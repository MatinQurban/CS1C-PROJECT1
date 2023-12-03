#ifndef REGISTER_H
#define REGISTER_H

#include "Disk.h"

struct Transaction_Info {
    string diskName;
    string diskType;
    double price;
    string firstName;
    string lastName;
    long phoneNumber;
} typedef Transaction_Info;

class Register 
{
    public:
        Register(const string& diskName, const string& diskType, const double& price, const string& firstName, const string& lastName, const long& phoneNumber);
        ~Register();
        void newTransaction(const string& diskName, const string& diskType, const double& price, const string& firstName, const string& lastName, const long& phoneNumber);

    private:
        vector<Transaction_Info *> allTransactions;
};
#endif // REGISTER_H