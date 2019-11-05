#include <stdio.h>


void userTypedHelp(){//This is the message the user gets when they type help
printf("This program will solve a quadratic equation (ax^2+bx+c=0). You must type in three numbers (a,b, and c) separated by a space\n");
printf("Examples of acceptable input:\n");
printf("1 2 3\n");
printf("500 3 26\n");
printf("4900 765 10000\n");

printf("If you want the results outputted to a logging file, type log\n");
printf("If you want to exit this program, type q\n" );
}
