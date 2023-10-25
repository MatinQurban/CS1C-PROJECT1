#include "MovieClass.h"

MovieClass::Movie() : leadingActor(" "), bluRayOrDVD(" ")
{

}

MovieClass::MovieClass(string title, string genre, string synopsis, int releaseYear, int rating, string leadingActor, string bluRayOrDVD)
{
    this->movieTitle = title;
    this->movieGenre = genre;
    this->movieSynopsis = synopsis;
    this->releaseYear = releaseYear;
    this->movieRating = rating;
    this->leadingActor = leadingActor;
    this->bluRayOrDVD = bluRayOrDVD;
}

MovieClass::~Movie() { }

string MovieClass::getLeadingActor() const
{
    return leadingActor;
}
string MovieClass::getBluRayOrDVD() const
{
    return bluRayOrDVD;
}

void MovieClass::createListOfMoviesOnSale(const string& inputFileName, vector<Movie>& movies)
{
    ifstream inFile(inputFileName);

    if (!inFile) {
        cout << "Error opening the input file." << endl;
        return;
    }

    string title;
    string genre;
    string leadingActor;
    string bluRayOrDVD;
    int releaseYear;
    int rating;
    string synopsis;
    while (inFile && !inFile.eof()) 
    {
        getline(inFile, title);
        getline(inFile, genre);
        getline(inFile, leadingActor);
        getline(inFile, bluRayOrDVD);
        inFile >> releaseYear;
        inFile >> rating;
        inFile.ignore(10000, '\n');
        getline(inFile, synopsis);
        inFile.ignore(10000, '\n');

        Movie movie(title, genre, synopsis, releaseYear, rating, leadingActor, bluRayOrDVD);

        movies.push_back(&movie);

    }
    
    inFile.close();
}

double MovieClass::getPrice() {
        if (rating >= 4) {
        return 39.99;
    } else if (percentageGrade >= 3) {
        return 29.99;
    } else if (percentageGrade >= 2) {
        return 19.99;
    } else {
        return 9.99;
    }
}