#include "Disk.h"

Disk::Disk() 
{
    title = "";
    genre = "";
    synopsis = "";
    releaseYear = 0;
    rating = 0;
    //numStock = 3;
}

Disk::Disk(string title, string genre, string synopsis, int releaseYear, int rating)
{
    this->title = title;
    this->genre = genre;
    this->synopsis = synopsis;
    this->releaseYear = releaseYear;
    this->rating = rating;
}


Disk::~Disk() { }

string Disk::getTitle() const
{
    return title;
}
    
string Disk::getGenre() const
{
    return genre;
}
    
string Disk::getSynopsis() const
{
    return synopsis;
}
    
int Disk::getReleaseYear() const
{
    return releaseYear;
}
    
int Disk::getRating() const
{
    return rating;
}

//int Disk::getStock() const
//{
    //return numStock;
//}

void Disk::setTitle(string title)
{
    this->title = title;
}
    
void Disk::setGenre(string genre)
{
    this->genre = genre;
}
    
void Disk::setSynopsis(string synopsis)
{
    this->synopsis = synopsis;
}
    
void Disk::setReleaseYear(int releaseYear)
{
    this->releaseYear = releaseYear;
}

void Disk::setRating(int rating)
{
    this->rating = rating;
}

//void Disk::setStock(int stock)
//{
    //this->numStock = stock;
//}

//void Disk::itemPurchased()
//{
    //numStock--;
//}

void Disk::displayInfo() const 
{
    cout << "Title: " << getTitle() << "." << endl; 
    cout << "Genre: " << getGenre() << "." << endl; 
    cout << "Synopsis: "  << getSynopsis() << "." << endl;
    cout << "Release Year: " << getReleaseYear() << "." << endl;
    cout << "Rating: " << getRating() << "." << endl;
    cout << "Price: " << getPrice() << ".\n";
}

ostream& operator <<(ostream& out, const Disk &rhs)
{
    rhs.displayInfo();
    return out;
}

bool Disk::operator ==(const Disk& rhs) const 
{
    return getTitle() == rhs.getTitle() &&
           getGenre() == rhs.getGenre() &&
           getSynopsis() == rhs.getSynopsis() &&
           getReleaseYear() == rhs.getReleaseYear() &&
           getRating() == rhs.getRating() &&
           getPrice() == rhs.getPrice();
}

bool Disk::operator !=(const Disk& rhs) const 
{
  return !(getTitle() == rhs.getTitle() &&
           getGenre() == rhs.getGenre() &&
           getSynopsis() == rhs.getSynopsis() &&
           getReleaseYear() == rhs.getReleaseYear() &&
           getRating() == rhs.getRating() &&
           getPrice() == rhs.getPrice());
}

