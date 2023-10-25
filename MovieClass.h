// Movie class extends from disk class

#ifndef MOVIECLASS_H
#define MOVIECLASS_H

#include "DiskClass.h"


class Movie : public Disk {

public:
    Movie();
    Movie(string title, string genre, string synopsis, int releaseYear, int rating, string leadingActor, string supportActor, string format);
    ~Movie();

    //getters
    string getLeadingActor();
    string getSupportActor();
    string getFormat();

    //setters
    void setLeadingActor(string leadingActor);
    void setSupportActor(string supportActor);
    void setFormat(string format);

    //pure virtual function
    void setPrice(int rating) override;

    //print
    void displayInfo() const override;



private:
    string leadingActor;
    string supportActor;
    string format;

};



#endif // MOVIECLASS_H