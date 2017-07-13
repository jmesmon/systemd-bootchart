#include "../src/fs.h"
#include "test.h"
#include <stdlib.h>

int main(void)
{
    unsetenv("PROC_PATH");
    unsetenv("SYSFS_PATH");

    test_plan(2);
    test_streq(sysfs_mountpoint(), "/sys");
    test_streq(procfs_mountpoint(), "/proc");

    return test_exit_status();
}
