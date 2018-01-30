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
  char expected[] = "abcd\nabcd";
  char actual[10];

  char *test = "abcd abcd";
  FILE *in = fmemopen((void *)test, strlen(test), "r");
  FILE *out = fmemopen((void *)actual, sizeof(actual), "w");

  knr__fold_lines(in, out, 4);

  fclose(out);
  log_info("expected '%s' actual '%s'", expected, actual);
  mu_assert(strcmp(expected, actual), "expected 'abcd abcd' to be split after first 'abcd'");
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
