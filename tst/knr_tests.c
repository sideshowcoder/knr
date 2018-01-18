#include <stdio.h>
#include "dbg.h"
#include "minunit.h"
#include "knr.h"

char* test_f_to_c() {
  mu_assert(0.0 == knr_f_to_c(32.0), "error, foo != 7");
  return NULL;
}

char* all_tests() {
  mu_suite_start();
  mu_run_test(test_f_to_c);
  return NULL;
}

RUN_TESTS(all_tests)
