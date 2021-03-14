#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define ULTRASONIC_TRIGGER_PIN  26
#define ULTRASONIC_ECHO_PIN     27


bool measurement_started = false;

absolute_time_t pulse_end_time;

absolute_time_t pulse_start_time;

void gpio_callback(uint gpio, uint32_t events)
{
    if (events & GPIO_IRQ_EDGE_FALL)
    {
        // pulse ended right after measurement is started
        // store the timestamp
        if (measurement_started == true)
        {
            pulse_end_time = get_absolute_time();

            // signal the end of measurement
            measurement_started = false;
        }
    }
    else if (events & GPIO_IRQ_EDGE_RISE)
    {
        // pulse started!
        // store the timestamp
        pulse_start_time = get_absolute_time();
    }
}

int main()
{
    stdio_init_all();

    // initialize GPIO and IRQ
    gpio_init(ULTRASONIC_ECHO_PIN);
    gpio_set_dir(ULTRASONIC_ECHO_PIN, GPIO_IN);
    gpio_set_irq_enabled_with_callback(ULTRASONIC_ECHO_PIN, GPIO_IRQ_EDGE_RISE|GPIO_IRQ_EDGE_FALL, true, &gpio_callback);

    // initialize trigger pin
    gpio_init(ULTRASONIC_TRIGGER_PIN);
    gpio_set_dir(ULTRASONIC_TRIGGER_PIN, GPIO_OUT);

    while (1)
    {
        // send trigger pulse
        gpio_put(ULTRASONIC_TRIGGER_PIN, 0);
        busy_wait_us(4);
        gpio_put(ULTRASONIC_TRIGGER_PIN, 1);
        busy_wait_us(10);
        gpio_put(ULTRASONIC_TRIGGER_PIN, 0);

        printf("Sent signal. Waiting for echo.\r\n");

        measurement_started = true;

        // wait for signal
        while (measurement_started)
        {
            printf(".");
        }

        printf("\r\n");

        int64_t pulse_width = absolute_time_diff_us(pulse_start_time, pulse_end_time);

        // if pulse width > 30ms, ultrasonic sensor didn't find anything in its course
        if (pulse_width >= 30 * 1000)
        {
            printf("timeout!!\r\n");
        }
        else
        {
            printf("pulse width: %lld us\r\n", pulse_width);

            // calculate distance in centimeters
            int distance_cm = pulse_width / 58;

            printf("distance: %d cm\r\n", distance_cm);

        }

        sleep_ms(500);
    }

    return 0;
}
