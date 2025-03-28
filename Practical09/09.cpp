/* UPM library includes */
#include "jhd1313m1.h"

/* Standard IO includes */
#include <stdio.h> // for printf()

#include <unistd.h> //for sleep()

int main(void)
{
    // 0x62 RGB_ADDRESS, 0x3E LCD_ADDRESS
    upm::Jhd1313m1 *lcd;
    lcd = new upm::Jhd1313m1(0, 0x3E, 0x62); // Create lcd instance
    // arguments: I2C addresses of LCD controller and LED backlight controller

    printf("Display text on LCD\n");

    lcd->setCursor(0, 0);                                        // bring cursor to top left corner
    lcd->write("CSE 2026!!!! ");                                 // print text
    lcd->setCursor(1, 2);                                        // bring cursor to second row
    lcd->write(" This Practical is performed by CSE 2026... !"); // print text

    printf("Sleeping for 5 seconds\n");
    sleep(5);
    printf("Starting Color loop...\n");

    // Run loop for toggling backlight color between Red->Green->Blue x 5 times
    for (int i = 10; i > 0; i--)
    {
        lcd->setColor(255, 0, 0); // set backlight color to Red
        sleep(1);
        lcd->setColor(0, 255, 0); // set backlight color to Green
        sleep(1);
        lcd->setColor(0, 0, 255); // set backlight color to Blue
        sleep(1);
    }

    printf("Exiting .. bbye!\n");

    delete lcd; // free up memory.
    return 0;
}
