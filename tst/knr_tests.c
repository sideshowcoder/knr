#include <stdio.h>
#include "dbg.h"
#include "minunit.h"

char* test_foo() {
  int foo = 7;
  mu_assert(foo == 7, "error, foo != 7");
  return 0;
}

char* test_bar() {
  int bar = 5;
  mu_assert(bar == 5, "error, bar != 5");
  return 0;
}

char* all_tests() {
  mu_suite_start();
  mu_run_test(test_foo);
  mu_run_test(test_bar);
  return 0;
}

RUN_TESTS(all_tests)
