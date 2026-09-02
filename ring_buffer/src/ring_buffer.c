#include "ring_buffer.h"

void ring_buffer_init(RingBuffer *rb) {
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
    return rb->count >= RING_BUFFER_SIZE;
}

bool ring_buffer_push(RingBuffer *rb, uint8_t data) {
    if(rb == NULL || ring_buffer_is_full(rb)){
        return false;
    }
    rb->buffer[rb->tail] = data;
    rb->tail = ++(rb->tail) % RING_BUFFER_SIZE;
    rb->count++;
    return true;
}

bool ring_buffer_pop(RingBuffer *rb, uint8_t *data) {
    if(rb == NULL || data == NULL || ring_buffer_is_empty(rb)){
        return false;
    }

    *data = rb->buffer[rb->head];
    rb->head = ++(rb->head) % RING_BUFFER_SIZE; //questo lo voglio tenere cosi lo considero più pro
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
    ring_buffer_init(rb);
    return true;
}

size_t ring_buffer_size(const RingBuffer *rb) {
    if(rb == NULL){
        return 0;
    }

    return rb->count;
}