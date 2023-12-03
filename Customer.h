#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Disk.h"
#include "Transaction.h"

class Customer {
    public:
        Customer();
        Customer(string firstName, string lastName, long phoneNumber, double budget);
        ~Customer();
        
        // getters
        string getFirstName() const;
        string getLastName() const;
        long getPhoneNumber() const;
        double getBudget() const;

        // setters
        void setFirstName(string firstName);
        void setLastName(string lastName);
        void setPhoneNumber(long phoneNumber);
        void setBudget(double budget);

        // print
        void displayTransactionHistory();
        void addTransaction(const Transaction &item);

    private:
        string firstName;
        string lastName;
        long phoneNumber;
        double budget;   
        vector<Transaction> transactions;
};
#endif