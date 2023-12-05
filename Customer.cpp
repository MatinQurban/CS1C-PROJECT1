#include "Customer.h"

Customer::Customer()
{
    firstName = "";
    lastName = "";
    budget = 0.0;
    phoneNumber = "";
}

Customer::Customer(string firstName, string lastName, string phoneNumber, double budget)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->phoneNumber = phoneNumber;
    this->budget = budget;
}

Customer::~Customer() { }

string Customer::getFirstName() const
{
    return firstName;
}

string Customer::getLastName() const
{
    return lastName;
}

string Customer::getPhoneNumber() const
{
    return phoneNumber;
}

double Customer::getBudget() const
{
    return budget;
}

void Customer::setFirstName(string firstName)
{
    this->firstName = firstName;
}

void Customer::setLastName(string lastName)
{
    this->lastName = lastName;
}

void Customer::setPhoneNumber(string phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

void Customer::setBudget(double budget)
{
    this->budget = budget;
}

void Customer::displayTransactionHistory()
{
    for (int i = 0; i < transactions.size(); i++)
    {
        displayTransaction(&transactions[i]);
    }
}

void Customer::addTransaction(const Transaction_Info &item)
{
    transactions.push_back(item);
}