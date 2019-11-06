#include "cunit.h"
#include "../solveIt/solveIt.h"
#include <stdlib.h>


int main(){


//Test to see if it returns proper value when there's no root
double a=0;
double b=0;
double c=0;


int checker=solve(&a, &b, &c,0,NULL);
assertd_eq("checker", checker, 2);



//Test to see if it returns proper value when there's 2 roots
a=10;
b=10;
c=1;

checker=solve(&a, &b, &c,0,NULL);
assertd_eq("checker", checker, 1);


//Test to see if it returns proper value when there's 1 root
a=4;
b=4;
c=1;

checker=solve(&a, &b, &c,0,NULL);
assertd_eq("checker", checker, 0);




//Test solvit 100,000 times with large random integers to see if it'll give an error
for (int i = 0; i < 100000; i++) {
  a= round(100*drand48());
  b= round(100*drand48());
  c= round(100*drand48());

  checker=solve(&a, &b, &c,0,NULL);
  assertd_neq("checker", checker, -1);

}









  return 0;
}
