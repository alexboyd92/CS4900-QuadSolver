#include "getit.h"

//---GetValues---//
char *  GetValues(int flag,FILE * logFile){
        // buffsize limit 100
        char buf[BUFFERSIZE];
        //input returned to calling function
        char * input;
        printf("Enter values: ");

<<<<<<< HEAD
        fgets(buf,BUFFERSIZE,stdin);
=======

        buf == fgets(buf,BUFFERSIZE,stdin);
>>>>>>> 77c38d604939ca7a240ef2ebd964064c4845a46c


        input = (char *)malloc(strlen(buf) +1);

        //if logging enabled output to file.
        if(input == NULL) {
          if(flag == 1){
                fprintf(logFile,"Unable to allocate Memory\n");
              }
        }
        strcpy(input,buf);

        return input;
}//END getValues()
