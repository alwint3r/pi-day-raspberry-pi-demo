#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "AnalogIn.h"
#include "InternalTemperatureSensor.h"

int main()
{
    stdio_init_all();

    adc_init();

    AnalogIn ain(4);

    while (1)
    {
        float volt = ain;
        float temperature = 27 - (volt - 0.706) / 0.001721;

        printf("voltage: %0.4f volt\t temp: %0.4f degC\r\n", volt, temperature);

        sleep_ms(1000);
    }

    // InternalTemperatureSensor temp_sensor;
    // while (1)
    // {
    //     float temperature = temp_sensor;
    //     float volt = temp_sensor.read_volt();

    //     printf("voltage: %0.4f volt\t temp: %0.4f degC\r\n", volt, temperature);

    //     sleep_ms(1000);
    // }

    return 0;
}
