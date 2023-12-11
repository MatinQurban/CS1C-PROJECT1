#include "Shelf.h" // Also includes Disk.h, Register.h, TransactionInfo.h, Customer.h
#include "Movie.h"
#include "Game.h"
using namespace std;

int main()
{
    Register* register1 = new Register();
    // displayTransaction(register1->allTransactions[1]); // Testing to see if we read from files correctly
    // register1->allCustomers[1]->displayCustomerInfo(); // Testing to see if we read from files correctly

    Movie *movie = new Movie();
    vector<Movie*> movies; 
    
    movie->createListOfSellableItems("inputMovies.txt", movies); // Passed vector of Movie objects

    Game *game = new Game();
    vector<Game*> games; 

    game->createListOfSellableItems("inputGames.txt", games); // Passed vector of Game objects

    Shelf *shelf = new Shelf();
    vector<Disk*> disks; // vector for total inventory, regardless of whether it's in stock or not

    // add movies and games to disks vector, then pass to shelf
    
    cout << "Movies: " << movies.size() << endl;
    
    for (int i = 0; i < movies.size(); i++)
    {
        // cout << "Movie " << i + 1 << ": " << movies[i]->getTitle() << endl;
        disks.push_back(movies[i]);
    }

    cout << "Games: " << games.size() << endl;
    
    for (int i = 0; i < games.size(); i++)
    {
        // cout << "Game " << i + 1 << ": " << games[i]->getTitle() << endl;
        disks.push_back(games[i]);
    }

    
    for(int i = 0; i < disks.size(); i++)
    {
        shelf->addDisk(disks[i]);
    }
    
    cout << "Total Inventory: " << disks.size() << " Disks" << endl;

    // cout << "Size of transactions: " << register1->allTransactions.size() << endl;
    
    string firstName;
    string lastName;
    string phoneNumber;
    double budget;

    cout << "\nWelcome to the store!" << endl;
    cout << "\nEnter first name: ";
    getline(cin, firstName);

    cout << "\nEnter last name: ";
    getline(cin, lastName);

    cout << "\nEnter phone number: ";
    getline(cin, phoneNumber);

    cout << "\nWhat is your budget?: ";
    cin >> budget;
    cin.ignore(1000, '\n');

    Customer Ignoctio = Customer(firstName, lastName, phoneNumber, budget);
    register1->addCustomer(Ignoctio);
    
    bool valid = false;
    int input; 
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
                cin.ignore(1000, '\n');
                valid = true;
            }
        }

        bool switchValid = false;
            
        if (valid)
        {
            cin.clear();
            
            valid = false;
            
            switch (input)
            {
                case 1:
                {
                    cout << "\nWhat is the title of the game or movie you are looking for?" << endl;
                    getline(cin, diskName);

                    if (shelf->checkStock(diskName)) 
                    {
                        cout << "\nFound entry for: " << diskName << ". Press Enter key to continue." << endl;
                        switchValid = true;
                    }
                    else
                    {
                        cout << "\nDid not find entry for: " << diskName << ". Press Enter key to continue." << endl;
                    }
                    
                    cin.clear();
                    
                    break;
                }

                case 2:
                {
                    diskType = "Game";  
                    switchValid = false;
                    
                    while (!switchValid)
                    {
                        cout << "What is the title of the game you are looking for?" << endl;
                        getline(cin, diskName);
                        cin.clear();

                        if (shelf->checkStock(diskName)) 
                        {
                            cout << "Found entry for: " << diskName << "." << endl;
                            switchValid = true;
                        }
                        else
                        {
                            cout << "Did not find entry for: " << diskName << "." << endl;
                            switchValid = false;
                        }
                    }

                    //checkout portion for if the game is in stock

                    //select the game from the shelf
                    Disk* customerGame = shelf->getDisk(diskName);
                    
                    cout << "Game Information:" << endl; //disk information
                    cout << "-----------------" << endl;
                    customerGame->displayInfo();
                    
                    if (budget >= customerGame->getPrice())
                    {
                        //convert this portion of code to a transaction using transaction class.
                        //will need to overload new transaction function to take disk
                        register1->newTransaction(customerGame, diskType, Ignoctio);

                        cout << "You have bought " << customerGame->getTitle() << endl;
                        
                        Ignoctio.setBudget(budget - customerGame->getPrice());
                        
                        //also need to clear game from shelf 
                        //use itemPurchased function to decrement stock
                        for (int i = 0; i < games.size(); i++)
                        {
                            if (games[i] == customerGame)
                            {
                                games[i]->itemPurchased();
                            }
                        }

                        switchValid = true;
                    }
                    else
                    {
                        cout << "You don't have enough money! ($" << Ignoctio.getBudget() << ")" << endl;
                        break;
                    }
                    break;
                }
                case 3: 
                {
                    diskType = "Movie";  
                    switchValid = false;
                    
                    while (!switchValid)
                    {
                        cout << "What is the title of the movie you are looking for?" << endl;
                        getline(cin, diskName);
                        cin.clear();

                        if (shelf->checkStock(diskName)) 
                        {
                            cout << "Found entry for: " << diskName << "." << endl;
                            switchValid = true;
                        }
                        else
                        {
                            cout << "Did not find entry for: " << diskName << ". Press Enter key to continue." << endl;
                            switchValid = false;
                        }
                    }

                    // checkout portion for if the disk is in stock

                    // select the disk from the shelf 
                    Disk* customerMovie = shelf->getDisk(diskName);
                    
                    cout << "Movie Information:" << endl; //disk information
                    cout << "-----------------" << endl;
                    customerMovie->displayInfo();
                    
                    if (budget >= customerMovie->getPrice())
                    {
                        //convert customer selection to a transaction using transaction class.
                        register1->newTransaction(customerMovie, diskType, Ignoctio);
                        
                        cout << "Transaction Details: " << endl << endl;
                        cout << "You have bought " << customerMovie->getTitle() << endl;
                        
                        Ignoctio.setBudget(budget - customerMovie->getPrice());
                        
                        //also need to clear disk from shelf
                        //use itemPurchased function to decrement stock
                        for (int i = 0; i < games.size(); i++)
                        {
                            if (movies[i] == customerMovie)
                            {
                                movies[i]->itemPurchased();
                            }
                        }

                        switchValid = true;
                    }
                    else
                    {
                        cout << "You don't have enough money! ($" << Ignoctio.getBudget() << ")" << endl;
                        break;
                    }
                    break;
                }
                case 4:
                {
                    register1->displayTransactionsforCustomer(phoneNumber);
                    
                    break;
                }
                case 0:
                {                
                    delete register1;

                    return 0;
                }
                
                default:
                {
                    cout << "\n**** Invalid selection. Please try again ****" << endl;
                    break;
                }
            }
        }
    } while (input != 0);

    return 0;
}