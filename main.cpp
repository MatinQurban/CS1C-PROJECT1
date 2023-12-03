#include "Shelf.h"
#include "Disk.h"
#include "Movie.h"
#include "Game.h"
#include "Customer.h"
#include "Transaction.h"
#include "Register.h"
using namespace std;

int main()
{
    Movie *movie = new Movie();
    vector<Movie *> movies;

    movie->createListOfSellableItems("inputMovies.txt", movies);

    Game *game = new Game();
    vector<Game> games; // Changed vector type to Game

    game->createListOfSellableItems("inputGames.txt", games); // Passed vector of Game objects

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
                else
                {
                    cout << "\n" << diskName << " is not in stock!" << endl;
                }
                break;
            }
            case 2:
            {
                switchValid = false;
                while (!switchValid)
                {
                string diskName;
                cout << "What is the title of the game you are looking for?";
                getline(1000, diskName)
                if (checkStock(diskName)) {
                    cout << "\n" << diskName << " is currently in stock!" << endl;
                    switchValid = true;
                }
                else
                {
                    cout << "\n" << diskName << " is not in stock!" << endl;
                }
                }
                cout << //disk information
                switchValid = false;
                while (!switchValid)
            {
                char validateSelection;
                cout << "\nAre you sure you want to exit? (Y/N)";
                cin.get(validateSelection);
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
                    if (validateSelection == 'Y' && budget > price)
                    {
                        cout << "You have bought " << diskName << endl;
                        budget = budget - price;
                        valid = false;
                        switchValid = true;
                    }
                }
            }
                break;
        }
            case 3: {
                switchValid = false;
                while (!switchValid)
                {
                string diskName;
                cout << "What is the title of the movie you are looking for?";
                getline(1000, diskName)
                if (checkStock(diskName)) {
                    cout << "\n" << diskName << " is currently in stock!" << endl;
                    switchValid = true;
                }
                else
                {
                    cout << "\n" << diskName << " is not in stock!" << endl;
                }
                }
                cout << //disk information
                switchValid = false;
                while (!switchValid)
            {
                char validateSelection;
                cout << "\nAre you sure you want to exit? (Y/N)" 
                cin.get(validateSelection);
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
                    if (validateSelection == 'Y' && budget > price)
                    {
                        cout << "You have bought " << diskName << endl;
                        budget = budget - price;
                        valid = false;
                        switchValid = true;
                    }
                }
            }
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
default:
{
    cout << "\n**** Please input a number between 0 and 4 ****" << endl;
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "\n";
}

    return 0;
}