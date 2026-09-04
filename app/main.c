#include <stdio.h>
#include <stdint.h>

#include "ring_buffer.h"
#include "moving-avg.h"

#define WINDOW_SIZE 4U

int main(void)
{
    uint8_t storage[WINDOW_SIZE];

    RingBuffer rb;
    MovingAvg ma;

    ring_buffer_init(&rb, storage, WINDOW_SIZE);

    if (!moving_avg_init(&ma, &rb)) {
        printf("Errore init moving average\n");
        return 1;
    }

    uint8_t samples[] = {
        10, 10, 11, 10,
        50,
        11, 10, 10
    };

    size_t sample_count = sizeof(samples) / sizeof(samples[0]);

    printf("RAW\tFILTERED\n");

    for (size_t i = 0; i < sample_count; i++) {
        float avg;

        if (!moving_avg_add(&ma, samples[i])) {
            printf("Errore add sample\n");
            return 1;
        }

        if (!moving_avg_get(&ma, &avg)) {
            printf("Errore get average\n");
            return 1;
        }

        printf("%u\t%f\n", samples[i], avg);
    }
    
    return 0;
}