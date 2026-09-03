#include "moving-avg.h"


bool moving_avg_init(MovingAvg *ma) {

    if(ma == NULL) {
        return false;
    }

    RingBuffer rb;
    uint8_t buffer[MOVING_AVG_SIZE];
    ring_buffer_init(&rb, buffer, MOVING_AVG_SIZE);
    ma->rb = rb;
    ma->sum = 0;
    return true;
}


bool moving_avg_add(MovingAvg *ma, uint8_t value) {
    if(ma == NULL){
        return false; 
    }

    if(ring_buffer_is_full(&ma->rb)) {
        uint8_t old_value;
        ring_buffer_get(&ma->rb, &old_value);
        ma->sum -= old_value;
    }

    if(!ring_buffer_put(&ma->rb, value)) {
        return false;
    }

    ma->sum += value;
    return true;
}

bool moving_avg_get(const MovingAvg *ma, uint32_t *value) {
    if(ma == NULL || value == NULL) {
        return false;
    }

    if(ring_buffer_is_empty(&ma->rb)) {
        return false;
    }

    *value = ma->sum / ring_buffer_size(&ma->rb);
    return true;
}