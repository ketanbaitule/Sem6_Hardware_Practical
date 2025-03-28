/* MRAA library includes */
#include "mraa.h"

#include <stdio.h>

int main()
{
    // create a GPIO object from MRAA using it
    mraa_gpio_context d_pin = NULL;
    d_pin = mraa_gpio_init(13);

    if (d_pin == NULL)
    { // error check
        fprintf(stderr, "MRAA couldn't initialize GPIO, exiting");
        return MRAA_ERROR_UNSPECIFIED;
    }

    // configure the GPIO pin as output
    if (mraa_gpio_dir(d_pin, MRAA_GPIO_OUT) != MRAA_SUCCESS)
    {
        fprintf(stderr, "Can't set digital pin as output, exiting");
        return MRAA_ERROR_UNSPECIFIED;
    };

    // loop to toggle on-board every second for 10 times
    for (int i = 10; i > 0; i--)
    {
        printf("LED OFF\n");
        mraa_gpio_write(d_pin, 0); // turn off LED
        sleep(2);                  // wait 1 second
        printf("LED ON\n");
        mraa_gpio_write(d_pin, 1); // turn on LED
        sleep(1);                  // wait 1 second
    }

    return MRAA_SUCCESS;
}
