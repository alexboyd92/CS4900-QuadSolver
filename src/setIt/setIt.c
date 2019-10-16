#include "setIT.h"
void  printResults(int flag,double a,double b){
	switch (flag) {
	case 0:
		printf("%s %.4f\n", "Result:",a );
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
