#pragma once

#include "bootchart.h"

void sampledata_free(struct list_sample_data *sampledata);

void ps_struct_free(struct ps_struct *ps_first);
void ps_struct_close(struct ps_struct *ps_first);
