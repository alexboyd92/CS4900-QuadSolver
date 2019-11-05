#include "main.h"
#include <time.h>
// Main //
int main(int argc, char const *argv[]) {
	int quit=1;
	int validateFlag=0;
	char * input; //pointer for getit return
	double a,b,c;
	int flag;
	time_t t= time(0);
	char timestamp[26];
	// get timeStamp
	strftime(timestamp, sizeof(timestamp), "%Y-%m-%d-%H:%M:%S", localtime(&t));
	//	hold status of loggin
	int logging=1;
	// to hold name of logfile
	char writeLog[40]=LOG_FILE;
	// add timestamp to logfile name
	strcat(writeLog,timestamp);
	//file pointer for log file
	FILE *logFile=NULL;


	// if argc == 4 call validate input
	if(argc==4) {
		char * input = malloc(argc + 1);
		strcpy(input, argv[1]);
		strcat(input, " ");
		strcat(input, argv[2]);
		strcat(input, " ");
		strcat(input, argv[3]);
		printf("input is %s\n", input);
		validateFlag = Validate(input, logging, logFile, &a, &b, &c); //validate input from user
		
		if(validateFlag  == -1){
			userTypedHelp();
		}
		else
		{
			//call solve
			flag= solve(&a,&b,&c);
			// call print results
			if(logging==1) {
				fprintf(logFile, "Entering solve with value of "
				        "a:%.4f b:%.4f c:%.4f\n",a,b,c );
			}
			printResults( flag,a,b,logFile,logging);
		}
	}//end if argc==4
	// do while if no arguments are specified
	// if argc is 1
	else if(argc==1) {
		printHeader();
		do {
			// call get Input
	 		input =	GetValues(logging, logFile);

			//if input is q then quit
			// then validate input
			if(logging==1) {
				logFile=fopen(writeLog,"a");
				fprintf(logFile, "Entering validate" );
			}
			validateFlag = Validate(input, logging, logFile, &a, &b, &c);
			// if validate fails call help
			if(validateFlag==-1) {
				//invalid input;
				userTypedHelp();
			}
			else{
				//call solve
				if(logging==1) {
					fprintf(logFile, "Entering solve with value of "
						"a:%.4f b:%.4f c:%.4f\n",a,b,c );
				}
				flag= solve(&a,&b,&c);

				// call print results
				if(logging==1) {
					fprintf(logFile, "Entering print results "
					        "with values of a:%.4f b:%.4f c: %.4f and "
					        "The flag variable set to :%d\n", a,b,c,flag);

				}
				printResults( flag,a,b,logFile,logging);
			}//end else

		} while(quit > 0); //end do while loop

	}//end Elseif(arg1)
	else{
		//call help on argv not 1 or 4
		//help();
	}
	if(logging==1) {
		fclose(logFile);
	}

	return 0;
}// End main//
