// File: ex_cunit.c t1.c
// License GPL 2.0 JKK Consulting 2019
// 
// Simple examples of using cunit.h 
// For validating cunit.h far more examples carefully chosen
// should be checked.
// The str arguments below are:
//    "S" if the assert should Pass and 
//    "F" is the assert should Fail
//    "" for neither :-)
// If it runs properly only "F" should be printed in output
// The total number of "F" lines that should appear is printed 
//  at the end of the output.

#include <stdlib.h>
#include "cunit.h"

int main() {
int	flines=0;  // counter for the number of asserts that should fail.
double	xd, yd, zd;

cunit_print("Run of ex_cunit\n");
cunit_date("");
cunit_print("\n");

// Integer asserts
assertd_eq("S",2,2);
assertd_eq("F",1,2);
flines++;
assertd_neq("F",2,2);
flines++;
assertd_neq("S",1,2);
assertd_ge("S ",2,1);
assertd_ge("F ",1,2);
flines++;
assertd_gt("S ",2,1);
assertd_gt("F ",1,1);
flines++;
assertd_le("S",1,2);
assertd_le("F",2,1);
flines++;
assertd_lt("S",1,2);
assertd_lt("F",1,1);
flines++;

// Double or float assert (floats are promoted to doubles);
assertf_eq("S",3.14,3.14);
assertf_eq("F",3.14,3.13);
flines++;
// Note these two are equal when converted to double because ther
// are extra digits that have not effect
assertf_eq("S",3.14159267345212341121333,3.14159267345212341121331);
assertf_eq("S",INFINITY,INFINITY);
assertf_eq("F",NAN,NAN);
flines++;
assertf_neq("F",3.14,3.14);
flines++;
assertf_neq("S",3.14,3.13);
assertf_neq("F",3.14159267345212341121333,3.14159267345212341121331);
flines++;
assertf_neq("F",INFINITY,INFINITY);
flines++;
assertf_neq("S",INFINITY,-INFINITY);
// Note this fails, can't compare a NAN to anything
assertf_neq("S",NAN,NAN);
// assertf_eqaerr(" ",a,b,aerr);
assertf_eqaerr("S",1.001, 1.002, 0.002);
assertf_eqaerr("F",1.001, 1.002, 0.0002);
flines++;
// assertf_eqrerr(" ",a,b,rerr);
assertf_eqrerr("S",1.001*100.0, 1.002*100.0, 0.002);
assertf_eqrerr("F",1.001*100.0, 1.002*100.0, 0.0002);
flines++;
assertf_eqrerr("F",1.001, 1.002, 0.0001);
flines++;
// Agree to approximately all but the last decimal place 
// as a double precision 
assertf_eqrerr("F",1.000001, 1.000002, DBL_EPSILON*10.0);
flines++;
// Agree to approximately all but the last decimal place 
// as a float (32 bits)
assertf_eqrerr("S",1.000001, 1.000002, FLT_EPSILON*10.0);
// assertf_ge(" ",a,b);
assertf_ge("S",INFINITY,DBL_MAX);
assertf_ge("S",INFINITY,1.0e30);
assertf_ge("F",INFINITY,NAN);
flines++;
// assertf_gt(" ",a,b);
assertf_gt("F",INFINITY,INFINITY);
flines++;
 // assertf_le(" ",a,b);
 // assertf_lt(" ",a,b);
 // 
// String asserts, could add le lt ge gt
// asserts_eq(" ",n,str1,str2);
asserts_eq("S",17,"SLEEP WELL ELIJAH","SLEEP WELL ELIJAH");
asserts_eq("S",10,"SLEEP WELL ELIJAHX","SLEEP WELL ELIJAHY`");
asserts_eq("F",10,"SLEEP ","SLEEP");
flines++;
 // asserts_neq(" ",n,str1,str2);
 // 
 // // IEEE-fp testing
 // assertf_normal(" ",a);
 // assertf_nnormal(" ",a);
 // assertf_subnnormal(" ",a);
 // assertf_nsubnormal(" ",a);
 // assertf_nan(" ",a);
 // assertf_nnan(" ",a);
 // assertf_inf(" ",a);
 // assertf_ninf(" ",a);
 // assertf_posinf(" ",a);
 // assertf_neginf(" ",a);
 // }
printf("There should be %d \"F\" lines above and no \"S\" lines\n", flines);

}
