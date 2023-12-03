#include "Transaction.h"

Transaction::Transaction()
{
    price = 0;
    diskName = "";
    diskType = "";
    date = "";
}

Transaction::Transaction(int total, string diskName, string diskType, string date)
{
    price = total;
    this->diskName = diskName;
    this->diskType = diskType;
    this->date = date;
}

Transaction::~Transaction() { }

int Transaction::getTotal() const
{
    return price;
}

string Transaction::getDiskName() const
{
    return diskName;
}

string Transaction::getDiskType() const
{
    return diskType;
}

void Transaction::setTotal(int moneySpent)
{
    price = moneySpent;
}

void Transaction::setDiskName(string diskName)
{
    this->diskName = diskName;
}

void Transaction::setDiskType(string diskType)
{
    this->diskType = diskType;
}