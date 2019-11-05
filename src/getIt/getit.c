#include "getit.h"

//---GetValues---//
char *  GetValues(int flag,FILE * logFile){
								// buffsize limit 100
								char buf[BUFFERSIZE];
								//input returned to calling function
								char * input;
								printf("Enter values: ");

								fgets(buf,BUFFERSIZE,stdin);
								//while ( getchar() != '\n' );
								__fpurge (stdin);

								input = (char *)malloc(strlen(buf) +1);
								//if logging enabled output to file.
								if(input == NULL) {
																if(flag == 1) {
																								fprintf(logFile,"Unable to allocate Memory\n");
																}
								}
								else if(flag == 1) {
																fprintf(logFile,"Input from user is %s\n", buf);
								}

								strcpy(input,buf);
								return input;
}//END getValues()
