// Movie class extends from disk class

#ifndef MOVIE_H
#define MOVIE_H

#include "Disk.h"

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
        void displayListOfSellableItems(const string &outputFileName, vector<Movie*> &movies) const;

        //print
        void displayMovieInfo() const override;

    private:
        double calculatePrice() const;
        string leadingActor;
        string bluRayOrDVD;
};
#endif // MOVIE_H