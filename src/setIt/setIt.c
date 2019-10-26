#include "setIt.h"
#include <float.h>
// Print results//
void  printResults(int flag,double a,double b,FILE * logFile,int logging){

	if(logging==1) {

		fprintf(logFile, "In print results "
		        "with values of a:%.4f b:%.4f  and "
		        "The flag variable set to :%d\n", a,b,flag );
	}
	// check if either a or b would be over Double max
	if(a>=DBL_MAX||b>=DBL_MAX) {
		printf("%s\n","One of the values is greater than can be output" );
	} // end if
	else{
		// check which print statement to use
		switch (flag) {
		case 0:
			if(logging==1) {

				fprintf(logFile, "Printing that there is an identical result of %.4f\n",a );
			}

			printf("%s%.4f \n", "Result:",a);
			break;
		case 1:
			if(logging==1) {

				fprintf(logFile, "Printing that there the two result %.4f %.4f\n",a,b );
			}
			printf("%s %.4f %.4f \n", "Result:",a,b );
			break;
		case 2:
			if(logging==1) {

				fprintf(logFile, "Printing that there are no real roots\n" );
			}
			printf("%s\n","No real roots found" );

			break;
		default: printf("%s\n","something went wrong" );
			if(logging==1) {

				fprintf(logFile, "Your not supposed to be here \n");
			}
			break;
		}//end switch
		if(logging==1) {

		}
	}
}// End print results
// print Header
void printHeader(){
	printf("JKK Engineers Quadratic Solver  Version: 0.1.\n"
	       "For Help type \"help\"\n"
	       "To exit, type \"q\"\n"
	       "To toggle logging, type \"log\"\n\n"
	       "ax^2 + bx + c enter a,b and c\n"
	       );

}// end print header
