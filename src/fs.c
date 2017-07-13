#include "fs.h"

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct fs {
        const char *env_var;
        bool found;
        char path[PATH_MAX + 1];
};

struct fs procfs = {
        .env_var = "PROC_PATH",
        .path = "/proc",
}, sysfs = {
        .env_var = "SYSFS_PATH",
        .path = "/sys",
};

static const char *fs_mountpoint(struct fs *fs) {
        char *override_path;
        if (fs->found)
                return fs->path;

        override_path = getenv(fs->env_var);
        if (override_path) {
                strncpy(fs->path, override_path, sizeof(fs->path));
        }

        fs->found = true;
        return fs->path;
}

const char *procfs_mountpoint(void) {
        return fs_mountpoint(&procfs);
}

const char *sysfs_mountpoint(void) {
        return fs_mountpoint(&sysfs);
}
