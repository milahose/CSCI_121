/*
 Author: Mila Hose
 Date: 07-15-2019
 
 CSCI 121 Project 09
 Recursion
*/

#include <iostream>
using namespace std;

// post-condition: display menu
void menu();

// post-condition: handle UI & user flow for sum program
void run_sum_numbers_manager();

// pre-condition: User enters valid integer
// post-condition: Uses recursion to calculate
// the sum of 1 + 2 + .... + n
int sum(int n);

// pre-condition: number has been entered by user
// post-condition: if number is valid (positive), move on, otherwise continue to
// prompt for a valid score until one is entered
void validate(int& n);

// post-condition: handle UI & user flow for sum characters program
void run_sum_chars_manager();

// Recursive version of strlen in C strings.
// It returns the length of the string s[].
// (the null character, '\0', is not counted in the length)
int str_length(const char s[]);


int main(int argc, const char * argv[]) {
    int choice;
    
    do
    {
        menu();
        cout << "\n\n\tPlease enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                run_sum_numbers_manager();
                break;
            case 2:
                run_sum_chars_manager();
                break;
            case 3:
                cout << "\n\tGoodbye!";
                break;
            default:
                cout << "\n\tWrong option. Please choose from menu.\n";
                break;
        }
        
    } while (choice != 3);
    
    return 0;
}

void menu()
{
    cout << "\n\t***************************************************";
    cout << "\n\t*                   Menu                          *";
    cout << "\n\t* 1. Sum up to n numbers                          *";
    cout << "\n\t* 2. Sum n characters in a sentence               *";
    cout << "\n\t* 3. Quit                                         *";
    cout << "\n\t***************************************************";
}

void run_sum_numbers_manager() {
    int n;
    char sum_new_value = 'Y';
    
    do
    {
        cout << "\n\tEnter a positive integer: ";
        validate(n);
        
        cout << "\n\tThe sum of 1+2+...+" << n << " is " << sum(n) << endl;
        
        cout << "\n\tDo you want to have another run? Y/N: ";
        cin >> sum_new_value;
        
    } while(sum_new_value == 'Y' || sum_new_value == 'y');
}

int sum(int n)
{
    return (n == 0 ? n : n + sum(n - 1));
}

void validate(int& n)
{
    for (;;) {
        if (cin >> n) {
            
            if (n < 1)
            {
                cout << "\n\tInvalid input. Please enter a positive integer: ";
                continue;
            }
            
            break; // success -> bail out of loop
        } else {
            cerr << "\n\tInvalid input. Please enter a positive integer: ";
            cin.clear(); // reset state
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // consume wrong input
        }
    }
}

void run_sum_chars_manager() {
    char sentence[80];
    char sum_new_sentence = 'Y';
    
    do
    {
        cout << "\n\tEnter a sentence: ";
        cin.ignore (INT_MAX, '\n');
        cin.getline(sentence, 81);
        
        cout << "\n\tThe string \"" << sentence << "\" contains";
        cout << "\n\t" << str_length(sentence)  << " characters, including white spaces.\n";
        
        cout << "\n\tDo you want to have another run? Y/N: ";
        cin >> sum_new_sentence;
        
    } while(sum_new_sentence == 'Y' || sum_new_sentence == 'y');
}

int str_length(const char s[])
{
    return (*s == '\0' ? 0 : 1 + str_length(s + 1));
}
