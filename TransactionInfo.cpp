#include "TransactionInfo.h"

void displayTransaction(Transaction_Info *Transaction)
{
    cout << "****** Transaction ******" << endl;
    cout << "Disk Name: " << Transaction->diskName << endl;
    cout << "Disk Type: " << Transaction->diskType << endl;
    cout << "Price: " << Transaction->price << endl;
    cout << "First Name: " << Transaction->firstName << endl;
    cout << "Last Name: " << Transaction->lastName << endl;
    cout << "Phone Number: " << Transaction->phoneNumber << endl;
    cout << "*************************\n" << endl;
}