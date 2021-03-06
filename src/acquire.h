#pragma once

#include <complex.h>
#include <fftw3.h>

#define ACQ_HISTORY 16

typedef struct
{
    struct input_t *input;
    float complex *buffer;
    float complex *sums;
    float complex *fftin;
    float complex *fftout;
    float *shape;
    fftwf_plan fft;

    float samperr;
    float slope;
    unsigned int idx;
    int ready;
    int history[ACQ_HISTORY];
    unsigned int history_size;
    float prev_angle;
} acquire_t;

void acquire_process(acquire_t *st);
unsigned int acquire_push(acquire_t *st, float complex *buf, unsigned int length);
void acquire_init(acquire_t *st, struct input_t *input);
