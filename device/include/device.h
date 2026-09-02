#ifndef DEVICE_H
#define DEVICE_H

#include <stdint.h>

#define BIT_MASK(x) (1U << (x))
#define ENABLE_BIT (BIT_MASK(4))


typedef enum
{
    DEVICE_OFF,
    DEVICE_READY,
    DEVICE_ERROR
}  DeviceState;

typedef struct
{
    volatile uint32_t CTRL;
    const volatile uint32_t STATUS;
    volatile uint32_t DATA;

    DeviceState state;

    uint8_t buffer[8];
    uint8_t write_index;

} Device;


void device_init(Device *device);
void device_enable(Device *device);
void device_disable(Device *device);

#endif // DEVICE_H