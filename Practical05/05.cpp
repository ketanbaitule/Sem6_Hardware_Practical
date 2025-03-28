#include "mraa/aio.h" //for mraa_aio_read()

#include <math.h> // for math functions

#include <stdio.h> // for printf()

#include <unistd.h> //for sleep()

int main()
{
    mraa_aio_context adc_a0;
    uint16_t adc_value = 0;

    const int B = 4275;    // B value of the thermistor
    const int R0 = 100000; // R0 = 100k

    // create object of analog input A0 class using mraa lib
    adc_a0 = mraa_aio_init(0);

    if (adc_a0 == NULL)
    {
        return 1;
    }
    for (int i = 5; i > 0; i--)
    {
        adc_value = mraa_aio_read(adc_a0); // Max value @ 5V = 1024
        printf("ADC A0 read value : %d\n", adc_value);

        float R = 1023.0 / ((float)adc_value) - 1.0;
        R = 100000.0 * R;
        float temperature = 1.0 / (log(R / 100000.0) / B + 1 / 298.15) - 273.15; // convert to temperature as per datasheet ;

        printf("Temperature value : %.2f Degree Celsius\n", temperature);

        sleep(1);
    }
    mraa_aio_close(adc_a0);
    printf("Exiting .. Bbye!");
    return MRAA_SUCCESS;
}
