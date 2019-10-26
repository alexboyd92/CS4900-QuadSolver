#include "validate.h"

//---VALIDATE---//
int validate (char * input){
  int check = 0;//return variable
  int tokenCount = 0;

  char * token = strtok(input," ");
  //cases:
  //too long
  if(strlen(input) > 30){
    check = -1;
    printf("Error input too long\n");
  }

  while(token){
  //  printf("Token: %s\n", token);
    token = strtok(NULL, " ");
    ++tokenCount;
  }//end while

  //more than 2 spaces
  if(tokenCount != 3){
    check = -1;
  }//end if

  //not numbers

  //not #.### format
  //not format ##.##
  //not format ###.#
  //or not ##e## format

  return check;
}//end validate
