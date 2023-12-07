#ifndef TRANSACTIONINFO_H
#define TRANSACTIONINFO_H

#include "Disk.h"

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

void displayTransaction(Transaction_Info *Transaction);

#endif // TRANSACTIONINFO_H