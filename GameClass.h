// Game class derives from Disk class (pure virtual includes rating and price)
// Game class has additional attributes: PrimaryConsole, MaxCoop count, isMultiplayer

#ifndef GAMECLASS_H
#define GAMECLASS_H

#include "DiskClass.h"

class Game : public Disk {
public:
    Game();
    Game(string title, string genre, string synopsis, int releaseYear, int rating, string primaryConsole, int maxCoopCount, bool isMultiplayer, bool microtransactions);
    ~Game();

    //getters
    string getPrimaryConsole() const;
    int getMaxCoopCount() const;
    bool getIsMultiplayer() const;
    bool getMicrotransactions() const;
    double getPrice() override;

    //setters
    void setPrimaryConsole(string primaryConsole);
    void setMaxCoopCount(int maxCoopCount);
    void setIsMultiplayer(bool isMultiplayer);
    void setMicrotransactions(bool microtransactions);

    void createListOfSellableItems(const string& inputFileName, vector<Game>& games) override;
    
    //pure virtual function

    //print
    void displayInfo() const override;

private:
    string primaryConsole;
    int maxCoopCount;
    bool isMultiplayer;
    bool microtransactions;
};
#endif // GAMECLASS_H
