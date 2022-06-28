#include <iostream>
#include <iomanip>
#include "Validate.h"
#include "Station.h"
#include "Logs.h"

using std::cin;
using std::cout;
using std::endl;
using std::left;
using std::setw;

int main() {

    const unsigned int SIZE_BUF = 100;
    char str[SIZE_BUF];
    cout << "Enter expression: ";
    gets(str);

    char message[SIZE_BUF];
    bool status = checking(str, message);
    cout << left << setw(22) << "Checking: ";
    puts(message);
    if(!status){
        printFile(str, message);
        return 1;
    }

    char out[SIZE_BUF] = "\0";
    getPosfixExpression(str, out);
    int result = getResultPostfixExpresson(out);
    cout << left << setw(22) << "Postfix expression: " << out << endl;
    cout << left << setw(22) << "Result: "<< str << "=" << result << endl;

    printFile(str, message,out, result);

    return 0;
}