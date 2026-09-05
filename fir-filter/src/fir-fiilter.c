#include "fir-fiilter.h"

static float multiply_accumulate(const float *coefficients, const RingBuffer *buffer){
    float sum = 0.0f;
    size_t size = ring_buffer_size(buffer);
    
    for(int i = (int)size - 1; i >= 0; i--){
        uint8_t value;
        ring_buffer_get(buffer, i, &value);
        sum += value * coefficients[i];
    }
    return sum;
}

bool fir_filter_init(FIRFilter *filter, float *coefficients, RingBuffer *buffer){
    if(filter == NULL || coefficients == NULL || buffer == NULL){
        return false;
    }

    filter->coefficients = coefficients;
    filter->buffer = buffer;
    filter->sum = 0.0f;
    return true;
}

bool fir_filter_add(FIRFilter *filter, uint8_t input){
    if(filter == NULL || filter->buffer == NULL || filter->coefficients == NULL){
        return false;
    }

    if(!ring_buffer_push(filter->buffer, input)){
        return false;
    }

    filter->sum = multiply_accumulate(filter->coefficients, filter->buffer);
    return true;
}

float fir_filter_get_output(const FIRFilter *filter){
    if(filter == NULL){
        return 0.0f;
    }
    return filter->sum;
}