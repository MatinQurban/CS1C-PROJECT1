// Movie class extends from disk class

#ifndef MOVIECLASS_H
#define MOVIECLASS_H

#include "DiskClass.h"

using namespace std;

class Movie : public Disk {
    public:
        Movie();
        Movie(string title, string genre, string synopsis, int releaseYear, int rating, string leadingActor, string bluRayOrDVD);
        ~Movie();
    
        //getters
        string getLeadingActor() const;
        string getBluRayOrDVD() const;
        double getPrice() const override;

        //setters
        void setLeadingActor(string leadingActor);
        void createListOfSellableItems(const string& inputFileName, vector<Movie*>& movies);

        //print
        void displaySpecificInfo() const override;

    private:
        double calculatePrice() const;
        string leadingActor;
        string bluRayOrDVD;
};
#endif // MOVIECLASS_H