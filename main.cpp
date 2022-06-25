#include <iostream>
#include <cstring>
#include "Validate.h"
#include "Station.h"

using std::cin;
using std::cout;
using std::endl;

const unsigned long FIVE_SECONDS = 500000000;
void pause(const unsigned long t){
    for(int i=1; i != t; i++);
}

int main() {

    const unsigned int SIZE_BUF = 40;
    char str[SIZE_BUF];
    cout << "Enter expression: ";
    gets(str);

    char message[SIZE_BUF];
    bool status = checking(str, message);
    cout << "Checking... ";
//    pause(FIVE_SECONDS);
    puts(message);
    if(!status){
        return 1;
    }

    char out[SIZE_BUF] = "\0";
    cout << "Postfix expression: ";
    getPosfixExpression(str, out);
    cout << out << endl;
    cout << "Result: "<< str << "=" << getResultPostfixExpresson(out) << endl;

    return 0;
}