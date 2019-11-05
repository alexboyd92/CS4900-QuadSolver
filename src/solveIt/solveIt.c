#include "solveIt.h"
#define  NO_ROOTS 2
#define TWO_ROOTS 1
#define ONE_ROOT  0
int solve( double *a, double *b, double *c, int logging, FILE * logFile){

	int returnValue = -1; // return value for solve -1 on error
	int roundMsg = 0; //control for output message
	double a2 = *a, b2 = *b, c2=*c;
	double rootVal = pow(b2, 2)-(4.0*a2*c2);

	if(logging==1) {
		fprintf(logFile, "value of that is in the "
		        "sqrt %f \n ",rootVal);
	}
	//if statement to check if SQRT(Negitive or Nan or +-infinite)
	if((rootVal<0 || fpclassify(rootVal) == FP_NAN || fpclassify(rootVal) == FP_INFINITE) && a2!= 0) {
		returnValue = NO_ROOTS;
	}
	//end if
	//if statement to check if SQRT(is 0)
	else if(rootVal==0) {
		*a = -b2/(2.0 * a2);
		float f = (float)*a;
		// printf("%f\n", rootVal);
		// printf("%f\n", (-b2));
		// printf("%f\n", (a2));
		// printf("%f\n", (-b2+rootVal)/(2.0*a2) );
		if (*a!=f) {
			if(logging==1) {
				fprintf(logFile, "root has a rounding error");
			}
			roundMsg = 1;
		}//end A!=F

		returnValue = ONE_ROOT;
	}  //end if
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


			roundMsg = 1; // set roundMSG

		}
		f = (float)*b;
		if (*b!=f) {
			if(logging==1) {
				fprintf(logFile, "- root has a rounding error");
			}

			roundMsg = 1; // set roundMSG
		}//end if b!=f
                                                      // end of else


		returnValue = TWO_ROOTS;
	}//end else

	if(roundMsg == 1){
		printf("Just a heads up!!\n With the numbers you put in there could be a rounding error with your output\n" );
	}
	                                                            // end of else
 	return returnValue;
} // end of solve function
