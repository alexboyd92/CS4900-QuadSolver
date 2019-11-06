#include "cunit.h"
#include "../validate/validate.h"


int main(){

  char * input="123";
  double a=2;
  double b=1;
  double c=2;

int checker= Validate(input,0,NULL,&a,&b,&c);

assertd_eq("checker", checker, -1);







return 0;
}
