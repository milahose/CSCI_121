/*
 Author: Mila Hose
 Date: 07-11-2019
 
 CSCI 121 Project 07
 Testing Array Functions
*/

#include <iostream>
using namespace std;


// pre-condition: program has started
// post-condition: displays a menu of options from which users can choose one
void menu();

// pre-condition: The arr has actual size that is greater than or equal to size
// post-condition: arr[0], ..., arr[size-1] is filled from keyboard
void fill_array(int arr[], int size);

// pre-condition: arr has given size
// post-condition: The index of first occurrence of key in arr is returned.
// If the key cannot be found in arr, -1 is returned
int linear_search(int arr[], int size, int key);

// post-condition: interchanges the values of v1 and v2
void swap_values(int& v1, int& v2);

// pre-condition: referenced array elements have values
// post-condition: returns the index i such that arr[i] is the smallest value
// arr[startIndex], arr[startIndex + 1], ... arr[size - 1]
int index_of_smallest(const int arr[], int startIndex, int size);

// pre-condition: arr has given size
// post-condition: the elements in arr are rearranged from least to largest
void select_sort(int arr[], int size);

// pre-condition: The arr has actual size that is greater than or equal to size
// post-condition: arr[0], ..., arr[size-1] is printed to screen with 5 elements per line
void print_array(int arr[], int size);

// pre-condition: arr has given size
// post-condition: the elements in arr are rearranged from least to largest
void insert_sort(int arr[], int size);

// pre-condition: arr has given size
// post-condition: the elements in arr are rearranged from least to largest
void bubble_sort(int arr[], int size);


int main() {
    int choice;
    int a[9];
    
    do {
        menu();
        cout << "\n\n\tEnter your choice: ";
        cin >> choice;
        
        switch(choice)
        {
            case 1:
            {
                fill_array(a, 9);
                cout << "\n\tEnter the key you want to search: ";
                int key;

                for (;;) {
                    if (cin >> key) {
                        break; // success -> bail out of loop
                    } else {
                        cerr << "\n\tInvalid input! Please enter a number: ";
                        cin.clear(); // reset state
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // consume wrong input
                    }
                }
                
                int index = linear_search(a, 9, key);
                if(index == -1)
                    cout << "\n\tThe key " << key << " is not in the array.\n";
                else
                    cout << "\n\tThe key " << key << " is the #" << (index + 1) << " element in the array.\n";
                    break;
            }
            case 2:
            {
                fill_array(a, 9);
                select_sort(a, 9);
                cout << "\n\tAfter sort, the array is:\n\n\t\t";
                print_array(a, 9);
                break;
            }
            case 3:
            {
                fill_array(a, 9);
                insert_sort(a, 9);
                cout << "\n\tAfter sort, the array is:\n\n\t\t";
                print_array(a, 9);
                break;
            }
            case 4:
            {
                fill_array(a, 9);
                bubble_sort(a, 9);
                cout << "\n\tAfter sort, the array is:\n\n\t\t";
                print_array(a, 9);
                break;
            }
            case 5:
            {
                cout << "\n\tThank you for using the array functions!\n";
                break;
            }
            default:
            {
                cout << "\n\tWrong choice. Please choose from menu: ";
                break;
            }
        }
    } while(choice != 5);
    
    return 0;
}

void menu()
{
    cout << "\n\t***************************************************";
    cout << "\n\t*                   Test Menu                     *";
    cout << "\n\t* 1. Linear Search                                *";
    cout << "\n\t* 2. Selection Sort                               *";
    cout << "\n\t* 3. Insertion Sort                               *";
    cout << "\n\t* 4. Bubble Sort                                  *";
    cout << "\n\t* 5. Quit                                         *";
    cout << "\n\t***************************************************";
}

void fill_array(int arr[], int size)
{
    int user_choice, count = 0;
    
    while (size > 0)
    {
        cout << "\n\tEnter array value " << count + 1 << ": ";
        
        for (;;) {
            if (cin >> user_choice) {
                break; // success -> bail out of loop
            } else {
                cerr << "\n\tInvalid input! Please enter a number: ";
                cin.clear(); // reset state
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // consume wrong input
            }
        }

        arr[count] = user_choice;
        count++;
        size--;
    }
}

int linear_search(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
            return i;
    }
    
    return -1;
}

void swap_values(int& v1, int& v2)
{
    int temp = v1;
    v1 = v2;
    v2 = temp;
}

int index_of_smallest(const int arr[], int startIndex, int size)
{
    int min = arr[startIndex], index_of_min = startIndex;
    
    for (int i = startIndex + 1; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            index_of_min = i;
        }
    }
    
    return index_of_min;
}

void select_sort(int arr[], int size)
{
    int index_of_next_smallest;
    
    for (int i = 0; i < size - 1; i++)
    {
        index_of_next_smallest = index_of_smallest(arr, i, size);
        swap_values(arr[i], arr[index_of_next_smallest]);
    }
}

void print_array(int arr[], int size)
{
    int count = 1;
    
    for (int i = 0; i < size; i++)
    {
        if (count > 5)
        {
            count = 1;
            cout << "\n\t\t ";
        }
        
        if (count == 1 && i == 0)
            cout << "{" << arr[i] << ", ";
        else if (i == size - 1)
            cout << arr[i] << "}";
        else
            cout << arr[i] << ", ";
        
        count++;
    }
    
    cout << "\n\t";
}

void insert_sort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int current = arr[i];
        int last_idx = i - 1;
        
        while (last_idx >= 0 && arr[last_idx] > current)
        {
            arr[last_idx + 1] = arr[last_idx];
            last_idx -= 1;
        }
        
        arr[last_idx + 1] = current;
    }
}

void bubble_sort(int arr[], int size)
{
    for (int i = size - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
                swap_values(arr[j+1], arr[j]);
        }
    }
}
