#include <stdio.h>
#include "buffer.h"
#include "device.h"
#include "ring_buffer.h"

typedef int (*Operation)(int, int);

void perform_operation(Operation op, int a, int b)
{
    int result = op(a, b);
    printf("Result: %d\n", result);
}

int add(int a, int b)
{
    return a + b;
}

int multiply(int a, int b)
{
    return a * b;
}

int main(void)
{
    Buffer buffer;

    buffer_init(&buffer);

    buffer_push(&buffer, 10);
    buffer_push(&buffer, 20);
    buffer_push(&buffer, 30);

    uint8_t value;

    if (buffer_get(&buffer, 1, &value))
    {
        printf("value = %u\n", value);
    }

    printf("size = %ld\n", buffer_size(&buffer));
    if (buffer_is_full(&buffer))
    {
        printf("buffer is full\n");
    }

    if (buffer_pop(&buffer, &value))
    {
        printf("popped value = %u\n", value);
    }
    perform_operation(add, 5, 3);
    perform_operation(multiply, 5, 3);

    RingBuffer rb;

    ring_buffer_init(&rb);

    ring_buffer_push(&rb, 10);
    ring_buffer_push(&rb, 20);
    ring_buffer_push(&rb, 30);

    while (ring_buffer_pop(&rb, &value))
    {
        printf("%u\n", value);
    }

    ring_buffer_init(&rb);

    for (uint8_t i = 0; i < 8; i++)
    {
        ring_buffer_push(&rb, i);
    }

    for (int i = 0; i < 3; i++)
    {
        ring_buffer_pop(&rb, &value);
    }

    ring_buffer_push(&rb, 100);
    ring_buffer_push(&rb, 101);
    ring_buffer_push(&rb, 102);

    while (ring_buffer_pop(&rb, &value))
    {
        printf("%u ", value);
    }
    printf("\n");
    return 0;
}