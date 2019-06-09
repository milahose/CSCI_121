// Author: Mila Hose
// Date: 06-06-2019

/* This is my first C++ program.
 CSCI 121 Computer Science I
 
 STEP 3 ANSWER:
 I have used \n instead of endl for my
 program, because that is what the textbook
 suggests for lines that end in strings as
 opposed to variables. I have also not used
 system(“pause”) in this program, as there is
 no reason for user input. When/if there is a
 need for user input, cin should be used instead.
 
 STEP 5 ANSWER:
 Changing cout to Cout results
 in the following error:
 Use of undeclared identifier 'Cout'; did you mean 'cout'? */

#include <iostream>
using namespace std;

int main()
{
    cout << "Hello, World!\n"; // using new line escape sequence since line ends in a string
    cout << "This is my first C++ program.\n"; // textbook recommends to always end lines using
    // \n if line ends in a string or endl if it ends in a variable
    // no need to use system(“pause”), since we are not waiting for input from a user in this program
    // attempting to use system("pause") also causes the following error: sh: pause: command not found
    // it is best practice to return out of a function
    return 0;
}
