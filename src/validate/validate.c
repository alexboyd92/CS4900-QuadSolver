#include "validate.h"

//--Tokenize--//
int Tokenize(int flag, FILE * logFile, char * input, double* a, double* b, double* c){
	int check = 0;
	int tokenCount = 0;
	char * nptr;

	char * token = strtok(input," ");
	//cases:
	while(token) {
		if(tokenCount == 0){
			*a = strtof(token,&nptr);
	//		printf("a is : %38.38f\n", *a);
		}//end token1 if
		if(tokenCount == 1) {
			*b = strtof(token,&nptr);
		//	 printf("b is : %38.38f\n", *b);
		}//end token2 if
		if(tokenCount == 2) {
			*c = strtof(token,&nptr);
		//	printf("c is : %38.38f\n", *c);
		}//end token3 if
		token = strtok(NULL, " ");
		++tokenCount;
	}//end while

	//more or less than 2 spaces
	if(tokenCount != 3) {
		check = -1;
		if(flag == 1) {
			fprintf(logFile,"Invalid input format during tokenize function\n");
		}
	}//end if

	return check;
}//end Tokenize()


//--ValidRange--//
int ValidRange(int flag, FILE * logFile, double* a, double* b, double* c){

	int inRange = 0;

	if(*a > FLT_MAX || *a < FLT_MIN) {
		inRange = -1;
		if(flag == 1) {
			fprintf(logFile,"Variable A is outside acceptable range\n");
		}
	}//end if a range
	if(*b > FLT_MAX || *b < FLT_MIN) {
		inRange = -1;
		if(flag == 1) {
			fprintf(logFile,"Variable B is outside acceptable range\n");
		}
	}//end if b range
	if(*c > FLT_MAX || *c < FLT_MIN) {
		inRange = -1;
		if(flag == 1) {
			fprintf(logFile,"Variable C is outside acceptable range\n");
		}
	}//end if c range

	return inRange;
}//end ValidFloat()

//--ValidState--//
int ValidState(int flag, FILE * logFile, double* a, double* b, double* c){
	int check;

	if(isinf(*a)==1 || isinf(*b)==1 || isinf(*c)==1) {
		check = -1;
		if(flag == 1) {
			fprintf(logFile,"Input contains INF\n");
		}
	}//end if inf abc

	if(isnan(*a) == 1 || isnan(*b) == 1 || isnan(*c) == 1) {
		check = -1;
		if(flag == 1) {
			fprintf(logFile,"Input contains NaN\n");
		}
	}//end if nan abc

	return check;
}//end ValidState()

//--VALIDATE--//
int Validate (char * input, int flag, FILE * logFile, double* a, double* b, double* c){
	int check = 0;//return variable
	//too long or too short input char array
	if(strlen(input) > 140) {
		check = -1;
		if(flag == 1) {
			fprintf(logFile,"Error input too long\n");
		}
	}
	if(strlen(input) < 5) {
		check = -1;
		if(flag == 1) {
			fprintf(logFile,"Error input too short\n");
		}
	}
	//convert char * input to doubles
	if(Tokenize(flag,logFile,input, a, b, c) < 0 ) {
		check = -1;
	}
	if(ValidRange(flag,logFile,a,b,c) < 0) {
		check = -1;
	}
	if(ValidState(flag,logFile,a,b,c)< 0) {
		check = -1;
	}

	return check;
}//end Validate()
