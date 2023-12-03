#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Disk.h"
#include "Transaction.h"

class Customer 
{
    public:
        Customer();
        Customer(string firstName, string lastName, string phoneNumber, double budget);
        ~Customer();
        
        // getters
        string getFirstName() const;
        string getLastName() const;
        string getPhoneNumber() const;
        double getBudget() const;

        // setters
        void setFirstName(string firstName);
        void setLastName(string lastName);
        void setPhoneNumber(string phoneNumber);
        void setBudget(double budget);
        
        void addTransaction(const Transaction &item);

        // print
        void displayTransactionHistory();

    private:
        string firstName;
        string lastName;
        string phoneNumber;
        double budget;   
        vector<Transaction> transactions;
};
#endif // CUSTOMER_H