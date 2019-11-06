// qsolve_roots.c 
// License GPL 2.0 JKK Consulting 2019
// version 1.01
// Needs testing. written to address best precision results
//    and IEEE fp input or results.
// 
// MY BAD. These comments should include 
//  What this does:
//       inputs
//       outputs
//       return value and errors
//       side effects?
//
#include <stdio.h>
#include <math.h>
#include "qsolve_roots.h"

// quadratic eqaution solver for
//    ax^2 + bx + x = 0
// returns roots x1 and x2
// does not check for overflows and underflows.

int qsolve_roots(double a, double b, double c, double *x1, double *x2) {
double disc;      // discriminate disc = b^2 = 4ac
double sqrtd; // sqrt of disc;

// Should do logging and argument validation here
// XXXX
// XXXX
// XXXX

if(a == 0.0) { // not a true quadratic
  return 1 ;
} 

disc = b*b - 4.0*a*c;
if(disc < 0.0) { // No real roots 
  return 2;
}
if(disc == 0) { // double root 
  // should test return values
  *x1 = -b / (2.0*a);
  *x2 = *x1; 
  return 0;
}
// two distinct roots 
// should test return values
sqrtd = sqrt(disc);
*x1 = (-b + sqrtd)/(2.0*a);
*x2 = (-b - sqrtd)/(2.0*a);

return 0;
}
