#include "ring_buffer.h"

void ring_buffer_init(RingBuffer *rb, uint8_t *buffer, uint32_t capacity) {
    if(rb == NULL || buffer == NULL || capacity == 0){
        return;
    }
    rb->buffer = buffer;
    rb->capacity = capacity;
    rb->head = 0;
    rb->tail = 0;
    rb->count = 0;
}

bool ring_buffer_is_empty(const RingBuffer *rb) {
    if(rb == NULL){
        return true;
    }

    return rb->count == 0;
}

bool ring_buffer_is_full(const RingBuffer *rb) {
    if(rb == NULL){
        return false;
    }
    return rb->count >= rb->capacity;
}

bool ring_buffer_push(RingBuffer *rb, uint8_t data) {
    if(rb == NULL || ring_buffer_is_full(rb)){
        return false;
    }
    rb->buffer[rb->tail] = data;
    rb->tail = ++(rb->tail) % rb->capacity;
    rb->count++;
    return true;
}

bool ring_buffer_pop(RingBuffer *rb, uint8_t *data) {
    if(rb == NULL || data == NULL || ring_buffer_is_empty(rb)){
        return false;
    }

    *data = rb->buffer[rb->head];
    rb->head = ++(rb->head) % rb->capacity; //questo lo voglio tenere cosi lo considero più pro
    rb->count--; 
    return true;
}

bool ring_buffer_peek(const RingBuffer *rb, uint8_t *data) {

    if(rb == NULL || data == NULL ||ring_buffer_is_empty(rb)){
        return false;
    }
    
    *data = rb->buffer[rb->head];
    return true;
}

bool ring_buffer_clear(RingBuffer *rb) {
    if(rb == NULL || ring_buffer_is_empty(rb)){
        return false;
    }
    ring_buffer_init(rb, rb->buffer, rb->capacity);
    return true;
}

bool ring_buffer_get(const RingBuffer *rb, uint32_t index, uint8_t *data) {
    if(rb == NULL || data == NULL || index >= rb->count){
        return false;
    }

    uint32_t actual_index = (rb->tail + index) % rb->capacity;
    *data = rb->buffer[actual_index];

    return true;
}


size_t ring_buffer_size(const RingBuffer *rb) {
    if(rb == NULL){
        return 0;
    }

    return rb->count;
}