#include <iostream>
#include <string>
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
    vector<string> movieTitles;

    movie->createListOfSellableItems("inputMovies.txt", movies);

    Game *game = new Game();
    vector<Game*> games; // Changed vector type to Game
    vector<string> gameTitles;

    game->createListOfSellableItems("inputGames.txt", games); // Passed vector of Game objects

    Shelf *shelf = new Shelf();
    vector<Disk*> disks;
    
    // add movies and games to disks vector, then pass to shelf
    for (int i = 0; i < movies.size(); i++)
    {
        disks.push_back(movies[i]);
    }

    for (int i = 0; i < games.size(); i++)
    {
        disks.push_back(games[i]);
    }

    for(int i = 0; i < disks.size(); i++)
    {
        shelf->addDisk(disks[i]);
    }
    
    string firstName;
    string lastName;
    string phoneNumber;
    double budget;

    cout << "Welcome to the store!" << endl;
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

    Customer Ignoctio = Customer(firstName, lastName, phoneNumber, budget);
    
    bool valid = false;
    int input; // Declare the variable "input"

    do
    {
        
        while (!valid)
        {

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

        // valid = false;

        bool switchValid = false;

        // int input; // Declare the variable "input"

        // cout << "\n1 - Check Stock" << endl;
        // cout << "2 – Buy Game" << endl;
        // cout << "3 – Buy Movie" << endl;
        // cout << "4 – Show Transaction History" << endl;
        // cout << "0 - Exit" << endl;
        // cout << "Enter selection: ";

        // if (!(cin >> input))
        // {
        //     cout << "\n**** Please input a number between 0 and 4 ****" << endl;
        //     cin.clear();
        //     cin.ignore(1000, '\n');
        //     cout << "\n";
        // }
        // else
        // {
        if (valid)
        {
            switch (input)
            {
                case 1:
                {
                    string diskName;
                    cout << "What is the title of the game or movie you are looking for?";
                    getline(cin, diskName);

                    if (shelf->checkStock(diskName)) 
                    {
                        cout << "\n" << diskName << " is currently in stock!" << endl;
                    }
                    else
                    {
                        cout << "\n" << diskName << " is not in stock!" << endl;
                        break;
                    }
                }

                case 2:
                {
                    switchValid = false;
                    string diskName;
                    
                    while (!switchValid)
                    {
                    cout << "What is the title of the game you are looking for?";
                    getline(cin, diskName);

                    if (shelf->checkStock(diskName)) 
                    {
                        cout << "\n" << diskName << " is currently in stock!" << endl;
                        switchValid = true;
                    }
                    else
                    {
                        cout << "\n" << diskName << " is not in stock!" << endl;
                    }
                    }

                    //need to add a checkout portion for if the game is in stock (switchValid = true)
                    //need to actually select the game from the shelf lol
                    //need to instantiate a register so customer can buy the game !
                    char validateSelection;
                    if(switchValid)
                    {
                        Disk* customerGame = shelf->getDisk(diskName);
                        cout << "Game Information:" << endl; //disk information
                        cout << "-----------------" << endl;
                        // "Title: "
                        // "Genre: "
                        // "Synopsis: "
                        // "Release Year: "
                        // "Rating: "
                        // "Price: "
                        // "Primary Console: "
                        // "Maximum Coop Count: "
                        customerGame->displayInfo();

                        do
                        {
                        cout << "Would you like to purchase this game? (Y/N)";
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
                            if (validateSelection == 'Y' && budget > customerGame->getPrice())
                            {
                                //convert this portion of code to a transaction using transaction class.
                                // Register* register = new Register();
                                // register->newTransaction(Ignoctio, customerGame);
                                
                                
                                cout << "You have bought " << game->getTitle() << endl;
                                budget = budget - customerGame->getPrice();
                                valid = false;
                                switchValid = true;
                                break;
                            }
                        }
                        } while (validateSelection != 'Y' && validateSelection != 'N');
                    }
                }

                case 3: 
                {
                    switchValid = false;
                    while (!switchValid)
                    {
                        string diskName;
                        cout << "Wha'\n' the title of the movie you are looking for?";
                        getline(1000, diskName);
                
                        if (checkStock(diskName)) 
                        {
                            cout << '\n' << diskName << " is currently in stock!" << endl;
                            switchValid = true;
                        }
                        else
                        {
                            cout << "\n" << diskName << " is not in stock!" << endl;
                        }
                    }
                
                    cout << "Movie Information:" << endl; //disk information
                    cout << "-----------------" << endl;
                    // "Title: "
                    // "Genre: "
                    // "Synopsis: "
                    // "Release Year: "
                    // "Rating: "
                    // "Price: "
                    // "Leading Actor: "
                    // "BluRay or DVD?: "
                    movie->displayInfo();
                
                    switchValid = false;
                
                    while (!switchValid)
                    {
                        char validateSelection;
                
                        cout << "\nAre you sure you want to exit? (Y/N)" ;
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
                                break;
                            }
                        }
                    
                    }
                }

                case 4:
                {
                    // Show Transaction History of the Customer
                    cout << "Transaction History: " << endl;
                    cout << "---------------------" << endl;
                    cout << "Customer Name: " << firstName << " " << lastName << endl;
                    cout << "Phone Number: " << phoneNumber << endl;
                    cout << "Budget: " << budget << endl;
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
                        validateSelection = toupper(validateSelection);
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
    } while (input != 0);
    
    // default:
    // {
    //     cout << "\n**** Please input a number between 0 and 4 ****" << endl;
    //     cin.clear();
    //     cin.ignore(1000, '\n');
    //     cout << "\n";
    // }

    return 0;
}