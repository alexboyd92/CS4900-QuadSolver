#include "cunit.h"
#include "../validate/validate.h"



int main(){


//Test to make sure validate returns -1 with bad input
  char * input=" ";
  double a=2;
  double b=1;
  double c=2;

int checker= Validate(input,0,NULL,&a,&b,&c);

assertd_eq("checker", checker, -1);







return 0;
}
