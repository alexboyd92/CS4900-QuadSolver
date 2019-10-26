// FILE: test_discriminant.c
// LICENSE: GPL 2.0 JKK Consulting 2019
//
//  Unit tests for quad_roots() 
//  solves a * x^2 + b x + c = 0
//  for real roots  *x1 and *x2
//
// Investigate a case where rounding produced discriminant < 0  in t2.c
// and such problems in general
#include <stdlib.h>
#include "cunit.h"
#include "qsolve_roots.h"

int main() {
double	a, b, c;   // a, b and c for the quadratic equation
double  tx1, tx2;  // "true" Roots of equation
double  x1=666.0, x2=667.0;    // Roots of equation x1 and x1 from qsolve_roots()
int	ret;       // return value from qsolve_roots
double	rerr;      // relative error for f_eqrerr tests
char	mess[100]; // for message to cunit_print))
double	disc;      // discriminant b^2 - 4ac
double	disc1;     // discriminant/b^2  = 1 - 4ac/(b*b)
double	qx1;      // -b/(2.0*a)  double root value...
// check for loss of less than about 3 binary places
rerr = DBL_EPSILON*4;
//
snprintf(mess, 99, "test_discriminant for development with rerr=%8.4g", rerr);
cunit_print(mess)
cunit_date("\n");


// bad discriminant < 0
tx1 = 3.1;
tx2 = 3.1;
a = -17.1;
b = a*(-tx1 + -tx2);
c = a*(tx1*tx2);
printf("Before tx1=%24.19g tx2=%24.19g\n        x1=%24.19g x2=%24.19g\n a=%24.19g b=%24.19g c=%24.19g\n", 
    tx1, tx2, x1, x2, a, b, c);
disc = b*b - 4.0*a*c;
printf("disc=%24.19g\n", disc);
// disc1 might be safer to check than disc as disc is not a relative error type
// could test disc1 > -DBL_EPSILON*n as == 0.0
disc1 = 1.0 - 4.0*a*c/(b*b);
printf("disc1=%24.19g\n", disc1);
qx1 = -b/(2.0*a);
printf("-b/(2.0*a)=%24.19g\n", qx1);

ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eqrerr("x1",x1, tx1,rerr);
assertf_eqrerr("x2",x2, tx2,rerr);

printf("After  tx1=%24.19g tx2=%24.19g\n        x1=%24.19g x2=%24.19g\n a=%24.19g b=%24.19g c=%24.19g\n", 
    tx1, tx2, x1, x2, a, b, c);
}
