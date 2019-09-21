/* Do Programming Project 2 on page 611. You may watch the video note for
 * Programming Project 1 on page 611 to get some idea. Then try to finish
 * independently by complete this sample file.
 *
 * Author: Mila Hose
 * Version: 09-08-2019
 *
 * CSCI 221 Project 02
 * Defining Classes
 *
 */

#include <iostream>
#include <cmath>
using namespace std;

class CDAccount
{
public:
    CDAccount();
    CDAccount(double new_balance, double new_interest_rate, int new_term);
    double get_initial_balance() const;
    double get_balance_at_maturity() const;
    double get_interest_rate() const;
    int get_term() const;
    void input(istream& in);
    void output(ostream& out);
    
private:
    int dollar;
    int cent;
    double interest_rate;
    int term; // months until maturity
};

// Display test menu
void menu();

int main()
{
    // You implement the test code here
    // You may watch the video note to get the idea
    // notice that user will only enter balance as a double value
    // You may implement it as a menu oriented testing program
    // which be able to test constructors, methods of CDAccount class
    int choice;
    double balance, interest;
    int term;
    CDAccount account;

    do
    {
        menu();
        cout << "\n\n\tPlease enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "\n\tCreating CD Account..." << endl;
                account.output(cout);
                break;
            case 2:
                cout << "\n\tPlease provide a space-delimited list for account balance, interest and term: ";
                cin >> balance >> interest >> term;
                account = CDAccount(balance, interest, term);
                account.output(cout);
                break;
            case 3:
                cout << "\n\tInitial balance will be 0, unless a balance was previously added using Option 2.\n";
                cout << "\n\tHere is the initial balance for the current CD Account: ";
                cout << "$" << account.get_initial_balance();
                cout << endl;
                break;
            case 4:
                cout << "\n\tInterest rate will be 0, unless a rate was previously added using Option 2.\n";
                cout << "\n\tHere is the interest rate for the current CD Account: ";
                cout << account.get_interest_rate() << "%";
                cout << endl;
                break;
            case 5:
                cout << "\n\tBalance at maturity will be 0, unless balance, rate & term were added using Option 2.\n";
                cout << "\n\tHere is the balance at maturity for the current CD Account: ";
                cout << "$" << account.get_balance_at_maturity();
                cout << endl;
                break;
            case 6:
                cout << "\n\tTerm will be 0, unless balance, rate & term were added using Option 2.\n";
                cout << "\n\tHere is the term for the current CD Account: ";
                cout << account.get_term() << " months";
                cout << endl;
                break;
            case 7:
                cout << "\n\tGoodbye!";
                break;
            default:
                cout << "\n\tWrong option. Please choose from menu.\n";
                break;
        }
        
    } while (choice != 7);
    
    return 0;
}

CDAccount::CDAccount() : // defaults to 0
    dollar(0), cent(0), interest_rate(0), term(0)
{}

CDAccount::CDAccount(double new_balance, double new_interest_rate, int new_term)
{
    if (new_balance < 0 || new_interest_rate < 0 || new_term < 0)
    {   // CD accounts can't have negative values
        cout << "\n\tIllegal values for balance, rate or term.\n";
        exit(1);
    }
    
    dollar = (int) new_balance;
    cent = (new_balance - dollar) * 100;
    interest_rate = new_interest_rate / 100.0;
    term = new_term;
}

double CDAccount::get_initial_balance() const
{
    return dollar + (cent / 100.0);
}

double CDAccount::get_balance_at_maturity() const
{   // interest rate taken from textbook
    double interest = get_initial_balance() * interest_rate * (term / 12.0);
    return get_initial_balance() + interest;
}

double CDAccount::get_interest_rate() const
{
    return interest_rate * 100;
}

int CDAccount::get_term() const
{
    return term;
}

void CDAccount::input(istream& in)
{
    double balance;
    in >> balance; // get initial balance from user
    
    // convert balance to dollars and cents since this is how balance stored
    dollar = (int) balance; // dollar is the interger part of balace
    cent = (balance - dollar) * 100; // cent is the fraction part * 100
    
    in >> interest_rate; // get interest rate from user
    in >> term; // get term from user
}

void CDAccount::output(ostream& out)
{
    out.setf(ios::fixed);
    out.setf(ios::showpoint);
    out.precision(2);
    
    out << "\n\tBalance: " << "$" << get_initial_balance() << endl;
    out << "\n\tInterest rate: " << get_interest_rate() << "%" << endl;
    out << "\n\tTerm: " << term << " months" << endl;
    out << "\n\tBalance at maturity: " << "$" << get_balance_at_maturity() << endl;
    out << endl;
}

void menu()
{
    cout << "\n\t***************************************************";
    cout << "\n\t*                   Test Menu                     *";
    cout << "\n\t*                                                 *";
    cout << "\n\t* 1. Create a new CD Account with defult values   *";
    cout << "\n\t* 2. Create a new CD Account w/ custom values     *";
    cout << "\n\t* 3. Get initial balance                          *";
    cout << "\n\t* 4. Get interest rate                            *";
    cout << "\n\t* 5. Get balance at maturity                      *";
    cout << "\n\t* 6. Get term                                     *";
    cout << "\n\t* 7. Quit                                         *";
    cout << "\n\t***************************************************";
}
