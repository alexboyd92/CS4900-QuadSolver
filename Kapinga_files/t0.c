/*
* t1.c
* License GPL 2.0 JKK Consulting 2019
*
* Unit tests for quad_roots() 
* solves a * x^2 + b x + c = 0
*   for the roots
* x1 and x2
*/
#include <stdlib.h>
#include "cunit.h"
#include "qsolve_roots.h"


int main() {
double	a, b, c;   // a, b and c for the quadratic eqaution
double  tx1, tx2;  // "true" eRoots of equation
double  x1, x2;    // Roots of equation x1 and x1 from qsolve_roots()
int	ret;       // return value from qsolve_roots

//  A bad unit test
a = 1.0;
b = 2.0;
c = 1.0;
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eq("x1",x1,-2.0);
assertf_eq("x2",x2,-2.0);

//  A Good unit test
a = 1.0;
b = 2.0;
c = 1.0;
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eq("x1",x1,-1.0);
assertf_eq("x2",x2,-1.0);

// A bad unit test, wrong order and == used used on floats
// (x - x1)*(x - x2) = 0
tx1 = 3.1;
tx2 = 3.3;
a = 1.0;
b = -tx1 + -tx2;
c = tx1*tx2;
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eq("x1",x1, tx1);
assertf_eq("x2",x2, tx2);

// A bad unit test, need to allow for round off!
// (x - x1)*(x - x2) = 0
tx1 = 3.1;
tx2 = 3.3;
a = 1.0;
b = -tx1 + -tx2;
c = tx1*tx2;
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eq("x1",x1, tx1);
assertf_eq("x2",x2, tx2);

// A "good" unit test, need to allow for round off!
// qsolve_roots() passes this one. ;-)
// This allows about one base 10 least significant digit of error
// (x - x1)*(x - x2) = 0
x1 = 3.1;
x2 = 3.3;
a = 1.0;
b = -x1 + -x2;
c = x1*x2;
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eqrerr("x1",x1, tx2, 100.0*DBL_EPSILON);
assertf_eqrerr("x2",x2, tx1, 100.0*DBL_EPSILON);
exit(0);
}
