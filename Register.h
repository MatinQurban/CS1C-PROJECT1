//Register class used to model and hold transactions. Will also handle saving and loading transactions from a file.
#ifndef REGISTER_H
#define REGISTER_H

#include "Disk.h"
#include "Customer.h"

struct Transaction_Info 
{
    string diskName;
    string diskType;
    double price;
    string firstName;
    string lastName;
    string phoneNumber;
    int budget;
};

class Register
{
    public:
        Register();
        Register(vector<Transaction_Info *> Transactions);
        ~Register();
        vector<Transaction_Info*> findTransaction(const string& aPhoneNumber, const string& key);
        void outputTransactionHistory(const string &aPhoneNumber);
        void populateTransactions();
        void dumpTransactions();
        void newTransaction(const string& diskName, const string& diskType, const double& price, Customer& customer);
        void newTransaction(const Disk* disk, const string& diskType, Customer& customer);
        //overload newTransaction to take in a Transaction_Info struct, or to take in a disk object
        bool validateTransactionFile(string line, int lineCount);

        void displayTransaction(Transaction_Info *Transaction);

    private:
        static vector<Transaction_Info *> allTransactions;
};
#endif // REGISTER_H