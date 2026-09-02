#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define RING_BUFFER_SIZE 8U

typedef struct {
    uint8_t buffer[RING_BUFFER_SIZE];
    uint8_t head;
    uint8_t tail;
    uint8_t count;
} RingBuffer;


void ring_buffer_init(RingBuffer *rb);
bool ring_buffer_is_empty(const RingBuffer *rb);
bool ring_buffer_is_full(const RingBuffer *rb);
bool ring_buffer_push(RingBuffer *rb, uint8_t data);
bool ring_buffer_pop(RingBuffer *rb, uint8_t *data);
bool ring_buffer_peek(const RingBuffer *rb, uint8_t *data);
bool ring_buffer_clear(RingBuffer *rb);
size_t ring_buffer_size(const RingBuffer *rb);

#endif // RING_BUFFER_H