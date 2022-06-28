#ifndef CALCULATOR_LOGS_H
#define CALCULATOR_LOGS_H

#include <iostream>
#include <ctime>

void printFile(const char* expression, const char* message, const char* postfixExpression, const int resultPostfixExpression){
    FILE* out = fopen("history.txt", "a");
    time_t timeNow = time(0);
    char format[] = "\t%sExpression:\t%s\nChecking:\t%s\nPostfixExpression:\t%s\nResult:\t%d\n\n";
    fprintf(out, format, ctime(&timeNow), expression, message, postfixExpression, resultPostfixExpression);
    fclose(out);
}

void printFile(const char* expression, const char* message){
    FILE* out = fopen("history.txt", "a");
    time_t timeNow = time(0);
    char format[] = "\t%sExpression:\t%s\nMessage:\t%s\n\n";
    fprintf(out, format, ctime(&timeNow), expression, message);
    fclose(out);
}

#endif
