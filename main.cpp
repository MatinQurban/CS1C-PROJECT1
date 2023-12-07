#include <iostream>
#include <string>

#include "Shelf.h" // Also includes Disk.h, Register.h, TransactionInfo.h, Customer.h
#include "Movie.h"
#include "Game.h"

using namespace std;

int main()
{
    Register* register1 = new Register();
    register1->populateTransactions(); // Loads the transaction history from the file
    register1->populateCustomers(); // Loads the customer information from the file


    Movie *movie = new Movie();
    vector<Movie *> movies; // vector for total inventory, regardless of whether it's purchased or not
    // vector<Movie *> availableMovies; // vector for customer facing inventory, still need to populate/implement. Will be changed based on what has been purchased.
    // realize we might no longer need the 'available' vectors, since we can just check the num stock of a disk during checkStock() function... DUHHHHH lol

    movie->createListOfSellableItems("inputMovies.txt", movies); // Populates both total inventory ~~~and customer facing inventory~~~ <---scratch for now

    Game *game = new Game();
    vector<Game*> games; // Changed vector type to Game
    // vector<Game*> availableGames; // vector for customer facing inventory, still need to populate/implement. Will be changed based on what has been purchased.

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
    register1->addCustomer(Ignoctio);
    
    bool valid = false;
    int input; // Declare the variable "input"
    string diskType;
    string diskName;
    char validateSelection;

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
                    diskType = "Game";
                    switchValid = false;
                    
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
                            if (validateSelection == 'Y' && budget >= customerGame->getPrice())
                            {
                                //convert this portion of code to a transaction using transaction class.
                                //will need to overload new transaction function to take disk
                                register1->newTransaction(customerGame, diskType, Ignoctio);
                                

                                cout << "You have bought " << customerGame->getTitle() << endl;
                                
                                budget = budget - customerGame->getPrice();
                                //also need to clear game from shelf, will need to remove from availableGames vector instead of total stock vector
                                //can use itemPurchased function to decrement stock
                                for(int i = 0; i < games.size(); i++)
                                {
                                    if(games[i] == customerGame)
                                    {
                                        games[i]->itemPurchased();
                                    }
                                }

                                valid = false;
                                switchValid = true;
                                break;
                            }
                        }
                        } while (validateSelection != 'Y' && validateSelection != 'N');
                    }
                    // potential stuck point here, if the customer doesn't have enough money, they can't buy the game.
                    // also if the game is not in stock, they can't buy the game.
                    // there is no break statement here, so will it loop back to the beginning of the switch statement(?)
                }

                case 3: 
                {
                    diskType = "Movie";
                    switchValid = false;
                    
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
                    if(switchValid)
                    {
                        Disk* customerMovie = shelf->getDisk(diskName);
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
                        customerMovie->displayInfo();

                        do
                        {
                        cout << "Would you like to purchase this movie? (Y/N)";
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
                            if (validateSelection == 'Y' && budget >= customerMovie->getPrice())
                            {
                                //convert this portion of code to a transaction using transaction class.
                                //will need to overload new transaction function to take disk
                                register1->newTransaction(customerMovie, diskType, Ignoctio);
                                
                                
                                cout << "You have bought " << customerMovie->getTitle() << endl;
                                
                                budget = budget - customerMovie->getPrice();
                                valid = false;
                                switchValid = true; 
                                //also need to clear movie from shelf; will decrement stock by 1
                                for(int i = 0; i < movies.size(); i++)
                                {
                                    if(movies[i] == customerMovie)
                                    {
                                        movies[i]->itemPurchased();
                                    }
                                }
                                
                                break;
                            }
                        }
                        } while (validateSelection != 'Y' && validateSelection != 'N');
                    }
                }

                case 4:
                {
                    // Show Transaction History of the Customer
                    // Would you like to see history of current customer or 
                    // would you like to look up a customer by phone number?
                    
                    cout << "Would you like to" << endl;
                    cout << "*** 1. Search for a customer" << endl;
                    cout << "*** 2. View current customer's history" << endl;
                    cout << "*** 0. Exit" << endl;
                    cout << "Enter selection: ";
                    
                    vector<Transaction_Info*> customerTransactions;

                    do
                    {
                        cin.get(validateSelection);
                        cin.ignore(1000, '\n');
                
                        validateSelection = toupper(validateSelection);

                        if (validateSelection != '0' && validateSelection != '1' && validateSelection != '2')
                        {
                            cout << "\n**** " << validateSelection << " is an invalid entry ****" << endl;
                            cout << "**** Please input an integer 0-2 ****" << endl;
                            cin.clear();
                        }
                        else 
                        {
                            switch (validateSelection)
                            {
                                case '1':
                                {
                                    // Search for a customer
                                    cout << "Enter the phone number of the customer you would like to search for: ";
                                    cin >> phoneNumber;
                                    cin.ignore(1000, '\n');

                                    // Search for the customer in the transaction history
                                    customerTransactions = register1->findTransaction(phoneNumber, "All");

                                    register1->displayTransactionsforCustomer(customerTransactions);

                                    break;
                                }

                                case '2':
                                {
                                    // View current customer's history by phone number
                                    // Simply display all the transactions that have the same phone number as the current customer
                                    

                                    // Search for the customer in the transaction history
                                    customerTransactions = register1->findTransaction(phoneNumber, "All");
                                    
                                   
                                    register1->displayTransactionsforCustomer(customerTransactions);

                                    break;
                                }

                                case '0':
                                {
                                    while (!switchValid)
                                    {
                                        cout << "\nAre you sure you want to exit? (Y/N)";
                                        cin.get(validateSelection);
                                        // Add code to handle the exit confirmation
                                        validateSelection = toupper(validateSelection);

                                        if (validateSelection != 'Y' && validateSelection != 'N')
                                        {
                                            cout << "\n**** " << validateSelection << " is an invalid entry ****" << endl;
                                            cout << "**** Please input Y or N  ****" << endl;
                                            cin.clear();
                                        }
                                        else
                                        {
                                            if (validateSelection == 'Y')
                                            {
                                                input = 0;
                                                switchValid = true;
                                            }
                                        }
                                        
                                        break;
                                    }
                                }
                            }
                        }
                    } while (validateSelection != '0' && validateSelection != '1' && validateSelection != '2');

                    cout << "Transaction History: " << endl;
                    cout << "---------------------" << endl;
                    cout << "Customer Name: " << firstName << " " << lastName << endl;
                    cout << "Phone Number: " << phoneNumber << endl;
                    cout << "Budget: " << budget << endl;

                    cout << "";
                    break;
                }

                case 0:
                {
                    while (!switchValid)
                    {
                        cout << "\nAre you sure you want to exit? (Y/N)";
                        cin.get(validateSelection);
                        // Add code to handle the exit confirmation
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
                                input = 0;
                                switchValid = true;
                            }
                        }
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