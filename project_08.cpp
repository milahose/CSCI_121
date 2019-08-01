/*
 Author: Mila Hose
 Date: 07-12-2019
 
 CSCI 121 Project 08
 Strings and Vectors
*/

#include <iostream>
#include <vector>
#include <cctype>
#include <string>
using namespace std;

// post-condition: display menu
void menu();

// post-condition: handle UI & user flow for score/stats program
void run_score_manager();

// get integer scores from keyboard and store in v.
// we assume that the user will input scores in range
// of 0 to 100, inclusive. User enter a negative
// number to stop the input and end the function
void get_scores(vector<int> &v, int& n);

// print out the stats of data that are stored in v
// includes: max, min, total number of data,
// and the average
void print_stats(vector<int> &v);

// pre-condition: user score has been requested
// post-condition: if number is valid, move on, otherwise continue to
// prompt for a valid score until one is entered
void validate(int& n);

// pre-condition: all scores have been collected
// post-condition: returns maximum value out of vector
int max(vector<int> &v);

// pre-condition: all scores have been collected
// post-condition: returns minimum value out of vector
int min(vector<int> &v);

// pre-condition: all scores have been collected
// post-condition: returns average score form all
// scores collected from user
double average(vector<int> &v);

// post-condition: handle UI & user flow for palindrome program
void run_palindrome_manager();

// pre-condition: user has entered a sentence
// post-condition: return true if the sentence is a palindrome,
// otherwise, return false
bool is_palindrome(string sentence);

// post-condition: interchanges the values of v1 and v2
void swap(char& v1, char& v2);

// pre-condition: takes in a string
// post-condition: returns the string in reverse order
string reverse(const string& s);

// pre-condition: string has punctuation marks in it
// post-condition: returns string stripped of all punctuation
string remove_punctuation(const string& s, const string& punct);

// pre-condition: string has uppercase letters in it
// post-condition: returns string in all lowercase letters
string to_lowercase(const string& s);

int main() {
    int choice;
    
    do
    {
        menu();
        cout << "\n\n\tPlease enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                run_score_manager();
                break;
            case 2:
                run_palindrome_manager();
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
    cout << "\n\t* 1. Get Score Stats                              *";
    cout << "\n\t* 2. Check for Palindrome                         *";
    cout << "\n\t* 3. Quit                                         *";
    cout << "\n\t***************************************************";
}

void run_score_manager()
{
    vector<int> scores;
    int next;
    char try_new_scores = 'Y';
    
    do
    {
        scores.resize(0);
        cout << "\n\tAdd scores one-by-one, enter -1 to stop: ";
        validate(next);
        
        get_scores(scores, next);
        print_stats(scores);
        
        cout << "\n\tDo you want to try another set of scores? Y/N: ";
        cin >> try_new_scores;
        
    } while(try_new_scores == 'Y' || try_new_scores == 'y');
}

void get_scores(vector<int> &v, int& n)
{
    while(n > 0)
    {
        v.push_back(n);
        cout << "\n\tAdded " << n << " to scores list.";
        cout << "\n\tPlease enter next score: ";
        
        validate(n);
    }
    
    
}

void validate(int& n)
{
    for (;;) {
        if (cin >> n) {
            
            if (n == -1) break;
            
            if (n < 0 || n > 100)
            {
                cout << "\n\tInvalid input! Please enter a positive integer between 0 and 100: ";
                continue;
            }
            
            break; // success -> bail out of loop
        } else {
            cerr << "\n\tInvalid input! Please enter a positive integer between 0 and 100: ";
            cin.clear(); // reset state
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // consume wrong input
        }
    }
}

void print_stats(vector<int> &v)
{
    if (!v.size())
    {
        cout << "\n\t---------------------------------------------------";
        cout << "\n\tThere are no scores.";
        cout << "\n\t---------------------------------------------------\n";
    }
    else
    {
        cout << "\n\t---------------------------------------------------";
        cout << "\n\t                 STATS SUMMARY                   \n";
        cout << "\n\tThere are a total of " << v.size() << " scores.";
        cout << "\n\tThe highest score is: " << max(v);
        cout << "\n\tThe lowest score is: " << min(v);
        cout << "\n\tThe average score is: " << average(v);
        cout << "\n\t---------------------------------------------------\n";
    }
}

int max(vector<int> &v)
{
    int max = v[0];
    
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > max)
            max = v[i];
    }
    
    return max;
}

int min(vector<int> &v)
{
    int min = v[0];
    
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] < min)
            min = v[i];
    }
    
    return min;
}

double average(vector<int> &v)
{
    double average = 0.0;
    
    for (int i = 0; i < v.size(); i++)
    {
        average += v[i];
    }
    
    return average / v.size();
}

void run_palindrome_manager()
{
    string sentence;
    char test_new_palindrome = 'Y';
    
    do
    {
        cout << "\n\tEnter a sentence: ";
        cin.ignore (INT_MAX, '\n');
        getline(cin, sentence);
        
        if (is_palindrome(sentence))
            cout << "\n\t\"" << sentence << "\" is a palindrome.\n";
        else
            cout << "\n\t\"" << sentence << "\" is not a palindrome.\n";

        cout << "\n\tDo you want to try another sentence? Y/N: ";
        cin >> test_new_palindrome;
        
    } while (test_new_palindrome == 'Y' || test_new_palindrome == 'y');
}

bool is_palindrome(string sentence)
{
    string punct(",;:.?!'\" ");
    string str(sentence);
    str = to_lowercase(str);
    string lower_str = remove_punctuation(str, punct);
    
    return (lower_str == reverse(lower_str));
}

void swap(char& v1, char& v2)
{
    char temp = v1;
    v1 = v2;
    v2 = temp;
}

string reverse(const string& s)
{
    string temp(s);
    int start = 0;
    int end = static_cast<int>(temp.length());
    
    while (start < end)
    {
        end--;
        swap(temp[start], temp[end]);
        start++;
    }
    
    return temp;
}

string to_lowercase(const string& s)
{
    string temp(s);
    
    for (int i = 0; i < s.length(); i++)
        temp[i] = tolower(s[i]);
    
    return temp;
}

string remove_punctuation(const string& s, const string& punct)
{
    string stripped;
    
    for (int i = 0; i < s.length(); i++)
    {
        string current_char = s.substr(i, 1);
        int location = static_cast<int>(punct.find(current_char, 0));
        
        if (location < 0 || location >= punct.length())
            stripped = stripped + current_char;
    }
    
    return stripped;
}
