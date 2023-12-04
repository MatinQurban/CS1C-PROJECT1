#include "Movie.h"

Movie::Movie()
{
    leadingActor = "";
    bluRayOrDVD = "";
}

Movie::Movie(string title, string genre, string synopsis, int releaseYear, int rating, string leadingActor, string bluRayOrDVD)
{
    this->title = title;
    this->genre = genre;
    this->synopsis = synopsis;
    this->releaseYear = releaseYear;
    this->rating = rating;
    this->leadingActor = leadingActor;
    this->bluRayOrDVD = bluRayOrDVD;
}

Movie::~Movie() { }

string Movie::getLeadingActor() const
{
    return leadingActor;
}
string Movie::getBluRayOrDVD() const
{
    return bluRayOrDVD;
}

void Movie::createListOfSellableItems(const string& inputFileName, vector<Movie*>& movies)
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

void Movie::displayListOfSellableItems(const string &outputFileName, vector<Movie*> &movies) const
{
    fstream outFile(outputFileName, ios::out);

    if (!outFile)
    {
        cout << "Error opening the output file." << endl;
        return;
    }

    for (int i = 0; i < movies.size(); i++)
    {
        outFile << "Title: " << movies[i]->title << endl;
        outFile << "Genre: " << movies[i]->genre << endl;
        outFile << "Leading Actor: " << movies[i]->leadingActor << endl;
        outFile << "Disk Type: " << movies[i]->bluRayOrDVD << endl;
        outFile << "Release Year: " << movies[i]->releaseYear << endl;
        outFile << "Rating: " << movies[i]->rating << endl;
        outFile << "Synopsis: " << movies[i]->synopsis << endl;
        outFile << endl;
    }

    outFile.close();
}

double Movie::getPrice() const 
{
    return getPrice();
}

double Movie::getPrice() const 
{
        if (rating >= 4) {
        return 39.99;
    } else if (rating >= 3) {
        return 29.99;
    } else if (rating >= 2) {
        return 19.99;
    } else {
        return 9.99;
    }
}

void Movie::setLeadingActor(string leadingActor)
{
    this->leadingActor = leadingActor;
}

void Movie::displayInfo() const
{
    cout << this;
    cout << "Title: " << title << endl;
    cout << "Genre: " << genre << endl;
    cout << "Leading Actor: " << leadingActor << endl;
    cout << "Disk Format: " << bluRayOrDVD << endl;
    cout << "Release Year: " << releaseYear << endl;
    cout << "Rating: " << rating << endl;
    cout << "Synopsis: " << synopsis << endl;
    cout << "Price: " << getPrice() << endl;    
    cout << endl;
}