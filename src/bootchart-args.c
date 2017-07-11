#include "bootchart-args.h"

/* graph defaults */
bool arg_entropy = false;
bool arg_initcall = true;
bool arg_relative = false;
bool arg_filter = true;
bool arg_show_cmdline = false;
bool arg_show_cgroup = false;
bool arg_pss = false;
bool arg_percpu = false;
int arg_samples_len = DEFAULT_SAMPLES_LEN; /* we record len+1 (1 start sample) */
double arg_hz = DEFAULT_HZ;
double arg_scale_x = DEFAULT_SCALE_X;
double arg_scale_y = DEFAULT_SCALE_Y;

char arg_init_path[PATH_MAX] = DEFAULT_INIT;
char arg_output_path[PATH_MAX] = DEFAULT_OUTPUT;
