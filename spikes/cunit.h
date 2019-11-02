#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <string.h>

/*Later for a log file name
extern FILE *cunit_log;
int cunit_init();

#define cunit_open(log) { \
    if((cunit_log=fopen( log, "w") == NULL ) { \
     cunit_log = stderr; \
    } \
}
#define cunit_close fclose(cunit_log)
#define cunit_flush() fflush(cunit_log)*/
#define cunit_log stdout

#define cunit_date(str) { \
    fprintf(cunit_log, "%s  LINE %d:  DATE:%s TIME:%s :%s\n", \
              __FILE__ , __LINE__ , __DATE__ , __TIME__ , str ); \
}
#define cunit_print(str) { \
    fprintf(cunit_log, "%s\n", str ); \
}

// Integer asserts
#define assertd_eq(str,a,b) { \
  if( a != b ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %d !== %d\n", \
              __FILE__ , __LINE__ , str ,  a , b ); \
  } \
}
#define assertd_neq(str,a,b) { \
  if( a == b ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %d !!= %d\n", \
              __FILE__ , __LINE__ , str ,  a , b ); \
  } \
}
#define assertd_ge(str,a,b) { \
  if( a < b ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %d !>= %d\n", \
              __FILE__ , __LINE__ , str ,  a , b ); \
  } \
}
#define assertd_gt(str,a,b) { \
  if( a <= b ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %d !> %d\n", \
              __FILE__ , __LINE__ , str ,  a , b ); \
  } \
}
#define assertd_le(str,a,b) { \
  if( a > b ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %d !<= %d\n", \
              __FILE__ , __LINE__ , str ,  a , b ); \
  } \
}
#define assertd_lt(str,a,b) { \
  if( a >= b ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %d !< %d\n", \
              __FILE__ , __LINE__ , str ,  a , b ); \
  } \
}

// Double or float assert (floats are promoted to doubles)
#define assertf_eq(str,a,b) { \
  if( a != b ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %24.16f !== %24.16f\n", \
              __FILE__ , __LINE__ , str , a , b ); \
  } \
}
#define assertf_neq(str,a,b) { \
  if( a == b ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %24.16f !== %24.16f\n", \
              __FILE__ , __LINE__ , str , a , b ); \
  } \
}
// eqi equal subject to absolute error
#define assertf_eqaerr(str,a,b,aerr) { \
  if( fabs(a - b) > aerr ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %24.16f !== %24.16f err=%10.6e\n", \
              __FILE__ , __LINE__ , str , a , b , err); \
  } \
}
// eq equal subject to relative error
#define assertf_eqrerr(str,a,b,rerr) { \
  {double rerr1; \
    if((a==0.0) && (b==0.0)) { \
      rerr1 = 0.0; \
    } else { \
      rerr1 = fabs(a - b)/fmax(fabs(a),fabs(b)); \
    } \
    if( rerr1 > rerr ) { \
      fprintf(cunit_log, "%s  LINE %d: %s, %24.16f !>= %24.16f rerr=%10.6e\n", \
                __FILE__ , __LINE__ , str , a , b , rerr ); \
    } \
  } \
}
#define assertf_ge(str,a,b) { \
  if( a < b ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %24.16f !> %24.16f\n", \
              __FILE__ , __LINE__ , str ,  a , b ); \
  } \
}
#define assertf_gt(str,a,b) { \
  if( a <= b ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %24.16f !> %24.16f\n", \
              __FILE__ , __LINE__ , str ,  a , b ); \
  } \
}
#define assertf_le(str,a,b) { \
  if( a > b ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %24.16f !<= %24.16f\n", \
              __FILE__ , __LINE__ , str , a , b ); \
  } \
}
#define assertf_lt(str,a,b) { \
  if( a >= b ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %24.16f !< %24.16f\n", \
              __FILE__ , __LINE__ , str , a , b ); \
  } \
}

// String asserts, could add le lt ge gt
// Also using n might be problematic
#define asserts_eq(str,n,str1,str2) { \
  if( strncmp(str1,str2,n) != 0)  { \
    fprintf(cunit_log, "%s  LINE %d: %s,\n   str1=%s\n   str2=$s\n", \
              __FILE__ , __LINE__ , str , str1 , str2 ); \
  } \
}
#define asserts_neq(str,n,str1,str2) { \
  if( strncmp(str1,str2,n) == 0)  { \
    fprintf(cunit_log, "%s  LINE %d: %s,\n   str1=%s\n   str2=$s\n", \
              __FILE__ , __LINE__ , str , str1 , str2 ); \
  } \
}
