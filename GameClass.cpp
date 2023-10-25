#include "GameClass.h"

GameClass::Game()
{
    primaryConsole = " ";
    maxCoopCount = 0;
}

GameClass::Game(string title, string genre, string synopsis, int releaseYear, int rating, string primaryConsole, int maxCoopCount, bool isMultiplayer, bool microtransactions)
{
    this->gameTitle = title;
    this->gameGenre = genre;
    this->gameSynopsis = synopsis;
    this->releaseYear = releaseYear;
    this->gameRating = rating;
    this->primaryConsole = primaryConsole;
    this->maxCoopCount = maxCoopCount;
    this->isMultiplayer = isMultiplayer;
    this->microtransactions = microtransactions;
}

GameClass::~Game() { }

string GameClass::getPrimaryConsole() const
{
    return primaryConsole;
}

int GameClass::getMaxCoopCount() const
{
    return maxCoopCount;
}

bool GameClass::getIsMultiplayer() const
{
    return
}

bool GameClass::getMicrotransactions() const
{
    return
}

double GameClass::getPrice() {
        if (rating >= 80) {
        return 69.99;
    } else if (percentageGrade >= 60) {
        return 49.99;
    } else if (percentageGrade >= 50) {
        return 29.99;
    } else {
        return 19.99;
    }
}