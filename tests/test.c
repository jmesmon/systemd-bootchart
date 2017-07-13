#include "test.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>

static unsigned test_failures = 0;
static unsigned test_ct = 0;

void test_print(bool cond, const char *fmt, ...) {
    va_list va;
    va_start(va, fmt);
    test_ct ++;
    if (!cond) {
        test_failures ++;
        printf("not ok %u - ", test_ct);
    } else {
        printf("ok %u - ", test_ct);
    }
    vprintf(fmt, va);
    putchar('\n');
    va_end(va);
}

int test_exit_status(void) {
    if (test_failures)
       fprintf(stderr, "# Failed %u/%u tests\n", test_failures, test_ct);
    return test_failures ? EXIT_FAILURE : EXIT_SUCCESS;
}

void test_plan(unsigned test_max) {
    printf("1..%u\n", test_max);
}
