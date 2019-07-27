/*
 Author: Mila Hose
 Date: 06-26-2019
 
 CSCI 121 Project 04
 The Temperature of Earth at a Depth
*/

#include <iostream>
using namespace std;


void print_introduction();
// Prints out information to tell the
// user what this program does.

double celsius_at_depth(double depth);
// Computes and returns the celsius
// temperature at a depth measured in kilometers.

double celsius_to_fahrenheit(double celsius);
// Converts a Celsius temperature celsius to Fahrenheit.

void print_conclusion(double depth);
// Display the conclusion that what is the temperature
// in both Celsius and Fahrenheit at depth of the earth.

int main()
{
    double depth;
    char user_wants_to_continue = 'Y';
    
    print_introduction();
    
    while (user_wants_to_continue == 'Y' || user_wants_to_continue == 'y')
    {
        cout << "Enter a depth in KM: ";
        cin >> depth;
        
        print_conclusion(depth);
        
        cout << "Would you like to do it again? (Y/N): ";
        cin >> user_wants_to_continue;
    }
    
    cout << "See you next time!";
    return 0;
}

void print_introduction()
{
    cout << "Hello! The program will tell you the temperature of the earth at any depth.\n";
}

double celsius_at_depth(double depth)
{
    return (10.0 * depth + 20.0);
}

double celsius_to_fahrenheit(double celsius)
{
    return (1.8 * celsius + 32);
}

void print_conclusion(double depth)
{
    double degrees_celsius, degrees_fahrenheit;
        
    degrees_celsius = celsius_at_depth(depth);
    degrees_fahrenheit = celsius_to_fahrenheit(degrees_celsius);
    
    cout << "The temperature of the earth at a depth of " << depth;
    cout << " KM is " << degrees_celsius << " in Celsius, ";
    cout << "and " << degrees_fahrenheit << " in Fahrenheit.\n";
}
