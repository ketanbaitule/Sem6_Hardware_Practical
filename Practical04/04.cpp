/* UPM library includes */
#include <buzzer.hpp>

#include <stdio.h> // for printf()

#include <unistd.h> //for sleep()

int main()
{
    int chord[] = {DO, RE, MI, FA, SOL, LA, SI, DO, SI};
    // create Buzzer instance
    upm::Buzzer *sound = new upm::Buzzer(5);

    printf("Volume = %f\n", sound->getVolume());
    sound->setVolume(30.1);
    printf("Volume = %f\n", sound->getVolume());
    fflush(stdout);

    // play sound (DO, RE, MI, etc...), pausing for 0.1 seconds between notes
    printf("\nPlaying notes, pausing for 0.1 seconds between notes...\n");
    fflush(stdout);

    for (int chord_ind = 0; chord_ind < 13; chord_ind++)
    {
        // play each note for one second
        printf(" %d\n", sound->playSound(chord[chord_ind], 5000000));
        usleep(100000);
    }
    printf("Exiting, bbye!\n");

    delete sound;
}
