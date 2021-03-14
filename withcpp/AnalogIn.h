#ifndef PICO_ANALOGIN_H
#define PICO_ANALOGIN_H

#include <stdint.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

class AnalogIn
{
public:
    AnalogIn(int channel);
    ~AnalogIn();

    uint16_t read();
    uint16_t read_mv();
    float read_volt();

    operator float()
    {
        return read_volt();
    }

    operator uint16_t()
    {
        return read_mv();
    }

private:
    int get_gpio(int channel);

private:
    int _channel;
};

#endif