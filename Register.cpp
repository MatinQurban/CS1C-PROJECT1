#include "Register.h"

Register::Register() 
{ 
    populateTransactions();
}

Register::Register(vector<Transaction_Info *> Transactions)
{
    for(int i = 0; i < Transactions.size(); i++)
    {
        allTransactions.push_back(Transactions[i]);
    }
}

Register::~Register() 
{ 
    dumpTransactions();
}

void Register::newTransaction(const string& diskName, const string& diskType, const double& price, const string& firstName, const string& lastName, const string& phoneNumber)
{
    Transaction_Info *Transaction_Info;
    Transaction_Info->diskName = diskName;
    Transaction_Info->diskType = diskType;
    Transaction_Info->price = price;
    Transaction_Info->firstName = firstName;
    Transaction_Info->lastName = lastName;
    Transaction_Info->phoneNumber = phoneNumber;

    allTransactions.push_back(Transaction_Info);
}

// This function will populate the allTransactions vector with the transactions from the transaction file.
void Register::populateTransactions()
{
    ifstream previousTransactions;
	previousTransactions.open("Store_Transactions.txt");

    string lineTransaction;
    int lineCount = 0;

    getline(previousTransactions, lineTransaction);
    if (!validateTransactionFile(lineTransaction, lineCount))
    {
        cout << "The transaction file is not in the correct format. Please check the file and try again." << endl;
        previousTransactions.close();
        return;
    }
    
    while (getline(previousTransactions, lineTransaction))
    { 
        lineCount++;
        if(validateTransactionFile(lineTransaction, lineCount))
        {
            Transaction_Info formattedTransaction = parseLine(lineTransaction);
            Transaction_Info *Transaction_Info = &formattedTransaction;

            allTransactions.push_back(Transaction_Info);
        }
        else
        {
            cout << "Information transfer complete. Closing file." << endl;
            previousTransactions.close();
            break;
        }
    }
    return;
}

Transaction_Info parseLine(string transaction)
{
    //string transaction will look like this: //DiskName //DiskType //Total //FirstName //LastName //Phone //
    /*
    DiskName: string
    DiskType: string
    Total: double
    FirstName: string
    LastName: string
    Phone: long
    */
    Transaction_Info transactionData;
    
    transactionData.diskName = transaction.substr(2, transaction.find(" ") - 3);
    
    transaction = transaction.substr(transaction.find(" ") + 1); //DiskType //Total //FirstName //LastName //Phone //
    transactionData.diskType = transaction.substr(2, transaction.find(" ") - 3);

    transaction = transaction.substr(transaction.find(" ") + 1); //Total //FirstName //LastName //Phone //
    transactionData.price = stod(transaction.substr(2, transaction.find(" ") - 3));

    transaction = transaction.substr(transaction.find(" ") + 1); //FirstName //LastName //Phone //
    transactionData.firstName = transaction.substr(2, transaction.find(" ") - 3);

    transaction = transaction.substr(transaction.find(" ") + 1); //LastName //Phone //
    transactionData.lastName = transaction.substr(2, transaction.find(" ") - 3);

    transaction = transaction.substr(transaction.find(" ") + 1); //Phone //
    transactionData.phoneNumber = transaction.substr(2, transaction.find(" ") - 3);

    return transactionData;
}

// This function will be used to check if we are opening the right file in the correct format.
bool Register::validateTransactionFile(string line, int lineCount)
{
    string tempLine = line;
    if (lineCount == 0)
    {
        return line == "//DiskName //DiskType //Total //FirstName //LastName //Phone //";
    }

    //For the rest of the validation process, we will skip checking for strings, due to their nature of being able to contain any character.

    tempLine = line.substr(line.find(" ") + 1); //DiskType //Total //FirstName //LastName //Phone //
    tempLine = line.substr(line.find(" ") + 1); //Total //FirstName //LastName //Phone //

    try 
    {
        stod(tempLine.substr(2, tempLine.find(" ") - 3));
    } catch (const std::out_of_range&) {
        cout << "Argument is out of range for a double" << endl;
        return false;
    }
    catch (const std::invalid_argument&) {
        cout << "Total is not in the right format!\n" << "Line: " << lineCount << endl;
        return false;
    }
    
    return true;
}

// This function will append every transaction inside allTransactions into the transaction file, and then clear the vector.
void Register::dumpTransactions()
{
    ofstream transactionFile;
    string lineTotal;

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
        lineTotal += "//" + allTransactions[i]->phoneNumber + " ";
        
    }
    // ======================================================================

    //NEED TO REMEMBER TO DELETE EVERYTHING IN THE VECTOR AFTER THIS IS DONE!

    // ======================================================================
    transactionFile.close("Store_Transactions.txt");
}