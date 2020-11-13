#include <stdio.h>
#include <stdio.h>
#include <math.h>
#define VOLTAGE_DIVIDER	1
#define EMITTER	2
#define COLLECTOR_FEEDBACK	3
#define VBE .7

void give_directions( void );
int get_choice( void );
/* and so forth */

int main(void)
{
    void give_directions( void )
    {
        printf("DC Bias Q Point calculator\n\n");
        printf("These are your bias choices:\n");
        printf("1. Voltage Divider\n");
        printf("2. Two Supply Emitter\n");
        printf("3. Collector Feedback\n");
        printf("\n");
    }

    int get_choice( void )
    {
        int ch;

        printf("Enter your choice number: ");
        scanf("%d", &ch);
        printf("\n");
        return( ch );
    }

    //function VOLTAGE DIVIDER
    void voltage_divider( void )
    {
        double vcc, vth, r1, r2, rth, re, rc, beta, ic, icsat, vce;

        printf("Enter collector supply in Volts: ");
        scanf("%lf", &vcc);
        printf("Enter current gain (beta or hfe): ");
        scanf("%lf", &beta);
        printf("Please enter all resistors in Ohms\n");
        printf("Enter upper divider resistor: ");
        scanf("%lf", &r1);
        printf("Enter lower divider resistor: ");
        scanf("%lf", &r2);
        printf("Enter collector resistor: ");
        scanf("%lf", &rc);
        printf("Enter emitter resistor: ");
        scanf("%lf", &re);

        vth = vcc*r2/(r1+r2);
        rth = r1*r2/(r1+r2);
        ic = (vth-VBE)/(re+rth/beta);
        icsat = vcc/(rc+re);

        if( ic >= icsat )
        {
            printf("Circuit is in saturation!\n");
            printf("Ic = %lf amps and Vce = 0 volts\n", icsat );

        }
        else
        {
            vce = vcc-ic*(re+rc);
            printf("Ic = %lf amps and Vce = %lf volts\n", ic, vce );
        }
    }

    //function COLLECTOR FEEDBACK
    void collector_feedback(void)
    {
        double ic, vcc, re, rc, rb, beta, vce, icsat;

        printf("Enter collector supply in Volts: ");
        scanf("%lf", &vcc);
        printf("Enter current gain (beta or hfe): ");
        scanf("%lf", &beta);
        printf("Enter collector resistor: ");
        scanf("%lf", &rc);
        printf("Enter emitter resistor: ");
        scanf("%lf", &re);
        printf("Enter base resistor: ");
        scanf("%lf", &rb);

        ic = (vcc-VBE)/(re+rc+rb/beta);
        icsat = vcc/(rc+re);

        if( ic >= icsat )
        {
            printf("Circuit is in saturation!\n");
            printf("Ic = %lf amps and Vce = 0 volts\n", icsat );

        }
        else
        {
            vce = vcc-ic*(re+rc);
            printf("Ic = %lf amps and Vce = %lf volts\n", ic, vce );
        }
    }

    //function EMITTER
    void emitter(void)
    {
        double vee, rb, re, beta, vce, vcc, ic, rc, icsat;

        printf("Enter collector supply in Volts: ");
        scanf("%lf", &vcc);
        printf("Enter current gain (beta or hfe): ");
        scanf("%lf", &beta);
        printf("Enter collector resistor: ");
        scanf("%lf", &rc);
        printf("Enter emitter resistor: ");
        scanf("%lf", &re);
        printf("Enter base resistor: ");
        scanf("%lf", &rb);
        printf("Enter negative emitter supply: ");
        scanf("%lf", &vee, fabs(vee));

        ic = (vee-VBE)/(re+rb/beta);
        icsat = (vee+vcc)/(rc+re);

        if( ic >= icsat )
        {
            printf("Circuit is in saturation!\n");
            printf("Ic = %lf amps and Vce = 0 volts\n", icsat );

        }
        else
        {
            vce = vee+vcc-ic*(re+rc);
            printf("Ic = %lf amps and Vce = %lf volts\n", ic, vce );
        }
    }


    int choice;

    //funtion for user choose
    give_directions();
    choice = get_choice();

    switch( choice )
    {
    case VOLTAGE_DIVIDER:
        voltage_divider();
        break;

    case EMITTER:
        emitter();
        break;

    case COLLECTOR_FEEDBACK:
        collector_feedback();
        break;

    default:	/* tell user they’re not so bright... */
        printf("No such choice!\n");
        break;
    }
}
