//Class to handle the base class of disk

#ifndef DISK_H
#define DISK_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Disk 
{
    public:
        Disk();
        Disk(string title, string genre, string synopsis, int releaseYear, int rating);
        virtual ~Disk();

        //getters
        string getTitle() const;
        string getGenre() const;
        string getSynopsis() const;
        int getReleaseYear() const;
        int getRating() const;
        //int getStock() const;

        //setters
        void setTitle(string title);
        void setGenre(string genre);
        void setSynopsis(string synopsis);
        void setReleaseYear(int releaseYear);
        void setRating(int rating);
        //void setStock(int stock);
    
        //void itemPurchased(); //decrement stock by 1
    
        //print
        void createListOfSellableItems(const string& inputFileName, vector<Disk>& disks);
        
        virtual void displayInfo() const;

        //pure virtual function
        virtual double getPrice() const=0;
        
        // operator overloading
        friend ostream& operator << (ostream& out, const Disk &rhs);
        bool operator == (const Disk& rhs) const;
        bool operator != (const Disk& rhs) const;
        
    protected:
        string title;
        string genre;
        string synopsis;
        //int numStock;
        int releaseYear;
        int rating;
};
#endif // DISK_H