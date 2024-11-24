#include <stdio.h>
#include <math.h>
//Parameters
#define PI 3.14159
#define AMPLITUDE 1.0
#define FREQUENCY 1.0
#define SAMPLE_RATE 100
#define DURATION 1.0

int main() {
    double time, wave;
    int i;
    FILE *fp = fopen("Sinewave.dat", "w");//Creates a file named sine_wave, in the format of'.dat'
/*the below code is
For SAMPLE_RATE = 100, DURATION = 1, AMPLITUDE = 1, and FREQUENCY = 1:
0.000000 0.000000
0.010000 0.006283
0.020000 0.012566
...
1.000000 0.000000*/
    for (i = 0; i < SAMPLE_RATE * DURATION; i++) {
        time = (double)i / SAMPLE_RATE;
        wave = AMPLITUDE * sin(2 * PI * FREQUENCY * time);//in the form of[Asin(2*pi*x)]
        fprintf(fp, "%f %f\n", time, wave);//Writes the values into a file
    }
    fclose(fp);//fclose() function is used to close an open file stream
    return 0;
}


