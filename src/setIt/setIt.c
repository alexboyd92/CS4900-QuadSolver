#include "setIt.h"
#include <float.h>

void  printResults(int flag,double a,double b){
	if(a>=DBL_MAX||b>=DBL_MAX) {
		printf("%s\n","One of the values is greater than can be output" );
	}
	else{
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
		}
	}
}
