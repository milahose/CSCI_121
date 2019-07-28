/*
 Author: Mila Hose
 Date: 07-02-2019
 
 CSCI 121 Project 05
 Test Menu
*/

#include <iostream>
#include <string>
using namespace std;

// post-condition: display test menu
void testMenu();

// pre-condition: year is a valid integer
// post-condition: return true if year is a leap year and false if it is not
bool isLeapYear(int year);

// pre-condition: year is a valid integer
// post-condition: return the century value for the year
int getCenturyValue(int year);

// pre-condition: year is a valid integer
// post-condition: return the value for the year
int getYearValue(int year);

// pre-condition: the month and year are valid integers
// post-condition: return the month value for the given month and year
int getMonthValue(int month, int year);

// pre-condition: month, day and year are valid
// post-condition: return integers 0-6 for days Sunday-Saturday
int dayOfWeek(int month, int day, int year);

// pre-condition: day has integer value 0, 1, 2, 3, 4, 5, or 6
// post-condition: the name of the day of week is returned as a std::. If day
// has value 0, then SUNDAY is returned; 1, then MONDAY is returned; and so on.
string dayOfWeek(int day);

// post-condition: return true if the day is valid, and false if it is not
bool isValid(int year);

// post-condition: return true if the month and year
// are valid, and false if they are not
bool isValid(int month, int year);

// post-condition: return true if the month, day
// and year are valid, and false if they are not
bool isValid(int month, int day, int year);

// pre-condition: user inputs year
// post-condition: if year is valid, continue; else prompt for valid year
void handleUserInput(int& year);

// pre-condition: user inputs month and year
// post-condition: if month and year are valid, continue;
// else prompt for valid month and year
void handleUserInput(int& month, int& year);

// pre-condition: user inputs month, day and year
// post-condition: if month, day and year are valid, continue;
// else prompt for valid month, day and year
void handleUserInput(int& month, int& day, int& year);


int main() {
    using namespace std;
    int choice;
    int day, month, year;
    
    do
    {
        testMenu();
        cout << "Please choose from menu: ";
        cin >> choice;
        
        switch (choice)
        {
            case 1: // check if a given year is leap year
                cout << "Please enter a year: ";
                cin >> year;
                handleUserInput(year);
                if (isLeapYear(year))
                    cout << "Year " << year << " is a leap year" << endl;
                else
                    cout << "Year " << year << " is NOT a leap year" << endl;
                break;
            case 2: // calculate the century value of a given year
                cout << "Please enter a year: ";
                cin >> year;
                handleUserInput(year);
                cout << "The century value is: " << getCenturyValue(year) << endl;
                break;
            case 3: // calculate the year value of a given year
                cout << "Please enter a year: ";
                cin >> year;
                handleUserInput(year);
                cout << "The year value is: " << getYearValue(year) << endl;
                break;
            case 4: // calculate the month value of a given month in a given year
                cout << "Please enter a year and month: ";
                cin >> year >> month;
                handleUserInput(month, year);
                cout << "The month value is: " << getMonthValue(month, year) <<
                endl;
                break;
            case 5: // calculate the day of week of a given date
                cout << "Please enter a year, a month, and a day: ";
                cin >> year >> month >> day;
                cout << "The day of the week is: " << dayOfWeek(month, day, year)
                << endl;
                break;
            case 6: // print out the name of a given day of week
                cout << "Please enter a day of week (0 for Sunday, 1 for Monday, etc): ";
                cin >> day;
                cout << "The name of the day of the week is: " << dayOfWeek(day)
                << endl;
                break;
            case 7:
                cout << "Did you test all functions yet? If not, please rerun the program.\n";
                break;
            default:
                cout << "wrong option. Please choose from menu\n";
                break;
        }
        
    } while (choice != 7);
    
    return 0;
}

void testMenu()
{
    cout << "*************************************\n";
    cout << "* Test Menu *\n";
    cout << "* 1. isLeapYear *\n";
    cout << "* 2. getCenturyValue *\n";
    cout << "* 3. getYearValue *\n";
    cout << "* 4. getMonthValue *\n";
    cout << "* 5. dayOfWeek(month, day, year) *\n";
    cout << "* 6. dayOfWeek(day) *\n";
    cout << "* 7. Quit *\n";
    cout << "*************************************\n";
}

bool isLeapYear(int year)
{
    return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

int getCenturyValue(int year)
{
    return 2 * (3 - (year / 100) % 4);
}

int getYearValue(int year)
{
    return year % 100 + year % 100 / 4;
}

int getMonthValue(int month, int year)
{
    int monthValue;
    
    // Logic from table in textbook
    switch(month)
    {
        case 1:
            if(isLeapYear(year))
                monthValue = 6;
            else
                monthValue = 0;
            break;
        case 2:
            if(isLeapYear(year))
                monthValue = 2;
            else
                monthValue = 3;
            break;
        case 3:
        case 11:
            monthValue = 3;
            break;
        case 4:
        case 7:
            monthValue = 6;
            break;
        case 5:
            monthValue = 1;
            break;
        case 6:
            monthValue = 4;
            break;
        case 8:
            monthValue = 2;
            break;
        case 9:
        case 12:
            monthValue = 5;
            break;
        default:
            monthValue = 0;
            break;
    }
    
    return monthValue;
}

int dayOfWeek(int month, int day, int year)
{
    if (!isValid(month, day, year))
        return -1;
    
    return (getCenturyValue(year) + getMonthValue(month, year) + getYearValue(year) + day) % 7;
}

string dayOfWeek(int day)
{
    string result;
    
    switch(day)
    {
        case 0:
            result = "Sunday";
            break;
        case 1:
            result = "Monday";
            break;
        case 2:
            result = "Tuesday";
            break;
        case 3:
            result = "Wednesday";
            break;
        case 4:
            result = "Thursday";
            break;
        case 5:
            result = "Friday";
            break;
        case 6:
            result = "Saturday";
            break;
        default:
            result = "Invalid date";
            break;
    }
    
    return result;
}

bool isValid(int year)
{   // leap years must be later than 1582
    return year > 1582;
}

bool isValid(int month, int year)
{   // Jan - Dec (months 1-12)
    return month >= 1 && month <= 12 && isValid(year);
}

bool isValid(int month, int day, int year)
{
    bool isValidDay;
    
    switch(month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            isValidDay = day >= 1 && day <= 31; // months with 31 days
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            isValidDay = day >= 1 && day <= 30; // months with 30 days
            break;
        case 2:
            isValidDay = isLeapYear(year) ? (day >= 1 && day <= 29) : (day >= 1 && day <= 28); // February
            break;
        default:
            isValidDay = false;
    }
    
    return isValidDay && isValid(month, year);
}

void handleUserInput(int& year)
{
    while (!isValid(year))
    {
        cout << "Invalid year. Please enter a year after 1582: ";
        cin >> year;
    }
}

void handleUserInput(int& month, int& year)
{
    while (!isValid(month, year))
    {
        cout << "Invalid input. Please enter a year and month: ";
        cin >> year >> month;
    }
}

void handleUserInput(int& month, int& day, int& year)
{
    while (!isValid(month, day, year))
    {
        cout << "Invalid input. Please enter a year, a month, and a day: ";
        cin >> year >> month >> day;
    }
}
