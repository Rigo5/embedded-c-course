#ifndef FIR_FIILTER_H
#define FIR_FIILTER_H

#include <stdint.h>
#include <stddef.h>
#include "ring_buffer.h"

typedef struct {
    float *coefficients;
    RingBuffer *buffer;
    float sum;
} FIRFilter;

bool fir_filter_init(FIRFilter *filter, float *coefficients, RingBuffer *buffer);
bool fir_filter_add(FIRFilter *filter, float input);
float fir_filter_get_output(const FIRFilter *filter);



#endif // FIR_FIILTER_H