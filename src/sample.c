#include "sample.h"
#include "fd-util.h"

#include <stdlib.h>

void *ps_struct_free(struct ps_struct *ps_first) {
        struct ps_struct *ps;
        if (!ps_first)
                return NULL;

        ps_struct_close(ps_first);

        ps = ps_first->next_ps;
        while (ps->next_ps) {
                struct ps_struct *old;

                old = ps;
                old->sample = ps->first;
                ps = ps->next_ps;
                while (old->sample->next) {
                        struct ps_sched_struct *oldsample = old->sample;

                        old->sample = old->sample->next;
                        free(oldsample);
                }
                free(old->cgroup);
                free(old->sample);
                free(old);
        }

        free(ps->cgroup);
        free(ps->sample);
        free(ps);

        free(ps_first);
        return NULL;
}

void *sampledata_free(struct list_sample_data *sampledata) {
        if (!sampledata)
                return NULL;

        while (sampledata->link_prev) {
                struct list_sample_data *old_sampledata = sampledata;
                sampledata = sampledata->link_prev;
                free(old_sampledata);
        }
        free(sampledata);
        return NULL;
}

void ps_struct_close(struct ps_struct *ps_first) {
        struct ps_struct *ps = ps_first;
        while (ps->next_running) {
                ps = ps->next_running;
                ps->schedstat = safe_close(ps->schedstat);
                ps->sched = safe_close(ps->sched);
                ps->smaps = safe_fclose(ps->smaps);
        }
}
