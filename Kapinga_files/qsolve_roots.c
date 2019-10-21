// FILE: qsolve_roots.c 
// LICENSE: GPL 2.0 JKK Consulting 2019
// VERSION: 0.50
// 
// int qsolve_roots(double a, double b, double c, double *x1, double *x2) 
// solves the quadratic equation
//   ax^2 + bx + c = 0
// for real roots x1 anf]d x2 c\x2
// It is written to address best precision results
//   
// Input:
//	double a, b, c; // Assumed to be in the IEEE-fp32 normal range
//                      // and a != 0A
// Output 
//	double *x1, *x2;// pointers to doubles where real roots are return
//			// x1 <= x2
// Return
//	0 		// real roots returned, IEEE-fp32 normal range 
//			// no roundoff problems detected
//	1  		// real roots returned, IEEE-fp32 normal range 
//			// possible loss of precision
//	2  		// real roots returned, not IEEE-fp32 normal range 
//			// possible loss of precision
//	3  		// no roots returned, overflow or internal error
//	4  		// a == 0
//	5  		// disc = b^2 -4ac < 0, no real roots
	
#include <stdio.h>
#include <math.h>
#include "qsolve_roots.h"

// quadratic equation solver for
//    ax^2 + bx + x = 0
// returns roots x1 and x2
// does not check for overflows and underflows.

int qsolve_roots(double a, double b, double c, double *x1, double *x2) {
double disc;  // discriminant disc = b^2 = 4ac
double sqrtd; // sqrt of disc;
double temp;  // used to swap *x1 and *x2

// Should do logging and argument validation here
// XXXX
// XXXX
// XXXX

if(a == 0.0) { // not a true quadratic
  return 4 ;
} 

disc = b*b - 4.0*a*c;
if(disc < 0.0) { // No real roots 
//  fprintf(stderr,"   disc = %24.19g\n", disc);
  return 5;
}
if(disc == 0) { // double root 
  // double root
  // should test return values
  *x1 = -b / (2.0*a);
  *x2 = *x1; 
} else {
  // two distinct roots 
  // should test return values
  sqrtd = sqrt(disc);
  *x1 = (-b + sqrtd)/(2.0*a);
  *x2 = (-b - sqrtd)/(2.0*a);
  if(*x1 >  *x2) {
    // swap *x1 and *x2
    temp = *x1;
    *x1 = *x2;
    *x2 = temp;
  }
}
return 0;
}
