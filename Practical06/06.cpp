/* UPM library includes */
#include "ttp223.h" // for button->value()

/* Standard IO includes */
#include <stdio.h> // for printf()

#include <unistd.h> //for sleep()

void touchISR(void *);
int count = 5;

void touchISR(void *)
{
    count--;
    printf("\nHello World from ISR, will exit after %d touch events", count);
    fflush(stdout);
}

int main()
{
    // Create the button object using GPIO pin 4
    upm::TTP223 *touch = new upm::TTP223(4);
    // Read the input and print, waiting one second between readings

    touch->installISR(mraa::EDGE_FALLING, &touchISR, NULL);

    printf("\nWelcome, waiting for touch event.\nWill exit after 5 events");
    fflush(stdout);

    while (count > 0)
        ;

    printf("\nExiting .. Bbye!");

    delete touch; // Delete the button object
}
