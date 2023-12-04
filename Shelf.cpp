#include "Shelf.h"

Shelf::Shelf() 
{ 
    
}

Shelf::~Shelf() { }

void Shelf::addDisk(Disk *disk)
{
    allDisks.push_back(disk);
}

bool Shelf::checkStock(const string &diskName)
{
    // Iterate through vector, look for diskName, return true if found, else, return false.
    for (const auto &disk : allDisks)
    {
        if (disk->getTitle() == diskName)
        {
            return true;
        }
    }
    return false;
}

bool Shelf::removeDisk(const string &diskName)
{
    // Check if the disk exists in the vector, if so, remove it.
    for (auto diskToFind = allDisks.begin(); diskToFind != allDisks.end(); diskToFind++)
    {
        if ((*diskToFind)->getTitle() == diskName)
        {
            allDisks.erase(diskToFind);
            return true;
        }
    }
    return false;
}

void Shelf::saveTransaction(const ostream& transactionFile, const string& diskName, const string& diskType, const string& price, const string& firstName, const string& lastName, const string& phoneNumber) const
{
    transactionFile << phoneNumber << endl;
    transactionFile << diskName << endl;
    transactionFile << diskType << endl;
    transactionFile << price << endl;
    transactionFile << firstName << endl;
    transactionFile << lastName << endl;
    transactionFile << endl;
}

void Shelf::getTransactions(const ostream& transactionFile) 
{
    //This function gets the previous transaction history into a vector and into the new transaction history file
    getline(transactionFile, xPhoneNumber);
    transactionFile << xPhoneNumber;
    getline(transactionFile, xdiskName);
    transactionFile << xdiskName;
    getline(transactionFile, xdiskType);
    transactionFile << xdiskType;
    getline(transactionFile, xprice);
    transactionFile << xprice;
    getline(transactionFile, xfirstName);
    transactionFile << xfirstName;
    getline(transactionFile, xlastName);
    transactionFile << xlastName;
    transactionFile.ignore(10000, '\n');
}

void Shelf::registerPreviousTransaction() {
    //iterate through vector holding data and call the check stock function to see if there is a match, if there is, call the removeDisk function with the name of the disk.
    for (const auto &disk : allDisks)
    {
        if (disk->getTitle() == xdiskName)
        {
            checkStock(xdiskName);
            removeDisk(xdiskName);
        }
    }
}

void Shelf::outputTransactionHistory(const string& aPhoneNumber) 
{
    //iterate through vector looking for a match for aPhone number, if found, display the next six pieces of data inside the vector as its the transaction history.
    for (const auto &disk : allDisks)
    {
        if (disk->getTitle() == aPhoneNumber)
        {
            cout << "Transaction History: " << endl;
            cout << "Phone Number: " << xPhoneNumber << endl;
            cout << "Disk Name: " << xdiskName. << endl;
            cout << "Disk Type: " << xdiskType << endl;
            cout << "Price: " << xprice << endl;
            cout << "First Name: " << xfirstName << endl;
            cout << "Last Name: " << xlastName << endl;
        }
    }
}

Disk* Shelf::getDisk(const string &diskName)
{
    for (const auto &disk : allDisks)
    {
        if (disk->getTitle() == diskName)
        {
            return disk;
        }
    }
    return nullptr;
}