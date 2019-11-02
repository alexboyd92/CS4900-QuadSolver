//#include "../testing/cunit.h"
#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[]) {

        double solveVal1, solveVal2;
        double a2 = 1.555, b2 = 100.365, c2=6589;
        double rootVal = b2*b2 - (4.0*a2*c2);


        solveVal1 = -b2/(2.0 * a2);
        solveVal1 = 11111111.11111111;

        double d = solveVal1;
        float f = (float)solveVal1;

        printf("The floating-point number d %f\n", d);
        printf("Stored in a variable f\n of type float as the value %f\n", f);

}
