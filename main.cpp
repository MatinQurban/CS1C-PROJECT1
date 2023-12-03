#include "Shelf.h"
#include "Disk.h"
#include "Movie.h"
#include "Game.h"
#include "Customer.h"
#include "Transaction.h"
using namespace std;

int main()
{
    Movie *movie = new Movie();
    vector<Movie *> movies;

    movie->createListOfSellableItems("inputMovies.txt", movies);

    Game *game = new Game();
    vector<Game> games; // Changed vector type to Game

    game->createListOfSellableItems("inputGames.txt", games); // Passed vector of Game objects

    ifstream previousTransactions;
	inFile.open("Store_Transactions.txt");

    string firstName;
    string lastName;
    long phoneNumber;
    double budget;

    cout << "Welcome!" << endl;
    cout << "\nEnter first name: ";
    getline(cin, firstName);
    cin.ignore(1000, '\n');

    cout << "\nEnter last name: ";
    getline(cin, lastName);
    cin.ignore(1000, '\n');

    cout << "\nEnter phone number: ";
    cin >> phoneNumber;
    cin.ignore(1000, '\n');

    cout << "\nWhat is your budget?: ";
    cin >> budget;

    // build customerObject(firstName, lastName, phoneNumber, budget)

    ofstream transactionFile;
    transactionFile.open("Store_Transactions.txt");

    bool valid = false;

    do
    {
        while (!valid)
        {
            int input; // Declare the variable "input"

            cout << "\n1 - Check Stock" << endl;
            cout << "2 – Buy Game" << endl;
            cout << "3 – Buy Movie" << endl;
            cout << "4 – Show Transaction History" << endl;
            cout << "0 - Exit" << endl;
            cout << "Enter selection: ";

            if (!(cin >> input))
            {
                cout << "\n**** Please input a number between 0 and 4 ****" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "\n";
            }
            else
            {
                valid = true;
            }
        }
        valid = false;

        bool switchValid = false;

        int input; // Declare the variable "input"

        cout << "\n1 - Check Stock" << endl;
        cout << "2 – Buy Game" << endl;
        cout << "3 – Buy Movie" << endl;
        cout << "4 – Show Transaction History" << endl;
        cout << "0 - Exit" << endl;
        cout << "Enter selection: ";

        if (!(cin >> input))
        {
            cout << "\n**** Please input a number between 0 and 4 ****" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\n";
        }
        else
        {
            switch (input)
            {
            case 1:
            {
                string diskName;
                cout << "What is the title of the game or movie you are looking for?";
                getline(1000, diskName)
                if (checkStock(diskName)) {
                    cout << "\n" << diskName << " is currently in stock!" << endl;
                }
                break;
            }
            case 2:
            {
                // Ask for title
                // if (Check stock)
                // if true, display information about game
                // if (Confirm purchase (ask if they want to buy for x amount of dollars))
                // if true, check if budget is >=
                // if true, subtract disk price from budget, remove the game from the store stock
                // Add this transaction to transaction history
                break;
            }
            case 3:
            {
                // Ask for title
                // if (Check stock)
                // if true, display information about movie
                // if (Confirm purchase (ask if they want to buy for x amount of dollars))
                // if true, check if budget is >=
                // if true, subtract disk price from budget, remove the movie from the store stock
                // Add this transaction to transaction history
                break;
            }
            case 4:
            {
                // Show Transaction History of the Customer
                break;
            }
            case 0:
            {
                while (!switchValid)
                {
                    char validateSelection;
                    cout << "\nAre you sure you want to exit? (Y/N)";
                    cin.get(validateSelection);
                    // Add code to handle the exit confirmation
                    break;
                }
            }
            default:
            {
                cout << "\n**** Invalid selection. Please try again ****" << endl;
                break;
            }
            }
        }
    case 1:
    {
        // Check stock
    }
    case 2:
    {
        // Ask for title
        // if (Check stock)
        // if true, display information about game
        // if (Confirm purchase (ask if they want to buy for x amount of dollars))
        // if true, check if budget is >=
        // if true, subtract disk price from budget, remove the game from the store stock
        // Add this transaction to transaction history
    }
    case 3:
        // Ask for title
        // if (Check stock)
        // if true, display information about movie
        // if (Confirm purchase (ask if they want to buy for x amount of dollars))
        // if true, check if budget is >=
        // if true, subtract disk price from budget, remove the movie from the store stock
        // Add this transaction to transaction history
    }
case 4:
{
    // Show Transaction History of the Customer
case 0:
{
    while (!switchValid)
    {
        char validateSelection;
        cout << "\nAre you sure you want to exit? (Y/N)" cin.get(validateSelection);
        cin.ignore(1000, '\n');
        validateSelection = toupper(validateSelection);
        if (validateSelection != 'Y' && validateSelection != 'N')
        {
            cout << "\n**** " << validateSelection << " is an invalid entry ****" << endl;
            cout << "**** Please input Y or N    ****" << endl;
            cin.clear();
        }
        else
        {
            if (validateSelection == 'Y')
            {
                cout << "\nExiting program!"

                    valid = false;
                switchValid = true;
            }
        }
    }
}
default:
{
    cout << "\n**** Please input a number between 0 and 4 ****" << endl;
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "\n";
}
}

    return 0;
}