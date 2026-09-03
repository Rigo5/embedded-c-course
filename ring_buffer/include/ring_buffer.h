#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct {
    uint8_t *buffer;
    uint32_t head;
    uint32_t tail;
    uint32_t count;
    uint32_t capacity;
} RingBuffer;


void ring_buffer_init(RingBuffer *rb, uint8_t *buffer, uint32_t capacity);
bool ring_buffer_is_empty(const RingBuffer *rb);
bool ring_buffer_is_full(const RingBuffer *rb);
bool ring_buffer_push(RingBuffer *rb, uint8_t data);
bool ring_buffer_pop(RingBuffer *rb, uint8_t *data);
bool ring_buffer_peek(const RingBuffer *rb, uint8_t *data);
bool ring_buffer_clear(RingBuffer *rb);
size_t ring_buffer_size(const RingBuffer *rb);

#endif // RING_BUFFER_H