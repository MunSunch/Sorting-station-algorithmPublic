#ifndef CALCULATOR_operatorsATION_H
#define CALCULATOR_operatorsATION_H

#include "MyStack.h"
#include <cstring>
#include <cstdio>

const unsigned int SIZE_BUF = 100;

int getPriorityOperator(char symbol){
    switch (symbol) {
        case '+':
        case '-':
            return 2;
        case '/':
        case '*':
            return 1;
    }
}

void append(char* string, const char symbol){
    int lenght = strlen(string);
    string[lenght] = symbol;
}

void append(char* string, const char* anotherString){
    int lenghtString = strlen(string);
    int lenghtAnotherString = strlen(anotherString);
    for(int i=0; i<lenghtAnotherString; i++){
        string[lenghtString + i] = anotherString[i];
    }
}

void getPosfixExpression(char* in, char* out){
    //  https://en.wikipedia.org/wiki/Shunting_yard_algorithm
    stack<char>* operators = nullptr;
    const char div = ' ';
    for(int i=0; in[i] != '\0'; i++){
        char symbol = in[i];
        if(isdigit(symbol)){
            append(out, symbol);
        } else {
            append(out, div);

            if(isEmpty(operators)){
                push(operators, symbol);
                continue;
            }

            if(symbol == '('){
                push(operators, symbol);
                continue;
            }
            if(symbol == ')'){
                while(getTop(operators) != '('){
                    append(out, getTop(operators));
                    append(out, div);
                    pop(operators);
                }
                pop(operators);
                continue;
            }


            int priorityCurrentOperator = getPriorityOperator(symbol);
            int priorityTopStackOperator = getPriorityOperator(getTop(operators));
            if(priorityCurrentOperator < priorityTopStackOperator){
                push(operators, symbol);
            } else {
                while(!isEmpty(operators) && priorityCurrentOperator >= getPriorityOperator(getTop(operators))){
                    append(out, getTop(operators));
                    append(out, div);
                    pop(operators);
                }
                push(operators, symbol);
            }
        }
    }

    append(out, div);
    while(!isEmpty(operators)){
        append(out, getTop(operators));
        append(out, div);
        pop(operators);
    }
}

int getResultOperation(int a, int b, char operation){
    switch (operation) {
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return std::max(a,b)/std::min(a,b);
    }
}

int getResultPostfixExpresson(const char* postfixExpression) {
    char buf[SIZE_BUF];
    strcpy(buf, postfixExpression);

    stack<int> *numbers = nullptr;
    const char div[] = " ";

    char *ptr = strtok(buf, div);
    while (ptr != NULL) {
        if (isdigit(*ptr)) {
            push(numbers, atoi(ptr));
        } else {
            int firstOperand = pop(numbers);
            int secondOperand = pop(numbers);
            int result = getResultOperation(secondOperand, firstOperand, *ptr);
            push(numbers, result);
        }
        ptr = strtok(NULL, div);
    }

    return pop(numbers);
}

#endif //CALCULATOR_operatorsATION_H
