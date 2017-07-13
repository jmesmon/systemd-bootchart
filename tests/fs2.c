#include "../src/fs.h"
#include "test.h"
#include <stdlib.h>

int main(void)
{
    const char *p = "/magic-proc-path/here";
    const char *s = "/sysfs-is-/somewhere-else";
    setenv("PROC_PATH", p, 1);
    setenv("SYSFS_PATH", s, 1);

    test_plan(2);
    test_streq(sysfs_mountpoint(), s);
    test_streq(procfs_mountpoint(), p);

    return test_exit_status();
}
