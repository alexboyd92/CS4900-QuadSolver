#include "main.h"
#include <time.h>
// Main //
int main(int argc, char const *argv[]) {
	int quit=0; // while loop control variable -1 on exit.
	int validateFlag=0;//holds return variable from validate function
	int logging=0; // sets logging
	char * input; //pointer for getit return

	//variables for quadratic equation
	double a = 0;
	double b = 0;
	double c = 0;
	int flag = 0;

	time_t t= time(0); // time stamp for log file
	char timestamp[26];
	// get timeStamp
	strftime(timestamp, sizeof(timestamp), "%Y-%m-%d-%H:%M:%S", localtime(&t));

	// to hold name of logfile
	char writeLog[40]=LOG_FILE;
	// add timestamp to logfile name
	strcat(writeLog,timestamp);
	//file pointer for log file
	FILE *logFile=NULL;

	// if argc == 4 call validate input
	// default no logging enabled and run program.
	if(argc==4) {
		char input[500];
		strcpy(input, argv[1]);
		strcat(input, " ");
		strcat(input, argv[2]);
		strcat(input, " ");
		strcat(input, argv[3]);

		validateFlag = Validate(input, logging, logFile, &a, &b, &c); //validate input from user

		if(validateFlag  == -1) {
			userTypedHelp();
		}
		else
		{
			//validate passed safe to convert
			sscanf(argv[1],"%lf", &a);
			sscanf(argv[2],"%lf", &b);
			sscanf(argv[3],"%lf", &c);

			//call solve
			flag= solve(&a,&b,&c,logging,logFile);
			// call print results
			printResults( flag,a,b,logFile,logging);
		}
	}//end if argc==4
	// do while if no arguments are specified
	// if argc is 1
	else if(argc==1) {
		printHeader();
		do {
			// call get Input
			input = GetValues(logging, logFile);

			int returned = 0;
			returned = strcmp(input,"q\n");

			//if input is q then quit
			if(returned == 0) {
				quit =-1;// set control to -1 to exit loop
				break;
			}else{
				returned = strcmp(input,"log\n");

				//if input is log then enable logging
				if(returned == 0) {
					logging = 1; // enable logging

				}
			}


			// then validate input
			if(logging==1) {
				printf("%s\n","Here you great " );
				logFile=fopen(writeLog,"a");
				//	fprintf(logFile, "Entering validate" );
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
				flag= solve(&a,&b,&c,logging,logFile);

				// call print results
				if(logging==1) {
					fprintf(logFile, "Entering print results "
					        "with values of a:%.4f b:%.4f c: %.4f and "
					        "The flag variable set to :%d\n", a,b,c,flag);

				}
				printResults( flag,a,b,logFile,logging);
			}        //end else

		} while(quit == 0); //end do while loop

	}//end Elseif(arg1)
	else {
		//call help on argv not 1 or 4
		//help();
	}
	if(logging==1) {
		fclose(logFile);
	}

	return 0;
}// End main//
