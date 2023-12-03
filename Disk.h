//Class to handle the base class of disk

#ifndef DISK_H
#define DISK_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Disk {
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


        //setters
        void setTitle(string title);
        void setGenre(string genre);
        void setSynopsis(string synopsis);
        void setReleaseYear(int releaseYear);
        void setRating(int rating);
    
        //print
        friend ostream& operator << (ostream& out, const Disk &rhs);
        void createListOfSellableItems(const string& inputFileName, vector<Disk>& disks);
        virtual void displaySpecificInfo() const = 0;

        //pure virtual function
        virtual double getPrice() const = 0;
        bool operator == (const Disk& rhs) const;
        bool operator != (const Disk& rhs) const;
        
    protected:
        string title;
        string genre;
        string synopsis;
        int releaseYear;
        int rating;
        //double price; Price will be calculated based on rating, so no variable needed. Everytime you want to get the price, calculate it.
};


#endif // DISK_H