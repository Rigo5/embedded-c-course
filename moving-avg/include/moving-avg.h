#ifndef MOVING_AVG_H
#define MOVING_AVG_H

#include <stdint.h>
#include <stdbool.h>
#include "ring_buffer.h"


typedef struct {
    RingBuffer *rb;
    uint32_t sum;
} MovingAvg;


bool moving_avg_init(MovingAvg *ma, RingBuffer *rb); // Returns true if initialization is successful, false otherwise.
bool moving_avg_add(MovingAvg *ma, uint8_t value); // Returns true if the value was successfully added, false otherwise.
bool moving_avg_get(const MovingAvg *ma, uint32_t *value); // Returns true if the average was successfully retrieved, false otherwise.

#endif // MOVING_AVG_H
