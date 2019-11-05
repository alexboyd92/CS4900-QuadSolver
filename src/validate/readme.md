# Validate
this folder will contain the functions for validating and cleaning input from user

a pointer to a character array is expected when validate is called. This input is the returned input from
Getit.c

int check is used to check the validity of the input.
  When check is set to 0 then input is good and is safe to be used in solveit.c
  when check is set to -1 then input is not valid and should be ignored.

FUNCTIONS FOR validate.c

int Validate (char * input, int flag, FILE * logFile, double* a, double* b, double* c);

int Tokenize(int flag, FILE * logFile, char * input, double* a, double* b, double* c);

int PointerCheck(int flag, FILE * logFile,char * token, char * nptr);

int ValidRange(int flag, FILE * logFile, double* a, double* b, double* c);


int ValidState(int flag, FILE * logFile, double* a, double* b, double* c);



Validate Function
  This function will check the length to make sure input is within a range of 3xfp max length or < 5
  then calls the Tokenize, ValidRange and ValidState functions.
  If everything passes then validate will return check variable to the function call from main.

Tokenize Function
  This function will take the input received from getit.c and put it into doubles A B C using strtof function.
  PointerCheck is called during this process for A B C. If there are more or less than 3 tokens then there is an error and check is set to -1.

PointerCheck Function
  This function will check the pointer used in strtof and check if the input contained additional characters or if the input did not contain a valid sequence of numbers. For example .. 123asdf would store 123 in a double but the pointer would point to asdf instead of '\0'. This function is to detect if input was 123asdf or just 123. Check is set to -1 if additional characters are detected. See strtof man page for more information.

ValidRange Function
  This function will check the range for A B C and compare it to FLT_MAX and FLT_MIN. A is also checked if it is equal to 0 in which case check is set to -1.

ValidState Function
  This function makes sure that A B C is not set to nan or inf during validation. If either are detected check is set to -1.
