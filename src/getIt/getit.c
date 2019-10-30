#include "getit.h"

//---GetValues---//
char *  GetValues(){
  // buffsize limit 100
  char buf[BUFFERSIZE];
  //input returned to calling function
  char * input;


  printf("Enter values: ");

  buf == fgets(buf,BUFFERSIZE,stdin);

  input = (char *)malloc(strlen(buf) +1);

  //if logging enabled output to file.
  if(input == NULL) {
          printf("Unable to allocate Memory");
  }

  strcpy(input,buf);

  return input;
}//END getValues()
