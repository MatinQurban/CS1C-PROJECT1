#include "Register.h"


Transaction_Info* parseTransaction(string transaction, int x)
{
    //string transaction will look like this: //DiskName //DiskType //Total //FirstName //LastName //Phone //
    /*
    DiskName: string
    DiskType: string
    Total: double
    FirstName: string
    LastName: string
    Phone: string
    */
    
    Transaction_Info *transactionData = new struct Transaction_Info;
    
    transactionData->diskName = transaction.substr(2, transaction.find(" //") - 2);
    
    transaction = transaction.substr(transaction.find(" //") + 1); //DiskType //Total //FirstName //LastName //Phone //
    transactionData->diskType = transaction.substr(2, transaction.find(" //") - 2);

    transaction = transaction.substr(transaction.find(" //") + 1); //Total //FirstName //LastName //Phone //
    transactionData->price = stod(transaction.substr(2, transaction.find(" //") - 2));

    transaction = transaction.substr(transaction.find(" //") + 1); //FirstName //LastName //Phone //
    transactionData->firstName = transaction.substr(2, transaction.find(" //") - 2);

    transaction = transaction.substr(transaction.find(" //") + 1); //LastName //Phone //
    transactionData->lastName = transaction.substr(2, transaction.find(" //") - 2);

    transaction = transaction.substr(transaction.find(" //") + 1); //Phone //
    transactionData->phoneNumber = transaction.substr(2, transaction.find(" //") - 2);

    return transactionData;
}

Customer* parseCustomer(string lineCustomerInfo)
{
    //string customer will look like this: //FirstName //LastName //Phone //
    /*
    FirstName: string
    LastName: string
    Phone: string
    */
    Customer* customerData = new Customer();
    string customerInfo = lineCustomerInfo;

    customerInfo = customerInfo.substr(2, customerInfo.find(" ") - 3); // FirstName
    customerData->setFirstName(customerInfo);
    
    customerInfo = lineCustomerInfo.substr(lineCustomerInfo.find(" ") + 1); //LastName //Phone //
    //                        customerInfo.substr(2, customerInfo.find(" ") - 3) ==> LastName
    customerData->setLastName(customerInfo.substr(2, customerInfo.find(" ") - 3));

    customerInfo = customerInfo.substr(customerInfo.find(" ") + 1); //Phone //
    customerData->setPhoneNumber(customerInfo.substr(2, customerInfo.find_last_of("//") - 4));

    return customerData;
}

Register::Register() 
{ 
    populateTransactions();
    populateCustomers();
}

Register::Register(vector<Transaction_Info *> Transactions, vector<Customer *> Customers)
{
    populateTransactions();
    populateCustomers();
    for(int i = 0; i < Transactions.size(); i++)
    {
        allTransactions.push_back(Transactions[i]);
    }
    for(int i = 0; i < Customers.size(); i++)
    {
        allCustomers.push_back(Customers[i]);
    }
}

Register::~Register() 
{ 
    dumpTransactions();
    // also need to delete all the pointers in the vector. Now what vector? you may ask, figure it out cuz idk rn either.
    for(int i = 0; i < allTransactions.size(); i++)
    {
        delete allTransactions[i];
    }
    allTransactions.clear();
}

void Register::newTransaction(const string& diskName, const string& diskType, const double& price, Customer& customer)
{
    Transaction_Info *Transaction_Info;
    Transaction_Info->diskName = diskName;
    Transaction_Info->diskType = diskType;
    Transaction_Info->price = price;
    Transaction_Info->firstName = customer.getFirstName();
    Transaction_Info->lastName = customer.getLastName();
    Transaction_Info->phoneNumber = customer.getPhoneNumber();

    populateTransactions();
    populateCustomers();
    allTransactions.push_back(Transaction_Info);
    customer.addTransaction(*Transaction_Info);
    dumpTransactions();
}

void Register::newTransaction(const Disk* disk, const string& diskType, Customer& customer)
{
    Transaction_Info *Transaction_Info = new struct Transaction_Info;
    Transaction_Info->diskName = disk->getTitle();
    Transaction_Info->diskType = diskType;
    Transaction_Info->price = disk->getPrice();
    Transaction_Info->firstName = customer.getFirstName();
    Transaction_Info->lastName = customer.getLastName();
    Transaction_Info->phoneNumber = customer.getPhoneNumber();

    populateTransactions();
    populateCustomers();
    allTransactions.push_back(Transaction_Info);
    customer.addTransaction(*Transaction_Info);
    cout << "Transaction Completed!" << endl;
    cout << "Transaction Details:" << endl;
    displayTransaction(Transaction_Info);
    dumpTransactions();
}

void Register::displayTransactionsforCustomer(vector<Transaction_Info*> customerTransactions)
{
    if (customerTransactions.size() == 0)
    {
        cout << "No transactions found for Customer." << endl;
        return;
    }
    else
    {
        int count = 0;
        // loop through customerTransactions<> vector and display each transaction. should be a function for that
        for(int i = 0; i < customerTransactions.size(); i++)
        {
            cout << "****** Transaction " << i+1 << " ******" << endl;
            displayTransaction(customerTransactions[i]);
            cout << endl;
            count++;
        }
        cout << "Total Transactions Found: " << count << endl;
    
        return;
    }
}

void Register::addCustomer(Customer& customer)
{
    //This function will add a customer to the allCustomers vector, but only if the customers phone number does not already exist in the vector.
    for (int i = 0; i < allCustomers.size(); i++)
    {
        if (allCustomers[i]->getPhoneNumber() == customer.getPhoneNumber())
        {
            cout << "Customer already exists in the system." << endl;
            return;
        }
    }
    allCustomers.push_back(&customer);
}
// This function will populate the allTransactions vector with the transactions from the transaction file.
void Register::populateTransactions()
{
    ifstream previousTransactions;
	previousTransactions.open("Store_Transactions.txt");

    string lineTransaction;
    int lineCount = 0;

    getline(previousTransactions, lineTransaction);
    if (!validateFile(lineTransaction, lineCount, "transactions"))
    {
        cout << "The transaction file is not in the correct format. Please check the file and try again." << endl;
        previousTransactions.close();
        
        return;
    }

    while (getline(previousTransactions, lineTransaction))
    { 
        if(lineTransaction == "") 
        {
            break;
        }

        lineCount++;
        
        if (validateFile(lineTransaction, lineCount, "transactions"))
        {
            Transaction_Info *formattedTransaction = parseTransaction(lineTransaction, 1);

            allTransactions.push_back(formattedTransaction);
        }

        if (previousTransactions.eof())
        {
            break;
        }
    }

    cout << "Transaction information transfer completed " << lineCount << " lines. Closing file." << endl;
    
    previousTransactions.close();

    return;
}


void Register::populateCustomers()
{
    ifstream customerList;
    customerList.open("Customer_List.txt");

    string lineCustomer;
    int lineCount = 0;

    getline(customerList, lineCustomer);
    if (!validateFile(lineCustomer, lineCount, "customers"))
    {
        cout << "The customer file is not in the correct format. Please check the file and try again." << endl;
        customerList.close();
        return;
    }
    
    while (getline(customerList, lineCustomer))
    { 
        if (lineCustomer == ""){break;}

        lineCount++;

        if (validateFile(lineCustomer, lineCount, "customers"))
        {
            Customer *formattedCustomer = parseCustomer(lineCustomer);

            allCustomers.push_back(formattedCustomer);
            allCustomers[lineCount - 1]->displayCustomerInfo();
        }

        if (customerList.eof())
        {
            break;
        }
    }

    cout << "Customer information transfer completed " << lineCount << " lines. Closing file." << endl;
    customerList.close();

    return;
}


// This function will be used to check if we are opening the right file in the correct format.
bool Register::validateFile(string line, int lineCount, string file)
{
    /*
    file: "transactions" or "customers"
    */

    string tempLine = line;
    string tryString;
    double tryDouble;
    
    if (lineCount == 0)
    {
        return line == "//DiskName //DiskType //Total //FirstName //LastName //Phone //" 
            || line == "//FirstName //LastName //Phone //";
    }

    //For the rest of the validation process, we will skip checking for strings, due to their nature of being able to contain any character.
    if (file == "transactions")
    {
        tempLine = line.substr(line.find(" //") + 1); //DiskType //Total //FirstName //LastName //Phone //
        tempLine = tempLine.substr(tempLine.find(" //") + 1); //Total //FirstName //LastName //Phone //

        tryString = tempLine.substr(2, tempLine.find(" //") - 2); //Total
        
        try 
        {
            stod(tryString);
        } 
        catch (const std::out_of_range&) 
        {
            cout << "Argument is out of range for a double" << endl;
            return false;
        }
        catch (const std::invalid_argument&) 
        {
            cout << "Total is not in the right format!\n" << "Line: " << lineCount << endl;
            return false;
        }
        
        return true;
    }
    else if (file != "customers")
    {
        cout << "File is not in the correct format. Please check the file and try again." << endl;
        return false;
    }
    return true;
}

// This function will append every transaction inside allTransactions into the transaction file, and then clear the vector.
void Register::dumpTransactions()
{
    // ofstream transactionFile;
    
    // transactionFile.open("Store_Transactions.txt", ios::app); // Open file in append mode
    
    // for (int i = 0; i < allTransactions.size(); i++) 
    // {
    //     string lineTotal = "//" + allTransactions[i]->diskName + " //" +
    //                               allTransactions[i]->diskType + " //" +
    //                               to_string(allTransactions[i]->price) + " //" +
    //                               allTransactions[i]->firstName + " //" +
    //                               allTransactions[i]->lastName + " //" +
    //                               allTransactions[i]->phoneNumber + " //";
        
    //     transactionFile << lineTotal << endl;
    // }

    // // Clear the vector after writing to the file
    // for (auto &transaction : allTransactions) 
    // {
    //     delete transaction;  // Deallocate memory since transactions are pointers
    // }

    // allTransactions.clear();
    // transactionFile.close();

    ofstream transactionFile;
    string lineTotal;
    //vector<Transaction_Info*> allTransactions;

    transactionFile.open("Store_Transactions.txt");

    vector<Transaction_Info*> allTransactions;
    
    for (int i = 0; i < allTransactions.size(); i++)
    {
        lineTotal = "";
        lineTotal += "//" + allTransactions[i]->diskName + " ";
        lineTotal += "//" + allTransactions[i]->diskType + " ";
        lineTotal += "//" + to_string(allTransactions[i]->price) + " ";
        lineTotal += "//" + allTransactions[i]->firstName + " ";
        lineTotal += "//" + allTransactions[i]->lastName + " ";
        lineTotal += "//" + allTransactions[i]->phoneNumber + " //";

        transactionFile << lineTotal << endl;
    }
    
    allTransactions.clear();

    transactionFile.close();
}

vector<Transaction_Info*> Register::findTransaction(const string& aPhoneNumber, const string& key) //Key: "All", "First", "Last", or name of game/movie
{
    vector<Transaction_Info*> foundTransactions;
    //search through all transactions vector or file and whatever matches with phone number, output it.
    
    if (key == "First")
    {
        for (int i = 0; i < allTransactions.size(); i++)
        {
            if (allTransactions[i]->phoneNumber == aPhoneNumber)
            {
                foundTransactions.push_back(allTransactions[i]);
                return foundTransactions;
            }
        }
    }
    else if (key == "Last")
    {
        for (int i = 1; i <= allTransactions.size(); i++) {
            if (allTransactions[allTransactions.size() - i]->phoneNumber == aPhoneNumber) {
                foundTransactions.push_back(allTransactions[allTransactions.size() - i]);
                return foundTransactions;
            }
        }
    }
    else if (key == "All")
    {
        for (int i = 0; i < allTransactions.size(); i++)
        {
            if (allTransactions[i]->phoneNumber == aPhoneNumber)
            {
                foundTransactions.push_back(allTransactions[i]);
            }
        }
        return foundTransactions;
    }
    else 
    {
        for (int i = 0; i < allTransactions.size(); i++)
        {
            if (allTransactions[i]->phoneNumber == aPhoneNumber && allTransactions[i]->diskName == key)
            {
                foundTransactions.push_back(allTransactions[i]);
                return foundTransactions;
            }
        }
    }
    
    return foundTransactions;
    
}

