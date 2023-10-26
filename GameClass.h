// Game class derives from Disk class (pure virtual includes rating and price)
// Game class has additional attributes: PrimaryConsole, MaxCoop count, isMultiplayer

#ifndef GAMECLASS_H
#define GAMECLASS_H

#include "DiskClass.h"

class Game : public Disk {
    public:
        Game();
        Game(string title, string genre, string synopsis, int releaseYear, int rating, string primaryConsole, int maxCoopCount);
        ~Game();

        //getters
        string getPrimaryConsole() const;
        int getMaxCoopCount() const;
        double getPrice() const override;

        //setters
        void setPrimaryConsole(string primaryConsole);
        void setMaxCoopCount(int maxCoopCount);

        void createListOfSellableItems(const string& inputFileName, vector<Game>& games) const;
        void displayListOfSellableItems(const string &outputFileName, vector<Game> &games) const;
    
        // pure virtual function

        //print
        void displayInfo() const override;

    private:
        double calculatePrice() const;
        string primaryConsole;
        int maxCoopCount;
};
#endif // GAMECLASS_H
