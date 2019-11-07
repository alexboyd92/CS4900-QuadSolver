#include "cunit.h"
#include "../validate/validate.h"
#include <string.h>



int main(){


//Test to make sure validate returns -1 with buffer overflow

	char input[2000] ="11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111 1 1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
	FILE * d=NULL;
	double a=0;
	double b=0;
	double c=0;

	int checker= Validate(input,0,d,&a,&b,&c);

	assertd_eq("checker", checker, -1);


//Test to make sure validate returns -1 with random characters

	char input2[2000]="abc def gfjwlafjasd;lkfjewofjsdkdsmklfjadskleh";

	checker= Validate(input2,0,d,&a,&b,&c);

	assertd_eq("checker", checker,-1);




//Test to make sure validate returns -1 when input is too short( <5)
	char input3[2000]="1234";

	checker= Validate(input3,0,d,&a,&b,&c);

	assertd_eq("checker", checker,-1);









	return 0;
}
