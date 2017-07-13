#pragma once
#include <stdbool.h>
#include <string.h>

void test_plan(unsigned test_max);
void test_print(bool cond, const char *fmt, ...);
int test_exit_status(void);

#define test_ok(cond) test_print((cond), "%s", #cond)
#define test_streq(a, b) do { \
    const char *test_a__ = (a); \
    const char *test_b__ = (b); \
   test_print(!strcmp(test_a__, test_b__), "%s (%s) == (%s) %s", \
        #a, test_a__, test_b__, #b); \
} while(0)
