// Movie class extends from disk class

#ifndef MOVIECLASS_H
#define MOVIECLASS_H

#include "DiskClass.h"
#include <fstream>

using namespace std;

class Movie : public Disk {
public:
    Movie();
    Movie(string title, string genre, string synopsis, int releaseYear, int rating, string leadingActor, string bluRayOrDVD);
    ~Movie();
    
    //getters
    string getLeadingActor() const;
    string getBluRayOrDVD() const;
    double getPrice() override;

    //setters
    void setLeadingActor(string leadingActor);
    void createListOfSellableItems(const string& inputFileName, vector<Movie>& movies) override;

    //pure virtual function

    //print
    void displayInfo() const override;

private:
    string leadingActor;
    string bluRayOrDVD;
};
#endif // MOVIECLASS_H