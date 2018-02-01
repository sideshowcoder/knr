#include <stdio.h>

#include "dbg.h"
#include "minunit.h"
#include "knr.h"

char* test_f_to_c() {
  mu_assert(within_delta(0.0, knr_f_to_c(32.0), 0.1), "32.0f should be 0.0c");
  mu_assert(within_delta(4.4, knr_f_to_c(40.0), 0.1), "40f should be 4.4c");
  return NULL;
}

char* test_c_to_f() {
  mu_assert(within_delta(32.0, knr_c_to_f(0.0), 0.1), "0.0c should be 32.0f");
  mu_assert(within_delta(40.0, knr_c_to_f(4.4), 0.1), "4.4c should be 40.0f");
  return NULL;
}

char* test_reverse() {
  char s1[] = "0123";
  char *s2 = knr_reverse("3210");
  mu_assert(strcmp(s1, s2) == 0, "expect 0123 to reverse to 3210");
  return NULL;
}

char* test_fold_lines() {
  const int ninputs = 4;

  /*
   * TODO cleanup the code
   * TODO columns are 0 indexed which is awkward
   * TODO indent lines split not at a space to mark continuation indent by one tab (?)
   */

  const char* expected[ninputs];
  expected[0] = "abcd\nabcd";
  expected[1] = "abc\nabcd";
  expected[2] = "ab\ncda";
  expected[3] = "abcda\nbcd";

  const char* inputs[ninputs];
  inputs[0] = "abcd abcd"; // break line at paragraph matching space
  inputs[1] = "abc\nabcd"; // given linebreak already present
  inputs[2] = "ab cda"; // given space before paragraph end
  inputs[3] = "abcdabcd"; // no space given break at column... no this is not smart

  char actual[256] = { 0 }; // buff with room results

  for(int i = 0; i < ninputs; i++) {
    memset(actual, 0, sizeof(actual)); // reset actual buffer
    FILE *in = fmemopen((void *)inputs[i], strlen(inputs[i]), "r");
    FILE *out = fmemopen((void *)actual, sizeof(actual), "w");

    knr__fold_lines(in, out, 4);
    fclose(out);

    log_info("expected '%s' actual '%s'", expected[i], actual);
    mu_assert(strcmp(expected[i], actual) == 0, "expected input to be split correctly");
  }

  return NULL;
}

char* all_tests() {
  mu_suite_start();
  mu_run_test(test_f_to_c);
  mu_run_test(test_c_to_f);
  mu_run_test(test_reverse);
  mu_run_test(test_fold_lines);
  return NULL;
}

RUN_TESTS(all_tests)
