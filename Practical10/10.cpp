/* UPM library includes */
#include "grove.h" // for button->value()

/* Standard IO includes */
#include <stdio.h> // for printf()

#include <unistd.h> //for sleep()

int main()
{
    // Instantiate a rotary sensor on analog pin A1
    upm::GroveRotary *knob = new upm::GroveRotary(1);
    // Read the input and print, waiting one second between readings for 1 min
    for (int i = 60; i >= 0; i++)
    {
        float abs_value = knob->abs_value(); // Absolute raw value
        float abs_deg = knob->abs_deg();     // Absolute degrees
        float abs_rad = knob->abs_rad();     // Absolute radians
        float rel_value = knob->rel_value(); // Relative raw value
        float rel_deg = knob->rel_deg();     // Relative degrees
        float rel_rad = knob->rel_rad();     // Relative radians
        printf("Absolute: %4d raw %5.2f deg = %3.2f rad Relative: %4d raw %5.2f deg %3.2f rad\n",
               (int16_t)abs_value, abs_deg, abs_rad, (int16_t)rel_value, rel_deg, rel_rad);
        sleep(1); // Sleep for 1s
    }
    // Delete the button object
    delete knob;
}
