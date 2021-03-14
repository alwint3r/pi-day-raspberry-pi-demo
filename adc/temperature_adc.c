#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

#define TEMPERATURE_SENSOR_INPUT 4

int main()
{
    stdio_init_all();

    adc_init();

    adc_set_temp_sensor_enabled(true);
    adc_select_input(TEMPERATURE_SENSOR_INPUT);

    while (1)
    {
        uint16_t adc_result = adc_read();
        float voltage = (3.3f / (1 << 12)) * adc_result;

        float temperature = 27 - (voltage - 0.706) / 0.001721;

        printf("adc: %d\t voltage: %0.4f volt\t temp: %0.4f degC\r\n", (int)adc_result, voltage, temperature);

        sleep_ms(1000);
    }

    return 0;
}
