#include <iostream>
#include "Validate.h"

using std::cin;
using std::cout;
using std::endl;

int main() {

    const unsigned int SIZE_BUF = 40;
    char str[SIZE_BUF];
    cout << "Enter expression: ";
    gets(str);

    char message[SIZE_BUF];
    bool status = checking(str, message);
    puts(message);
    if(!status){
        return 1;
    }



    return 0;
}
