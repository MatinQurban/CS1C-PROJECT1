//Class to handle the base class of disk

#ifndef DISKCLASS_H
#define DISKCLASS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Disk {
public:
    Disk();
    Disk(string title, string genre, string synopsis, int releaseYear, int rating);
    ~Disk();

    //getters
    string getTitle();
    string getGenre();
    string getSynopsis();
    int getReleaseYear();
    int getRating();
    virtual double getPrice() = 0;


    //setters
    void setTitle(string title);
    void setGenre(string genre);
    void setSynopsis(string synopsis);
    void setReleaseYear(int releaseYear);
    void setRating(int rating);
    
    //print
    virtual void displayInfo() const;
    virtual void createListOfSellableItems(const string& inputFileName, vector<Disk>& disks) = 0;

    //pure virtual function

protected:
    string title;
    string genre;
    string synopsis;
    int releaseYear;
    int rating;
    //double price; Price will be calculated based on rating, so no variable needed. Everytime you want to get the price, calculate it.
};
#endif 