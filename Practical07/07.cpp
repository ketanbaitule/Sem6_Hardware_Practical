/* UPM library includes */
#include "grove.h" //for light->name(), light->value()

/* Standard IO includes */
#include <stdio.h> // for printf()

#include <unistd.h> //for sleep()

int main()
{
    // Create the light sensor object using AIO pin 0
    upm::GroveLight *light = new upm::GroveLight(0);
    // Read the input and print both the raw value and a rough lux value,
    // waiting one second between readings
    for (int i = 5; i > 0; i--)
    {
        printf(" Light value is %f which is roughly %d lux \n", light->raw_value(), light->value());
        fflush(stdout);
        sleep(1);
    }
    // Delete the light sensor object
    printf("Exiting .. bbye!");
    delete light;
}
