/*
 Author: Mila Hose
 Date: 06-08-2019
 
 CSCI 121 Project 02
 Simple BMR calculator
 
 NOTE:
 Although this program is a great
 candidate for Procedural programming,
 I did not abstract any of the logic
 into individual functions, since we
 have not yet covered functions in the
 textbook readings.
*/

#include <iostream>
using namespace std;

int main()
{
    // variable declarations
    char gender, try_again;
    bool new_calculation = true;
    double weight, height, bmr, chocolate_bar_calories;
    int age;
    
    cout << "Welcome to my BMR calculator.\n";
    
    while (new_calculation)
    {
        // Get gender
        cout << "Gender (M or F): ";
        cin >> gender;
        // Verify gender was entered correctly, keep prompting if not
        while (gender != 'M' && gender != 'm' && gender != 'F' && gender != 'f')
        {
            cout << "Wrong gender input. Please enter again. Gender (M or F): ";
            cin >> gender;
        }
        
        // Get weight
        cout << "Weight (in pounds): ";
        cin >> weight;
        // Get height
        cout << "Height (in inches): ";
        cin >> height;
        // Get age
        cout << "Age (in years): ";
        cin >> age;
        
        // Calculate results according to gender
        if (gender == 'M' || gender == 'm') // if male
        {
            bmr = 66 + (6.3 * weight) + (12.9 * height) - (6.8 * age); // Male BMR formula
            chocolate_bar_calories = bmr / 230;
            
            cout << "He needs " << bmr << " calories to maintain his weight.\n";
            cout << "That is about " << chocolate_bar_calories << " chocolate bar's calories.\n";
        }
        else // otherwise user is female
        {
            bmr = 655 + (4.3 * weight) + (4.7 * height) - (4.7 * age); // Female BMR formula
            chocolate_bar_calories = bmr / 230;
            
            cout << "She needs " << bmr << " calories to maintain her weight.\n";
            cout << "That is about " << chocolate_bar_calories << " chocolate bar's calories.\n";
        }
        
        // Prompt to do further calculations
        cout << "Do you want to do another calculation? (Y/N): ";
        cin >> try_again;
        
        if (try_again == 'Y' || try_again == 'y')
            new_calculation = true; // while loop flow starts again
        else // "No" response or invalid input; end loop
            new_calculation = false;
        
    }
    // End program
    cout << "Thanks for using my BMR calculator. Good bye!\n";
    
    return 0;
}
