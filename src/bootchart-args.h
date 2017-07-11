#pragma once
#include <limits.h>
#include <stdbool.h>

#define DEFAULT_SAMPLES_LEN 500
#define DEFAULT_HZ 25.0
#define DEFAULT_SCALE_X 100.0 /* 100px = 1sec */
#define DEFAULT_SCALE_Y 20.0  /* 16px = 1 process bar */
#define DEFAULT_INIT ROOTLIBEXECDIR "/systemd"
#define DEFAULT_OUTPUT "/run/log"

extern bool arg_relative;
extern bool arg_filter;
extern bool arg_show_cmdline;
extern bool arg_show_cgroup;
extern bool arg_pss;
extern bool arg_entropy;
extern bool arg_percpu;
extern bool arg_initcall;
extern int  arg_samples_len;
extern double arg_hz;
extern double arg_scale_x;
extern double arg_scale_y;

extern char arg_output_path[PATH_MAX];
extern char arg_init_path[PATH_MAX];
