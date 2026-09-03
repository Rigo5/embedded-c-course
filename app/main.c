#include <stdio.h>
#include "buffer.h"
#include "device.h"
#include "ring_buffer.h"
#include "moving-avg.h"

#define MOVING_AVG_SIZE 32

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
    MovingAvg ma;
    RingBuffer rb2;
    uint8_t buffer[MOVING_AVG_SIZE];

    ring_buffer_init(&rb2, buffer, MOVING_AVG_SIZE);
    moving_avg_init(&ma, &rb2);
    moving_avg_add(&ma, 10);
    moving_avg_add(&ma, 20);
    moving_avg_add(&ma, 30);

    uint32_t avg;
    if (moving_avg_get(&ma, &avg))
    {
        printf("moving average = %u\n", avg);
    }
    return 0;
}