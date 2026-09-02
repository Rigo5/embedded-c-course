#include "device.h"

void device_init(Device *device)
{
    device->CTRL = 0;
    device->DATA = 0;
    device->state = DEVICE_OFF;   
}

void device_enable(Device *device)
{
    device->CTRL |= ENABLE_BIT;
    device->state = DEVICE_READY;
}

void device_disable(Device *device)
{
    device->CTRL &= ~ENABLE_BIT;
    device->state = DEVICE_OFF;
}
