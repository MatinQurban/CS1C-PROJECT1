//Class to handle the base class of disk


#ifndef DISKCLASS_H
#define DISKCLASS_H


#include <iostream>
#include <string>


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


    //setters
    void setTitle(string title);
    void setGenre(string genre);
    void setSynopsis(string synopsis);
    void setReleaseYear(int releaseYear);
    void setRating(int rating);
    
    //print
    virtual void displayInfo() const;

    //pure virtual function
    virtual void setPrice(int rating);



protected:
    string title;
    string genre;
    string synopsis;
    int releaseYear;
    int rating;
    double price;


};

#endif