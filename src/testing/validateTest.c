#include "cunit.h"
#include "../validate/validate.h"
#include <string.h>



int main(){


//Test to make sure validate returns -1 with bad input

	char input[2000] ="-1 ";
	FILE * d=NULL;
	double a=0;
	double b=0;
	double c=0;

	int checker= Validate(input,0,d,&a,&b,&c);

	assertd_eq("checker", checker, 0);







	return 0;
}
