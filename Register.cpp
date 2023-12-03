#include "Register.h"

Register::Register(const string& diskName, const string& diskType, const double& price, const string& firstName, const string& lastName, const long& phoneNumber)
{
    this->diskName = diskName;
    this->diskType = diskType;
    this->price = price;
    this->firstName = firstName;
    this->lastName = lastName;
    this->phoneNumber = phoneNumber;
}

Register::~Register() { }