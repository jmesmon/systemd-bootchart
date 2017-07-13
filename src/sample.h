#pragma once

#include "bootchart.h"
#include "macro.h"
#include "attributes.h"

#define _cleanup_ps_struct_ _cleanup_(ps_struct_freep)
#define _cleanup_sampledata_ _cleanup_(sampledata_freep)

void *sampledata_free(struct list_sample_data *sampledata);
void *ps_struct_free(struct ps_struct *ps_first);
void ps_struct_close(struct ps_struct *ps_first);

DEFINE_TRIVIAL_CLEANUP_FUNC(struct ps_struct*,ps_struct_free);
DEFINE_TRIVIAL_CLEANUP_FUNC(struct list_sample_data*,sampledata_free);
