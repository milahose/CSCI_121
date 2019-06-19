/*
 Author: Mila Hose
 Date: 06-18-2019
 
 CSCI 121 Project 03
 Simple game of "23"
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
    char play_again_response;
    string sticks_picked_msg;
    bool user_wants_to_play_again = true;
    int player_choice, computer_choice, sticks_left;
    
    while (user_wants_to_play_again)
    {
        sticks_left = 23;
        cout << "Let's play a game of \"23\"!\n";
        
        while (sticks_left > 0)
        {
            // set first-turn message
            if (sticks_left == 23)
                sticks_picked_msg = "Enter the number of sticks you wish to pick: ";
            else
                sticks_picked_msg = "Your turn. Enter the number of sticks you wish to pick: ";
            
            
            cout << sticks_picked_msg;
            cin >> player_choice;
            
            // invalid choice
            while (player_choice <= 0 || player_choice > 3)
            {
                cout << "Wrong number of sticks. Please pick 1, 2, or 3 sticks: ";
                cin >> player_choice;
            }
            
            
            sticks_left -= player_choice;
            cout << "You picked " << player_choice << " stick(s). " << sticks_left << " left.\n";
            
            // Computer choice operations
            if (sticks_left > 4)
            {
                computer_choice = 4 - player_choice;
                sticks_left -= computer_choice;
                cout << "Computer picked " << computer_choice << " stick(s). " << sticks_left << " left.\n";
            }
            else if (sticks_left >= 2 && sticks_left <= 4)
            {
                computer_choice = sticks_left - (sticks_left - 1);
                sticks_left -= computer_choice;
                cout << "Computer picked " << computer_choice << " stick. " << sticks_left << " left.\n";
            }
            else if (sticks_left == 1) // computer wins
            {
                cout << "The computer picked the last stick.\n";
                cout << "You beat the computer!\n";
                sticks_left--;
            }
            else if (sticks_left == 0) // player wins
            {
                cout << "You picked the last stick.\n";
                cout << "Sorry, the computer beat you!\n";
            }
        }
        
        
        cout << "Do you want to play another game? <Y/N>: ";
        cin >> play_again_response;
        
        
        if (play_again_response == 'Y' || play_again_response == 'y')
            user_wants_to_play_again = true;
        else
            user_wants_to_play_again = false;
    }
    
    cout << "Thanks for playing! Goodbye.";
    return 0;
}
