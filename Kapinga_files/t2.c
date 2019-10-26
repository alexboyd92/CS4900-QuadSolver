// FILE: t1.c
// LICENSE: GPL 2.0 JKK Consulting 2019
//
//  Unit tests for quad_roots() 
//  solves a * x^2 + b x + c = 0
//  for real roots  *x1 and *x2
#include <stdlib.h>
#include "cunit.h"
#include "qsolve_roots.h"

// The t2 tests use small double roots (near roots in t1.c)
// so that all floating  point conversions and operations 
// should not be exact, including the sqrt(). There
// should be no overflows, nans or significant round off 
// problems as to IEEE-fp32 resuilts.

int main() {
double	a, b, c;   // a, b and c for the quadratic equation
double  tx1, tx2;  // "true" Roots of equation
double  x1, x2;    // Roots of equation x1 and x1 from qsolve_roots()
int	ret;       // return value from qsolve_roots
double	rerr;      // relative error for f_eqrerr tests
char	mess[100]; // for message to cunit_print))
// check for loss of less than about 3 binary places
rerr = DBL_EPSILON*4;
//
snprintf(mess, 99, "t2 tests should all pass with rerr=%8.4g", rerr);
cunit_print(mess)
cunit_date("\n");

// the first few check for correct order x1 < x2 as well as correct values
tx1 = 1.1;
tx2 = 2.1;
a = 1.0;
b = -tx1 + -tx2;
c = tx1*tx2;
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eqrerr("x1",x1, tx1,rerr);
assertf_eqrerr("x2",x2, tx2,rerr);

tx1 = 1.1;
tx2 = 2.1;
a = -1.1;
b = a*(-tx1 + -tx2);
c = a*(tx1*tx2);
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eqrerr("x1",x1, tx1,rerr);
assertf_eqrerr("x2",x2, tx2,rerr);

tx1 = -2.1;
tx2 = 1.1;
a = 1.0;
b = -tx1 + -tx2;
c = tx1*tx2;
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eqrerr("x1",x1, tx1,rerr);
assertf_eqrerr("x2",x2, tx2,rerr);

tx1 = -2.1;
tx2 = 1.1;
a = -1.1;
b = a*(-tx1 + -tx2);
c = a*(tx1*tx2);
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eqrerr("x1",x1, tx1,rerr);
assertf_eqrerr("x2",x2, tx2,rerr);

tx1 = -2.1;
tx2 = -1.1;
a = 1.0;
b = -tx1 + -tx2;
c = tx1*tx2;
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eqrerr("x1",x1, tx1,rerr);
assertf_eqrerr("x2",x2, tx2,rerr);

tx1 = -2.1;
tx2 = -1.1;
a = -1.1;
b = a*(-tx1 + -tx2);
c = a*(tx1*tx2);
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eqrerr("x1",x1, tx1,rerr);
assertf_eqrerr("x2",x2, tx2,rerr);

tx1 = -3.1;
tx2 = -3.1;
a = 1.0;
b = -tx1 + -tx2;
c = tx1*tx2;
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eqrerr("x1",x1, tx1,rerr);
assertf_eqrerr("x2",x2, tx2,rerr);

tx1 = -3.1;
tx2 = -3.1;
a = -13.1;
b = a*(-tx1 + -tx2);
c = a*(tx1*tx2);
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eqrerr("x1",x1, tx1,rerr);
assertf_eqrerr("x2",x2, tx2,rerr);

tx1 = 3.1;
tx2 = 3.1;
a = 1.0;
b = -tx1 + -tx2;
c = tx1*tx2;
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eqrerr("x1",x1, tx1,rerr);
assertf_eqrerr("x2",x2, tx2,rerr);

tx1 = 3.1;
tx2 = 3.1;
a = -17.1;
b = a*(-tx1 + -tx2);
c = a*(tx1*tx2);
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eqrerr("x1",x1, tx1,rerr);
assertf_eqrerr("x2",x2, tx2,rerr);

tx1 = 0.1;
tx2 = 5.1;
a = 1.0;
b = -tx1 + -tx2;
c = tx1*tx2;
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eqrerr("x1",x1, tx1,rerr);
assertf_eqrerr("x2",x2, tx2,rerr);

tx1 = 0.1;
tx2 = 5.1;
a = 19.1;
b = a*(-tx1 + -tx2);
c = a*(tx1*tx2);
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eqrerr("x1",x1, tx1,rerr);
assertf_eqrerr("x2",x2, tx2,rerr);

tx1 = 0.1;
tx2 = 5.1;
a = -19.1;
b = a*(-tx1 + -tx2);
c = a*(tx1*tx2);
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eqrerr("x1",x1, tx1,rerr);
assertf_eqrerr("x2",x2, tx2,rerr);

tx1 = -5.1;
tx2 = 0.1;
a = 1.0;
b = -tx1 + -tx2;
c = tx1*tx2;
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eqrerr("x1",x1, tx1,rerr);
assertf_eqrerr("x2",x2, tx2,rerr);

tx1 = 0.1;
tx2 = 5.1;
a = 23.1;
b = a*(-tx1 + -tx2);
c = a*(tx1*tx2);
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eqrerr("x1",x1, tx1,rerr);
assertf_eqrerr("x2",x2, tx2,rerr);

tx1 = 0.1;
tx2 = 5.1;
a = -23.1;
b = a*(-tx1 + -tx2);
c = a*(tx1*tx2);
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eqrerr("x1",x1, tx1,rerr);
assertf_eqrerr("x2",x2, tx2,rerr);

tx1 = 0.1;
tx2 = 0.1;
a = 1.0;
b = a*(-tx1 + -tx2);
c = a*(tx1*tx2);
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eqrerr("x1",x1, tx1,rerr);
assertf_eqrerr("x2",x2, tx2,rerr);

tx1 = 0.1;
tx2 = 0.1;
a = 1.0;
b = a*(-tx1 + -tx2);
c = a*(tx1*tx2);
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eqrerr("x1",x1, tx1,rerr);
assertf_eqrerr("x2",x2, tx2,rerr);

tx1 = 0.1;
tx2 = 0.1;
a = -11.1;
b = a*(-tx1 + -tx2);
c = a*(tx1*tx2);
ret = qsolve_roots(a, b, c, &x1, &x2);
assertd_eq("ret",ret,0);
assertf_eqrerr("x1",x1, tx1,rerr);
assertf_eqrerr("x2",x2, tx2,rerr);

exit(0);
}
