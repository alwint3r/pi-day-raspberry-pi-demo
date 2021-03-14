#ifndef INTERNAL_TEMPERATURE_SENSOR_H
#define INTERNAL_TEMPERATURE_SENSOR_H

#include "AnalogIn.h"

class InternalTemperatureSensor : public AnalogIn
{
    
public:
    InternalTemperatureSensor();
    ~InternalTemperatureSensor();

    operator float()
    {
        return read_temperature();
    }

    float read_temperature();
};

#endif
