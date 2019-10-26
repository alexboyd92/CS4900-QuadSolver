#include "setIt.h"
#include <float.h>
// Print results//
void  printResults(int flag,double a,double b){
	// check if either a or b would be over Double max
	if(a>=DBL_MAX||b>=DBL_MAX) {
		printf("%s\n","One of the values is greater than can be output" );
	} // end if
	else{
		// check which print statement to use
		switch (flag) {
		case 0:
			printf("%s%.4f \n", "Result:",a);
			break;
		case 1:
			printf("%s %.4f %.4f \n", "Result:",a,b );
			break;
		case 2:
			printf("%s\n","No real roots found" );
			break;
		default: printf("%s\n","something went wrong" );
		}//end switch
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
