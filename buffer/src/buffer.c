#include "buffer.h"


void buffer_init(Buffer *buffer){
    if (buffer == NULL) {
        return;
    }

    buffer->index = 0;
    for (size_t i = 0; i < BUFFER_CAPACITY; i++) {
        buffer->data[i] = 0;
    }
}

bool buffer_is_full(const Buffer *buffer)
{
    return buffer != NULL && buffer->index == BUFFER_CAPACITY;
}

bool buffer_is_empty(const Buffer *buffer)
{
    return buffer != NULL && buffer->index == 0;
}

bool buffer_push(Buffer *buffer, uint8_t value)
{
    if (buffer_is_full(buffer) || buffer == NULL) {
        return false;
    }
    buffer->data[buffer->index++] = value;
    return true;
}

bool buffer_pop(Buffer *buffer, uint8_t *value)
{
    if (buffer == NULL || buffer_is_empty(buffer) || value == NULL) {
        return false;
    }

    *value = buffer->data[--buffer->index];
    return true;
}

bool buffer_get(const Buffer *buffer, size_t index, uint8_t *value)
{
    if (buffer == NULL || index >= buffer->index || value == NULL) {
        return false;
    }

    *value = buffer->data[index];
    return true;
}

bool buffer_clear(Buffer *buffer)
{
    if (buffer == NULL) {
        return false;
    }
    
    buffer_init(buffer);
    return true;
}

size_t buffer_size(const Buffer *buffer)
{
    if (buffer == NULL) {
        return 0;
    }
    return buffer->index;
}