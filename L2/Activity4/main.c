#include <stdio.h>
#include <math.h>

void give_directions(void);

double find_fc(double res, double cap);

double find_xc(double freq, double cap);

double find_dB(double gain);

int main(void) {

    double r, c, xc, gain, dB, steps;
    double f, fstart, fstop, ffactor;
    double fc;

    give_directions();

    printf("Enter the resistance in Ohms:");
    scanf("%1lf", &r);
    printf("Enter the capacitance in Farad:");
    scanf("%1lf", &c);

    fc = find_fc(r, c);

    printf("\nThe critical frequency is %1f Hertz.\n\n", fc);

    printf("Enter the start frequency in Hertz:");
    scanf("%1lf", &fstart);

    printf("Enter the stop frequency in Hertz:");
    scanf("%1lf", &fstop);

    printf("Enter the number of steps per decade to display:");
    scanf("%1lf", &steps);

    printf("Frequency (Hz)\t\t\tGain (dB)\n"); //\t is tab

    ffactor = pow(10.0, 1.0 / steps);

    f = fstart;
    while (f <= fstop) {

        xc = find_xc(f, c);
        /*
         * Can use pow() for square here, but multiply itself will execute
         * the program faster
         */
        gain = xc / sqrt((r * r) + (xc * xc));

        dB = find_dB(gain);
        printf("%10.1lf\t\t%10.1lf\n", f, dB);
        /*
         * %10.1lf is 10 spaces with 1 digit after decimal
         */

        f *= ffactor; /* shortcut for f=f*ffactor; */

    }

}

void give_directions(void) {
    printf("Bode Table Generator\n\n");
    printf("This program will display dB gains for a simple R-C circuit\n");
}

double find_fc(double res, double cap) {
    return (1.0 / (2.0 * M_PI * res * cap));
}

double find_xc(double freq, double cap) {
    return (1.0 / (2.0 * M_PI * freq * cap));
}

double find_dB(double gain) {
    return (20.0 * log10(gain));
}
