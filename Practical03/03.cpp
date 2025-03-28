/* UPM library includes */
#include "grove.h" // for button->value()

/* MRAA library includes */
#include "mraa.h"

#include <stdio.h>

int main()
{
    // create a GPIO object from MRAA using it
    mraa_gpio_context d_pin = NULL;
    d_pin = mraa_gpio_init(13);

    // Create the button object using GPIO pin D4
    upm::GroveButton *button = new upm::GroveButton(3);

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

    // Run Code for 1 min
    for (int i = 60; i > 0; i--)
    {
        button_val = button->value();
        if (button_val)
        {
            printf("LED ON\n");
            mraa_gpio_write(d_pin, 1); // turn on LED
        }
        else
        {
            printf("LED OFF\n");
            mraa_gpio_write(d_pin, 0); // turn off LED
        }
        sleep(1);
    }

    return MRAA_SUCCESS;
}
