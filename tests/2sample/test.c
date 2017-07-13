#include "../../src/fd-util.h"
#include "../../src/log.h"
#include "../../src/sample.h"
#include "../../src/store.h"

int main(void) {
    _cleanup_closedir_ DIR *p1 = NULL;
    _cleanup_closedir_ DIR *p2 = NULL;
    int n_cpus = 0;
    int pscount = 0;
    int samples = 0;
    struct ps_struct *ps_first;
    struct list_sample_data *sampledata;
    int r;

    p1 = opendir("tests/gh-31/p1");
    if (!p1) {
        log_error_errno(errno, "could not open p1");
        return EXIT_FAILURE;
    }

    p2 = opendir("tests/gh-31/p2");
    if (!p2) {
        log_error_errno(errno, "could not open p2");
        return EXIT_FAILURE;
    }

    ps_first = new0(struct ps_struct, 1);
    if (!ps_first) {
        log_oom();
        return EXIT_FAILURE;
    }

    sampledata = new0(struct list_sample_data, 1);
    if (sampledata == NULL) {
        log_oom();
        return EXIT_FAILURE;
    }

    sampledata->sampletime = 0;
    sampledata->counter = samples;

    r = log_sample(p1, samples, ps_first, &sampledata, &pscount, &n_cpus);
    if (r < 0) {
        log_error("log_sample p1 failed");
        return EXIT_FAILURE;
    }

    samples++;

    r = log_sample(p1, samples, ps_first, &sampledata, &pscount, &n_cpus);
    if (r < 0) {
        log_error("log_sample p2 failed");
        return EXIT_FAILURE;
    }

    sampledata_free(sampledata);
    ps_struct_free(ps_first);

    puts("Ok");
    return 0;
}
