/* This program requires the student to write 3 functions described in
 * Program project 4 (Page 535) and Program Project 6 (Page 536).
 * The student also need to add a print function to print out an array.
 * The student may watch video notes on MyProgrammingLab to get the idea
 * on how to write the main function and three of these four functions
 *
 * Author: Mila Hose
 * Version: 09-01-2019
 *
 * CSCI 221 Project 01
 * Pointers and Dynamic Arrays
 *
 */

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// Precondition: The front and rear are pointing to the front
//               and rear of a C-string, respectively
// Postcondition: The C-string is reversed
void reverse(char* front, char* rear);

// Precondition: dynamicArray point to a array of strings with give size,
//               newEntry is a string
// Postcondition: A new dynamic array is created, which is one larger than
//                dynamicArray All elements from dynamicArray are copied to
//                new array, the new entry is added to new array, the size
//                is increased, the dynamicArray is deleted, new dynamic
//                array is returned.
string* addEntry(string* dynamicArray, int& size, string newEntry);

// Precondition: dynamicArray point to a array of strings with give size,
//               newEntry is a string
// Postcondition: The function should search dynamicArray for entryToDelete.
//                If not found, the request should be ignored and the
//                unmodified dynamicArray returned. If found, create a new
//                dynamic array one element smaller than dynamicArray. Copy
//                all element except entryToDelete into the new array, delete
//                dynamicArray, decrement size, and return the new dynamic
//                array
string* deleteEntry(string* dynamicArray, int& size, string entryToDelete);

// Precondition: dynamicArray point to a array of strings with give size,
// Postcondition: The elements in dynamic array will be print out. One
//                element per line forllowed by its index
void print(const string* dynamicArray, int size);

int main()
{
    // Make an array and put some names into it
    int size = 5;
    string *names = new string[size];
    names[0] = "Joe";
    names[1] = "Sally";
    names[2] = "Tom";
    names[3] = "Steven";
    names[4] = "Phoenix";
    
    cout << "Initial list:" << endl;
    print(names, size);
    
    // Add some names
    names = addEntry(names, size, "Nicole");
    names = addEntry(names, size, "Michael");
    
    cout << "After adding names:" << endl;
    print(names, size);
    
    // Delete some names
    names = deleteEntry(names, size, "Steven");
    names = deleteEntry(names, size, "Jennifer"); // Non-existent name
    names = deleteEntry(names, size, "Michael");
    
    cout << "After deleting names:" << endl;
    print(names, size);
    
    // Testing a string with even length
    char even_str[] = "coding";
    cout << "Even-length c-string before reversal:" << endl;
    cout << even_str << endl;
    
    reverse(&even_str[0], &even_str[5]);
    
    cout << "Even-length c-string after reversal:" << endl;
    cout << even_str << endl;
    
    // Testing a string with odd length
    char odd_str[] = "programming";
    cout << "\nOdd-length c-string before reversal:" << endl;
    cout << odd_str << endl;
    
    reverse(&odd_str[0], &odd_str[10]);
    
    cout << "\nOdd-length c-string after reversal:" << endl;
    cout << odd_str << endl;
    
    // Testing a multi-word string
    char multi_word_str[] = "I love to code";
    cout << "\nMulti-word c-string before reversal:" << endl;
    cout << multi_word_str << endl;
    
    reverse(&multi_word_str[0], &multi_word_str[13]);
    
    cout << "\nMulti-word c-string after reversal:" << endl;
    cout << multi_word_str << endl;
    
    // Delete array
    delete[] names;
    return 0;
}

void reverse(char* front, char* rear)
{
    char temp = *front;
    
    // While memory address of front is less than
    // memory address of rear, swap front and rear
    while (front <= rear) {
        temp = *front;
        *front = *rear;
        *rear = temp;
        front++;
        rear--;
    }
    
    cout << endl; // Add new line
}

string* addEntry(string* dynamicArray, int& size, string newEntry)
{
    string *newArray = new string[size + 1];
    
    for (int i = 0; i < size; i++)
    {
        newArray[i] = dynamicArray[i];
    }
    
    newArray[size] = newEntry;
    size++;
    delete[] dynamicArray;
    
    return newArray;
}

string* deleteEntry(string* dynamicArray, int& size, string entryToDelete)
{
    bool foundEntryToDelete = false; // assume not found
    
    for (int i = 0; i < size; i++) {
        if (dynamicArray[i] == entryToDelete) {
            foundEntryToDelete = true;
            break;
        }
    }
    
    
    if (foundEntryToDelete)
    {
        string *newArray = new string[size - 1];
        int count = 0;
        
        for (int i = 0; i < size; i++) {
            if (dynamicArray[i] != entryToDelete) {
                newArray[count] = dynamicArray[i];
                count++;
            }
        }
        
        size--;
        delete[] dynamicArray;
        return newArray;
    }
    
    return dynamicArray;

}

void print(const string* dynamicArray, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << ": " << dynamicArray[i] << endl;
    }
    
    cout << endl; // Add new line
}
