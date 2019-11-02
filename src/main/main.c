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
		Validate(logging, logFile, a, b, c);
		if(validateFlag	 ==-1)
			//help();
			;
		else
		{       //call solve
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
		 //input =	GetValues(logging, logFile);
		 //if input is q then quit
			// then validate input
			if(logging==1) {
				logFile=fopen(writeLog,"a");
				fprintf(logFile, "Entering validate" );
			}
		 validateFlag  =	Validate(logging, logFile, a, b, c);
			// if validate fails call help
			if(validateFlag==-1){
				//invalid input;
				//help();
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

		} while(!quit); //end do while loop

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
