#ifndef CALCULATOR_VALIDATE_H
#define CALCULATOR_VALIDATE_H

#include "MyStack.h"
#include <cstdio>

bool checking1(const char* string)  // 364362894++--(--)    --> true
{                                   // cbewbiufewd  --> false
    const char SPECIAL_SYMBOLS[] = "0123456789+-*/()";
    for(int i = 0; string[i] != '\0'; i++)
    {
        char symbolString = string[i];
        bool flag = true;
        for(int j=0; SPECIAL_SYMBOLS[j] != '\0'; j++)
        {
            char symbolSpecialSymbols = SPECIAL_SYMBOLS[j];
            if(symbolString == symbolSpecialSymbols)
            {
                flag = false;
            }
        }
        if(flag)
        {
            return false;
        }
    }
    return true;
}





bool isOpenBracket(char symbol)
{
    return symbol == '(';
}
bool isCloseBracket(char symbol)
{
    return symbol == ')';
}

bool checking2(const char* string)   // (((2+2)) - (65+1))   --> true
{                                    // (((((  --> false
    stack<int>* st_OpenBrackets = nullptr;
    stack<int>* st_CloseBrackets = nullptr;

    for(int i=0; string[i] != '\0'; i++)
    {
        char symbol = string[i];
        if(isOpenBracket(symbol))
        {
            push(st_OpenBrackets, 1);
        }
        if(isCloseBracket(symbol))
        {
            push(st_CloseBrackets, 1);
            if(!isEmpty(st_OpenBrackets) && !isEmpty(st_CloseBrackets))
            {
                pop(st_OpenBrackets);
                pop(st_CloseBrackets);
            }
        }
    }

    return isEmpty(st_OpenBrackets) && isEmpty(st_CloseBrackets);
}






bool isOperator(char symbol){
    return symbol=='+' || symbol=='-' || symbol=='*' || symbol=='/';
}

bool checking3(const char* string)  // 12+12+34*(312-121)-1   --> true
{                                   // 12+++-12(-)23132/      --> false
    if(isOperator(string[strlen(string)-1])){
        return false;
    }
    for(int i=1; string[i] != 0; i++){
        char symbol = string[i];
        char pre_symbol = string[i-1];
        if(isOperator(pre_symbol) && isOperator(symbol)){   // ++ и т.д.
            return false;
        }
        if(isdigit(pre_symbol) && isOpenBracket(symbol) ||
                isOpenBracket(pre_symbol) && isOperator(symbol)){   // 1( или (+
            return false;
        }
    }
    return true;
}





struct checkStatus {
    const char* ERROR_INVALID_CHARACTERS = "ERROR!Valid characters: \"0123456789+-*/()\"";
    const char* ERROR_IMBALANCE_BRACKETS = "ERROR!Bracket imbalance";
    const char* ERROR_INCORRECT_ORDER = "ERROR!Incorrect order of order: \"2(\", \"++\", \"(-\"";
    const char* SUCCESS = "Success";
} status;

bool checking(const char* string, char* message){
    if(!checking1(string)){
        strcpy(message, status.ERROR_INVALID_CHARACTERS);
        return false;
    }
    if(!checking2(string)){
        strcpy(message, status.ERROR_IMBALANCE_BRACKETS);
        return false;
    }
    if(!checking3(string)){
        strcpy(message, status.ERROR_INCORRECT_ORDER);
        return false;
    }
    strcpy(message, status.SUCCESS);
    return true;
}

#endif //CALCULATOR_VALIDATE_H









