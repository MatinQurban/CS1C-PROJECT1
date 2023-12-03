#ifndef SHELF_H
#define SHELF_H
#include "Disk.h"


class Shelf
{
public:
    void addDisk(Disk *disk);
    bool checkStock(const string &diskName);
    bool removeDisk(const string &diskName);
    void saveTransaction(const ostream& transactionFile, const string& diskName, const string& diskType, const double& price, const string& firstName, const string& lastName, const long& phoneNumber) const;
    void getTransactions(const ostream& transactionFile);
    void registerPreviousTransaction();
    void outputTransactionHistory(const string &aPhoneNumber);

private:
    vector<Disk *> allDisks;
};
#endif // SHELF_H