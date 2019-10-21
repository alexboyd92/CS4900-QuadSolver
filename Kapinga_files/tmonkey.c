// FILE: t1.c
// LICENSE: GPL 2.0 JKK Consulting 2019
//
//  Unit tests for quad_roots() 
//  solves a * x^2 + b x + c = 0
//  for real roots  *x1 and *x2
#include <stdlib.h>
#include "cunit.h"
#include "qsolve_roots.h"

// The tmonkey tests use small double roots x1 and x2 as well as a
// in [-1.0, 1.0)  so that all floating  point conversions and operations 
// should likely not be exact, including the sqrt(). There
// should be no overflows, nans or significant round off 
// problems as to IEEE-fp32 resuilts.

int main() {
double	a, b, c;   // a, b and c for the quadratic equation
double  tx1, tx2;  // "true" Roots of equation
double  x1, x2;    // Roots of equation x1 and x1 from qsolve_roots()
int	ret;       // return value from qsolve_roots
double	rerr;      // relative error for f_eqrerr tests
long	seed;      // seed for the PRNG drand48()
int	nmonkey;   // numnber of monkey tests
int	n;         // counter for monkey tests
char    mess[100]; // message for cunit_print()
double	temp;      // for swapping tx1 and tx2 if needed

// check for loss of less than about 3 binary places
// Note this fails many tests
// rerr = DBL_EPSILON*4;
// Note this fails 66/10000 tests
// rerr = DBL_EPSILON*100;
// Note this fails 6/100000 tests
// rerr = DBL_EPSILON*1000;
// Note this failed 2 out of 100000 tests
rerr = DBL_EPSILON*10000;
// Set the seed for the prng
seed = 1;
// Set the nubner of monkey tests
nmonkey = 100000;

srand48(seed);

// Must edit this if nmonkey or rerr is changed
snprintf(mess, 99, "tmonkey tests should fail only about 2 of the 100000 with rerr=%8.4g", rerr); 
cunit_print(mess);
cunit_date("\n");

cunit_print("non integer values\n");
for(n=0; n<nmonkey; n++) {
  tx1 = 2.0*drand48() - 1.0;
  tx2 = 2.0*drand48() - 1.0;
  if(tx2<tx1) {
    temp = tx1;
    tx1 = tx2;
    tx2 = temp;
  }
  // a might be 0.0, low probability but
  a =  2.0*drand48() - 1.0;
  b = a*(-tx1 + -tx2);
  c = a*(tx1*tx2);
  ret = qsolve_roots(a, b, c, &x1, &x2);
  assertd_eq("ret",ret,0);
  assertf_eqrerr("x1 ",x1, tx1,rerr);
  assertf_eqrerr("x2 ",x2, tx2,rerr);
}
cunit_print("\ninteger values\n");
for(n=0; n<nmonkey; n++) {
  tx1 = round(200.0*drand48() - 100.0);
  tx2 = round(200.0*drand48() - 100.0);
  if(tx2<tx1) {
    temp = tx1;
    tx1 = tx2;
    tx2 = temp;
  }
  // -100.0 <= a < 100.0
  a = round(99.0*drand48() + 1.0);
  // be sire a != 0.0
  if(drand48() < 0.5) {
    a = -a;
  }
  b = a*(-tx1 + -tx2);
  c = a*(tx1*tx2);
  // printf("%g %g %g %g %g\n", a,b,c,tx1,tx2);
  ret = qsolve_roots(a, b, c, &x1, &x2);
  assertd_eq("ret",ret,0);
  assertf_eqrerr("x1 ",x1, tx1,rerr);
  assertf_eqrerr("x2 ",x2, tx2,rerr);
}
}

