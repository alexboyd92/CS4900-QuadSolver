// FILE: t1.c
// LICENSE: GPL 2.0 JKK Consulting 2019
//
//  Unit tests for quad_roots() 
//  solves a * x^2 + b x + c = 0
//  for real roots  *x1 and *x2
#include <stdlib.h>
#include "cunit.h"
#include "qsolve_roots.h"

// The t1 tests use small integer roots so that all floating
// point conversions and operations should be exact, including 
// the sqrt().

int main() {
double	a, b, c;   // a, b and c for the quadratic eqaution
double  tx1, tx2;  // "true" eRoots of equation
double  x1, x2;    // Roots of equation x1 and x1 from qsolve_roots()
int	ret;       // return value from qsolve_roots

//
cunit_print("t1 tests should all pass");
cunit_date("\n");

// the first few check for correct order x1 < x2 as well as correct values
tx1 = 1.0;
tx2 = 2.0;
a = 1.0;
b = -tx1 + -tx2;
c = tx1*tx2;
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eq("x1",x1, tx1);
assertf_eq("x2",x2, tx2);

tx1 = 1.0;
tx2 = 2.0;
a = -1.0;
b = a*(-tx1 + -tx2);
c = a*( tx1*tx2);
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eq("x1",x1, tx1);
assertf_eq("x2",x2, tx2);

tx1 = -2.0;
tx2 = 1.0;
a = 1.0;
b = -tx1 + -tx2;
c = tx1*tx2;
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eq("x1",x1, tx1);
assertf_eq("x2",x2, tx2);

tx1 = -2.0;
tx2 = 1.0;
a = -1.0;
b = a*(-tx1 + -tx2);
c = a*( tx1*tx2);
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eq("x1",x1, tx1);
assertf_eq("x2",x2, tx2);

tx1 = -2.0;
tx2 = -1.0;
a = 1.0;
b = -tx1 + -tx2;
c = tx1*tx2;
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eq("x1",x1, tx1);
assertf_eq("x2",x2, tx2);

tx1 = -2.0;
tx2 = -1.0;
a = -1.0;
b = a*(-tx1 + -tx2);
c = a*( tx1*tx2);
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eq("x1",x1, tx1);
assertf_eq("x2",x2, tx2);

tx1 = -3.0;
tx2 = -3.0;
a = 1.0;
b = -tx1 + -tx2;
c = tx1*tx2;
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eq("x1",x1, tx1);
assertf_eq("x2",x2, tx2);

tx1 = -3.0;
tx2 = -3.0;
a = -13.0;
b = a*(-tx1 + -tx2);
c = a*( tx1*tx2);
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eq("x1",x1, tx1);
assertf_eq("x2",x2, tx2);

tx1 = 3.0;
tx2 = 3.0;
a = 1.0;
b = -tx1 + -tx2;
c = tx1*tx2;
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eq("x1",x1, tx1);
assertf_eq("x2",x2, tx2);

tx1 = 3.0;
tx2 = 3.0;
a = -17.0;
b = a*(-tx1 + -tx2);
c = a*( tx1*tx2);
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eq("x1",x1, tx1);
assertf_eq("x2",x2, tx2);

tx1 = 0.0;
tx2 = 5.0;
a = 1.0;
b = -tx1 + -tx2;
c = tx1*tx2;
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eq("x1",x1, tx1);
assertf_eq("x2",x2, tx2);

tx1 = 0.0;
tx2 = 5.0;
a = 19.0;
b = a*(-tx1 + -tx2);
c = a*( tx1*tx2);
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eq("x1",x1, tx1);
assertf_eq("x2",x2, tx2);

tx1 = 0.0;
tx2 = 5.0;
a = -19.0;
b = a*(-tx1 + -tx2);
c = a*( tx1*tx2);
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eq("x1",x1, tx1);
assertf_eq("x2",x2, tx2);

tx1 = -5.0;
tx2 = 0.0;
a = 1.0;
b = -tx1 + -tx2;
c = tx1*tx2;
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eq("x1",x1, tx1);
assertf_eq("x2",x2, tx2);

tx1 = 0.0;
tx2 = 5.0;
a = 23.0;
b = a*(-tx1 + -tx2);
c = a*( tx1*tx2);
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eq("x1",x1, tx1);
assertf_eq("x2",x2, tx2);

tx1 = 0.0;
tx2 = 5.0;
a = -23.0;
b = a*(-tx1 + -tx2);
c = a*( tx1*tx2);
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eq("x1",x1, tx1);
assertf_eq("x2",x2, tx2);

tx1 = 0.0;
tx2 = 0.0;
a = 1.0;
b = -tx1 + -tx2;
c = tx1*tx2;
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eq("x1",x1, tx1);
assertf_eq("x2",x2, tx2);

tx1 = 0.0;
tx2 = 0.0;
a = 7.0;
b = -tx1 + -tx2;
c = tx1*tx2;
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eq("x1",x1, tx1);
assertf_eq("x2",x2, tx2);

tx1 = 0.0;
tx2 = 0.0;
a = -11.0;
b = -tx1 + -tx2;
c = tx1*tx2;
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eq("x1",x1, tx1);
assertf_eq("x2",x2, tx2);

exit(0);
}
