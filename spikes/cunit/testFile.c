//#include "simple_cunit"
//#include <CUnit/CUnit.h>
#include <CUnit/Automated.h>
#include <CUnit/Basic.h>
#include <CUnit/Console.h>
//#include <CUnit/CUCurses.h>

#include <CUnit/CUnit.h>
int maxi(int i1, int i2){
        return (i1 > i2) ? i1 : i2;
}

void test_maxi(void){
        CU_ASSERT(maxi(0,2) == 2);
        CU_ASSERT(maxi(0,-2) == 0);
        CU_ASSERT(maxi(2,2) == 2);
}

int main(int argc, char const *argv[]) {
        test_maxi();
        return 0;
}


/*int main(int argc, char const *argv[]) {
   test_example();


        printf("make sure a=a and test a=b\n");

        float a = 2.00;
        float b = 1.35;

        CU_ASSERT_TRUE(a=a);
        CU_ASSERT_TRUE(b=a);
        return 0;
   }



   int maxi(int i1, int i2){
      return (i1 > i2) ? i1 : i2;
   }

   void test_example(void){
   CU_ASSERT(maxi(0,2) == 2);
   CU_ASSERT(maxi(0,-2) == 0);
   CU_ASSERT(maxi(2,2) == 2);
   }

 */
