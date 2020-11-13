#include <stdio.h>
#include <stdlib.h>

double find_current( double voltage, double resistance ){
    return( voltage/resistance );
}

double find_power (double voltage, double current) {
    return (voltage * current);
}


int main(void)
{

    /*Listing 1*/
    printf("Hello world!\n");

    //break
    printf("\n\n");

    /*Listing 2 & 3*/
    int x, y;

    x = 10;
    y = x + 20;
    printf("The result is %d\n",y);

    //break
    printf("\n\n");

    /*Listing 4*/
    int a, b, c;
    printf("Enter the first value:");
    scanf("%d", &a);

    printf("Enter the second value:");
    scanf("%d", &b);

    c = a + b;
    printf("%d + %d = %d\n", a, b, c);

    //break
    printf("\n\n");

    /*Listing 5*/
    /*double v, tol;
    double rnom, rlow, rhigh;
    double inom, ilow, ihigh;
    double pnom, plow, phigh;

    printf("This program determines current and power.\n");

    printf("Please enter the voltage source in Volts. ");
    scanf("%lf", &v);
    printf("Please enter the nominal resistance in Ohms. ");
    scanf("%lf", &rnom);
    printf("Please enter the resistor tolerance in percent. ");
    scanf("%lf", &tol);

    tol = (tol/100.0);
    rlow = rnom - (rnom*tol);
    rhigh = rnom + (rnom*tol);

    inom = (v/rnom);
    ihigh = (v/rlow);
    ilow = (v/rhigh);

    pnom = v * inom;
    plow = v * ilow;
    phigh = v * ihigh;

    printf("Resistance (Ohms)	Current (Amps)	Power (Watts)\n");
    printf("%lf	%lf	%lf\n", rnom, inom, pnom );
    printf("%lf	%lf	%lf\n", rhigh, ilow, plow );
    printf("%lf	%lf	%lf\n", rlow, ihigh, phigh );

    //break
    printf("\n\n");*/

    /*Listing 6: Include function*/
    double v, tol;
    double rnom, rlow, rhigh;
    double inom, ilow, ihigh;
    double pnom, plow, phigh;

    printf("This program determines current and power.\n");

    printf("Please enter the voltage source in Volts. "); scanf("%lf", &v);
    printf("Please enter the nominal resistance in Ohms. "); scanf("%lf", &rnom);
    printf("Please enter the resistor tolerance in percent. "); scanf("%lf", &tol);

    tol = (tol/100.0);
    rlow = rnom - (rnom*tol);
    rhigh = rnom + (rnom*tol);

    //function find_current
    inom = find_current( v, rnom );
    ihigh = find_current( v, rlow );
    ilow = find_current( v, rhigh );

    //function find_power
    pnom = find_power(v, inom);
    plow = find_power(v, ilow);
    phigh =find_power(v, ihigh);

    printf("Resistance (Ohms)	Current (Amps)	Power (Watts)\n");
    printf("%lf	%lf	%lf\n", rnom, inom, pnom );
    printf("%lf	%lf	%lf\n", rhigh, ilow, plow );
    printf("%lf	%lf	%lf\n", rlow, ihigh, phigh );

}
