#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "Disk.h"
#include "Customer.h"

class Transaction : public Customer 
{
    public:
        Transaction();
        Transaction(int total, string diskName, string diskType, string date);
        ~Transaction();

        //getters
        int getTotal() const;
        string getDiskName() const;
        string getDiskType() const;

        //setters
        void setTotal(int moneySpent);
        void setDiskName(string diskName);
        void setDiskType(string diskType);

        //print

    private:
        int price;
        string diskName;
        string diskType;
        string date;
};
#endif // TRANSACTION_H