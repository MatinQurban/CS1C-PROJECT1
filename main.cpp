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
    vector<Movie*> movies; // vector for total inventory, regardless of whether it's purchased or not
    // vector<Movie *> availableMovies; // vector for customer facing inventory, still need to populate/implement. Will be changed based on what has been purchased.
    // realize we might no longer need the 'available' vectors, since we can just check the num stock of a disk during checkStock() function... DUHHHHH lol

    movie->createListOfSellableItems("inputMovies.txt", movies); // Populates both total inventory ~~~and customer facing inventory~~~ <---scratch for now

    Game *game = new Game();
    vector<Game*> games; // Changed vector type to Game
    // vector<Game*> availableGames; // vector for customer facing inventory, still need to populate/implement. Will be changed based on what has been purchased.

    game->createListOfSellableItems("inputGames.txt", games); // Passed vector of Game objects

    Shelf *shelf = new Shelf();
    vector<Disk*> disks;
    
    // // Testing to see if we read from files correctly: 
    // // Access Movie object from movies vector
    // cout << "First Movie: " << endl;
    // movies[0]->displayInfo();
    // cout << "Second Movie: " << endl;
    // movies[1]->displayInfo();

    // // Access Game object from games vector
    // cout << "First Game: " << endl;
    // games[0]->displayInfo();

    // add movies and games to disks vector, then pass to shelf
    cout << "Size of movies: " << movies.size() << endl;
    for (int i = 0; i < movies.size(); i++)
    {
        disks.push_back(movies[i]);
    }

    cout << "Size of games: " << games.size() << endl;
    for (int i = 0; i < games.size(); i++)
    {
        disks.push_back(games[i]);
    }

    cout << "Size of disks: " << disks.size() << endl;
    for(int i = 0; i < disks.size(); i++)
    {
        shelf->addDisk(disks[i]);
    }

    cout << "Size of transactions: " << register1->allTransactions.size() << endl;
    
    string firstName;
    string lastName;
    string phoneNumber;
    double budget;

    cout << "Welcome to the store!" << endl;
    cout << "\nEnter first name: ";
    getline(cin, firstName);

    cout << "\nEnter last name: ";
    getline(cin, lastName);

    cout << "\nEnter phone number: ";
    cin >> phoneNumber;
    cin.ignore(1000, '\n');

    cout << "\nWhat is your budget?: ";
    cin >> budget;
    cin.ignore(1000, '\n');

    Customer Ignoctio = Customer(firstName, lastName, phoneNumber, budget);
    register1->addCustomer(Ignoctio);

    //"Hello returning customer!" Functionality
    
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
                cin.ignore(1000, '\n');
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
            cin.clear();
            
            switch (input)
            {
                case 1:
                {
                    cout << "What is the title of the game or movie you are looking for?\n";
                    getline(cin, diskName);

                    if (shelf->checkStock(diskName)) 
                    {
                        cout << "\n\nFound entry for: " << diskName << ". Press Enter key to continue." << endl;
                        switchValid = true;
                    }
                    else
                    {
                        cout << "\nDid not find entry for: " << diskName << ". Press Enter key to continue." << endl;
                    }
                    
                    cin.clear();
                    
                    valid = false;
                    break;
                }

                case 2:
                {
                    diskType = "Game";  
                    switchValid = false;
                    
                    while (!switchValid)
                    {
                        cout << "\nWhat is the title of the game you are looking for?\n";
                        getline(cin, diskName);
                        cin.clear();

                        if (shelf->checkStock(diskName)) 
                        {
                            cout << "\nFound entry for: " << diskName << "." << endl;
                            switchValid = true;
                        }
                        else
                        {
                            cout << "\nDid not find entry for: " << diskName << ". Press Enter key to continue." << endl;
                            break;
                        }
                    }

                    //need to add a checkout portion for if the game is in stock (switchValid = true)
                    //need to actually select the game from the shelf lol
                    //need to instantiate a register so customer can buy the game !


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
                        
                        if (budget >= customerGame->getPrice())
                        {
                            //convert this portion of code to a transaction using transaction class.
                            //will need to overload new transaction function to take disk
                            register1->newTransaction(customerGame, diskType, Ignoctio);
                            
                            cout << "Transaction Details: " << endl << endl;
                            cout << "\nYou have bought " << customerGame->getTitle() << endl;
                            
                            
                            budget = budget - customerGame->getPrice();
                            //also need to clear game from shelf, will need to remove from availableGames vector instead of total stock vector
                            //can use itemPurchased function to decrement stock
                            for (int i = 0; i < games.size(); i++)
                            {
                                if (games[i] == customerGame)
                                {
                                    games[i]->itemPurchased();
                                }
                            }

                            valid = false;
                            switchValid = true;
                        }
                        else
                        {
                            cout << "You don't have enough money! ($" << Ignoctio.getBudget() << ")" << endl;
                            switchValid = false;
                            
                        }
                    break;
                }
                case 3: 
                {
                    diskType = "Movie";
                    switchValid = false;
                    
                    while (!switchValid)
                    {
                        cout << "\nWhat is the title of the movie you are looking for?\n";
                        getline(cin, diskName);
                        cin.clear();

                        if (shelf->checkStock(diskName)) 
                        {
                            cout << "\n" << diskName << " is currently in stock!" << endl << endl;
                            switchValid = true;
                        }
                        else
                        {
                            cout << "\n" << diskName << " is not in stock!" << endl << endl;
                        }
                    }

                    //need to add a checkout portion for if the game is in stock (switchValid = true)
                    //need to actually select the game from the shelf lol
                    //need to instantiate a register so customer can buy the game !
                    if (switchValid)
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

                        if (budget >= customerMovie->getPrice())
                        {
                            //convert this portion of code to a transaction using transaction class.
                            //will need to overload new transaction function to take disk
                            register1->newTransaction(customerMovie, diskType, Ignoctio);   
                            cout << "\nYou have bought " << customerMovie->getTitle() << endl;
                                
                            budget = budget - customerMovie->getPrice();
                            valid = false;
                            switchValid = true; 
                                    
                            //also need to clear movie from shelf; will decrement stock by 1
                            for (int i = 0; i < movies.size(); i++)
                            {
                                if (movies[i] == customerMovie)
                                {
                                    movies[i]->itemPurchased();
                                }
                            }
                                
                        }
                        else
                        {
                            cout << "You don't have enough money!" << endl;
                            switchValid = true;
                            break;
                        }    
                    }
                    
                    break;
                }

                case 4:
                {
                    register1->displayTransactionsforCustomer(phoneNumber);
                    
                    valid = false;
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