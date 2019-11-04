#include "main.h"
#include <time.h>

// Main //
int main(int argc, char const *argv[]) {
	int quit=1;
	int validateFlag=0;
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
		//validateInput()
		if(validateFlag==-1)
			// call HELP
			userTypedHelp();

		else
		{         //call solve
			flag= solve(&a,&b,&c);
			// call print results
			if(logging==1) {
				fprintf(logFile, "Entering solve with value of "
				        "a:%.4f b:%.4f c:%.4f\n",a,b,c );
			}
			printResults( flag,a,b,logFile,logging);
		}

	}
	// do while if no arguments are specified
	// if argc is 1
	else if(argc==1) {
		printHeader();
		do {
			// call get input
			//getit();
			// then validate input
			if(logging==1) {
				logFile=fopen(writeLog,"a");
				//fprintf(logFile, "Entering validate" );
			}

			//validate();
			// if validate fails call userTypedHelp
			if(validateFlag==-1)

				userTypedHelp();
			// check if logging is enabled
			else if(validateFlag==2) {
				logging^=1;
				printf("Logging enabled\n" );
			}
			else if(validateFlag==5) {
				//  if input = q quit =1
				if(logging==1)
					fprintf(logFile, "Exiting" );
				if(validateFlag==5)
					quit=1;
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
			}

		} while(!quit);

	}
	else{
		userTypedHelp();
	}









	if(logging==1) {
		fclose(logFile);
	}
	return 0;
}// End main//
