#include <stdio.h>
#include <stdlib.h>

/*Declare function*/
void assign_it( int *x, int *y, int *z );

int main(void)
{
    /*POINTER*/
    /*int c, *pc;
    c = 36;
    pc = &c;

    printf("The value of c = %d, the address of c = %d\n", c, &c );
    printf("The value of pc = %d, the value pc points to = %d\n", pc, *pc );

    /*break*/
    /*printf("\nExercise 1\n");
    int a, b;
    a = 26;
    b = &a; /*pointer a*/
    /*printf("Value of a is %d\n", a);
    printf("Address of value a (*a) is %d\n", b);
    printf("Value of b is %d\n", b);
    printf("Hence, value b is points to %d\n", a);*/


    /*HANDLE*/
    /*printf("\n\n");
    int c, *pc, **ppc;

    c = 12;
    pc = &c;
    ppc = &pc;

    printf("pc = %d, the value pc points to = %d\n", pc, *pc );
    printf("ppc = %d, the value ppc points to = %d\n", ppc, *ppc );

    /*break*/
    /*printf("\nExercise 2\n");
    int c, *pc, **ppc;

    c = 12;
    pc = &c;
    ppc = &pc;

    printf("pc = %d, the value pc points to = %d\n", pc, *pc );
    printf("ppc = %d, the value ppc points to = %d\n", ppc, *ppc );
    printf("Value of **ppc is %d\n", **ppc);*/

    /*ADDRESSES*/
    /*printf("\n\n");
    int a, b, c, *pc;

    pc = &c;

    assign_it( &a, &b, pc ); /*pc = &c*/

    /*printf("The values in main are: %d %d %d\n", a, b, c );
    printf("The values in main are: %d %d %d\n", &a, &b, pc );*/

    /*break*/
    /*printf("\nExercise 3\n");
    int num1, num2, num3, point3;

    point3 = &num3;

    assign_it(&num1, &num2, point3);
    printf("The values in main are: %d %d %d\n", num1, num2, num3);*/

    /*break*/
    printf("\nExercise 4\n");
    int a, b, c, *pc;

    pc = &c;

    assign_it( &a, &b, pc ); /*pc = &c*/

    printf("The values in main are: \n(value = address)\n");
    printf("%d = %d | %d = %d | %d = %d", a, &a, b, &b, c, pc);

    printf("\n\nsizeof()");
    int p = sizeof(a);

    printf("\nSize of a is %d\n", p);

}

void assign_it( int *x, int *y, int *z )
{
    *x = 1;
    *y = 20;
    *z = 300;
}
