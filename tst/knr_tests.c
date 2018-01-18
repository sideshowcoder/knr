#include <stdio.h>
#include "dbg.h"
#include "minunit.h"
#include "knr.h"

char* test_foo() {
  int foo = 7;
  mu_assert(foo == 7, "error, foo != 7");
  return NULL;
}

char* test_f_to_c() {
  float f = 32.0;

  return NULL;
}

char* all_tests() {
  mu_suite_start();
  mu_run_test(test_foo);
  return NULL;
}

RUN_TESTS(all_tests)
