// Movie class derives from Disk class (pure virtual includes rating and price)
// Movie class has additional attributes: leadingActor and bluRayOrDVD

#ifndef MOVIE_H
#define MOVIE_H

#include "Disk.h"

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
        void createListOfSellableItems(const string& inputFileName, vector<Movie*>& totalMovies) const; //, vector<Movie *> &availableMovies potentially add this back in as 3rd parameter
        void displayListOfSellableItems(const string &outputFileName, vector<Movie*> &movies) const;

        //print
        void displayInfo() const override;

        double calculatePrice() const;
    private:
        string leadingActor;
        string bluRayOrDVD;
};
#endif // MOVIE_H