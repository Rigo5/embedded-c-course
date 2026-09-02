#ifndef BUFFER_H
#define BUFFER_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define BUFFER_CAPACITY 8U

typedef struct {
    uint8_t data[BUFFER_CAPACITY];
    size_t index;
} Buffer;


void buffer_init(Buffer *buffer);
bool buffer_is_full(const Buffer *buffer);
bool buffer_is_empty(const Buffer *buffer);
bool buffer_push(Buffer *buffer, uint8_t value);
bool buffer_pop(Buffer *buffer, uint8_t *value);
bool buffer_get(const Buffer *buffer, size_t index, uint8_t *value);
bool buffer_clear(Buffer *buffer);
size_t buffer_size(const Buffer *buffer);


void printBuffer(const Buffer *buffer);



#endif // BUFFER_H