#include <stdio.h>

#include "dbg.h"
#include "minunit.h"
#include "knr.h"

char* test_f_to_c() {
  mu_assert(0.0 == knr_f_to_c(32.0), "32.0f should be 0.0c");
  mu_assert(within_delta(4.4, knr_f_to_c(40.0), 0.1), "40f should be 4.4c");
  return NULL;
}

char* test_c_to_f() {
  mu_assert(0.0 == knr_c_to_f(0.0), "32.0f should be 0.0c");
  mu_assert(within_delta(4.4, knr_c_to_f(40.0), 0.1), "40f should be 4.4c");
  return NULL;
}

char* all_tests() {
  mu_suite_start();
  mu_run_test(test_f_to_c);
  return NULL;
}

RUN_TESTS(all_tests)
