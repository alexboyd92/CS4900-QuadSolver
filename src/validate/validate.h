#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>

#ifndef VALIDATE_H
#define VALIDATE_H

extern int ValidRange(int flag, FILE * logFile, double* a, double* b, double* c);
extern int Tokenize(int flag, FILE * logFile, char * input, double* a, double* b, double* c);
extern int ValidRange(int flag, FILE * logFile, double* a, double* b, double* c);
extern int PointerCheck(int flag, FILE * logFile,char * token, char * nptr);
extern int ValidState(int flag, FILE * logFile, double* a, double* b, double* c);
#endif
