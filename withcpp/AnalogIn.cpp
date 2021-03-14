#include "AnalogIn.h"

AnalogIn::AnalogIn(int channel)
{
    _channel = channel;

    int pin = get_gpio(channel);
    if (pin == -1)
    {
        adc_set_temp_sensor_enabled(true);
    }
    else
    {
        adc_gpio_init(pin);
    }
}

AnalogIn::~AnalogIn()
{
}

float AnalogIn::read_volt()
{
    return (3.3 / (1 << 12)) * read();
}

uint16_t AnalogIn::read()
{
    adc_select_input(_channel);
    return adc_read();
}

uint16_t AnalogIn::read_mv()
{
    return read_volt() * 1000;
}

int AnalogIn::get_gpio(int channel)
{
    if (channel == 4)
    {
        return -1;
    }

    return channel + 26;
}
