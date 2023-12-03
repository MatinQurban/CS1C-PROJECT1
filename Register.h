#ifndef REGISTER_H
#define REGISTER_H

#include "Disk.h"

struct Transaction_Info {
    string diskName;
    string diskType;
    double price;
    string firstName;
    string lastName;
    string phoneNumber;
};

class Register : public Transaction_Info
{
    public:
        Register();
        Register(vector<Transaction_Info *> Transactions);
        ~Register();
        void populateTransactions();
        void dumpTransactions();
        void newTransaction(const string& diskName, const string& diskType, const double& price, const string& firstName, const string& lastName, const string& phoneNumber);
        bool validateTransactionFile(string line, int lineCount);

    private:
        static vector<Transaction_Info *> allTransactions;
};
#endif // REGISTER_H