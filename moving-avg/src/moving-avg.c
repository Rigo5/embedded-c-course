#include "moving-avg.h"


bool moving_avg_init(MovingAvg *ma, RingBuffer *rb) {

    if(ma == NULL || rb == NULL) {
        return false;
    }

    ma->rb = rb;
    ma->sum = 0;

    return true;
}


bool moving_avg_add(MovingAvg *ma, uint8_t value) {
    if(ma == NULL){
        return false; 
    }
    
    if(ring_buffer_is_full(ma->rb)) {
        uint8_t old_value;
        if(!ring_buffer_pop(ma->rb, &old_value)) {
            return false;
        }
        ma->sum -= old_value;
    }

    if(!ring_buffer_push(ma->rb, value)){
        return false;
    }
    ma->sum += value;
    return true;
}
 

bool moving_avg_get(const MovingAvg *ma, float *value) {
    if(ma == NULL || value == NULL) {
        return false;
    }

    if(ring_buffer_is_empty(ma->rb)) {
        return false;
    }

    *value = (float)ma->sum / ring_buffer_size(ma->rb);
    return true;
}