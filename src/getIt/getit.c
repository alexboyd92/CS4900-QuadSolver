#include "getit.h"
#include <stdio_ext.h>
//---GetValues---//
char *  GetValues(int flag,FILE * logFile){

        // buffsize limit 100
        char buf[BUFFERSIZE];
        //input returned to calling function
        char * input;
        //pointer to 'newline character' replace
        char * replace;

        printf("Enter values: ");

								fgets(buf,BUFFERSIZE,stdin);
								//while ( getchar() != '\n' );
								__fpurge (stdin);


        //replace first occurance of 'newline char' from fgets
        if((replace = strchr(buf,'\n')) != NULL){
          replace = '\0';
          if(flag == 1){
            fprintf(logFile, "Replacing newline in buf from fgets\n");
          }
        }//end if replace

        input = (char *)malloc(strlen(buf) +1);

        //if logging enabled output to file.
        if(input == NULL) {
          if(flag == 1){
                fprintf(logFile,"Unable to allocate Memory\n");
          }
        }
        else if(flag == 1){
          fprintf(logFile,"Input from user is %s\n", buf);
        }


								strcpy(input,buf);
								return input;
}//END getValues()
