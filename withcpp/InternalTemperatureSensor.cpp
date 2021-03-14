#include "InternalTemperatureSensor.h"

InternalTemperatureSensor::InternalTemperatureSensor(): AnalogIn(4)
{
}

float InternalTemperatureSensor::read_temperature()
{
    return 27 - (read_volt()- 0.706) / 0.001721;
}