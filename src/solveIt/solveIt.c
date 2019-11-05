#include "solveIt.h"
#define  NO_ROOTS 2
#define TWO_ROOTS 1
#define ONE_ROOT  0
int solve( double *a, double *b, double *c, int logging){
								//double *solveVal1,* solveVal2;
								double a2 = *a, b2 = *b, c2=*c;
								double rootVal = pow(b2, 2)-(4.0*a2*c2);
								if(logging==1) {
																fprintf(logFile, "value of that is in the "
																								"sqrt %f \n ",rootVal);
								}

								//solveVal1 = solveVal2 = malloc(sizeof(double)); // this needs to be freeded at some point
								//if statement to check if SQRT(Negitive or Nan or +-infinite)
								if((rootVal<0 || fpclassify(rootVal) == FP_NAN || fpclassify(rootVal) == FP_INFINITE) && a2!= 0) {
																//printf("root is complex\n");


																return NO_ROOTS;
								}         //end if
								          //if statement to check if SQRT(is 0)
								else if(rootVal==0) {
																*a = -b2/(2.0 * a2);
																float f = (float)*a;
																printf("%f\n", rootVal);
																printf("%f\n", (-b2));
																printf("%f\n", (a2));
																printf("%f\n", (-b2+rootVal)/(2.0*a2) );
																if (*a!=f) {
																								if(logging==1) {
																																fprintf(logFile, "root has a rounding error");
																								}

																								printf("Just a heads up!!\n With the numbers you put in there could be a rounding error with your output\n" );
																}
																//printf("roots are the same\n");
																//printf("Root of quadratic equation is:%.3f\n", solveVal1);

																return ONE_ROOT;
								}         //end if
								          // else statement to check if SQRT(is valid)
								else{
																rootVal = sqrt(rootVal);
																*a = ((-b2+rootVal)/(2.0*a2));
																*b = (-b2-rootVal)/(2.0*a2);
																float f = (float)*a;
																printf("%f\n", *a );
																printf("%f\n", *b );
																if (*a!=f) {
																								if(logging==1) {
																																fprintf(logFile, "+ root has a rounding error");
																								}

																								printf("Just a heads up!!\n With the numbers you put in there could be a rounding error with your output\n" );
																}
																f = (float)*b;
																if (*b!=f) {
																								if(logging==1) {
																																fprintf(logFile, "- root has a rounding error");
																								}

																								printf("Just a heads up!!\n With the numbers you put in there could be a rounding error with your output\n" );
																}
																//printf("Roots of quadratic equation are:%.3f , %.3f", solveVal1, solveVal2);
																return TWO_ROOTS;
								}        // end of else


} // end of solve function
