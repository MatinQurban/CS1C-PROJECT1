#include "Game.h"

Game::Game()
{
    primaryConsole = "";
    maxCoopCount = 0;
}

Game::Game(string title, string genre, string synopsis, int releaseYear, int rating, string primaryConsole, int maxCoopCount)
{
    this->title = title;
    this->genre = genre;
    this->synopsis = synopsis;
    this->releaseYear = releaseYear;
    this->rating = rating;
    this->primaryConsole = primaryConsole;
    this->maxCoopCount = maxCoopCount;
}

void Game::createListOfSellableItems(const string& inputFileName, vector<Game>& games) const
{
    ifstream inFile(inputFileName);

    if (!inFile) {
        cout << "Error opening the input file." << endl;
        return;
    }

    string title;
    string genre;
    string primaryConsole;
    int maxCoopCount;
    int releaseYear;
    int rating;
    string synopsis;

    while (inFile && !inFile.eof()) 
    {
        getline(inFile, title);
        getline(inFile, genre);
        getline(inFile, primaryConsole);
        inFile >> maxCoopCount;
        inFile >> releaseYear;
        inFile >> rating;
        inFile.ignore(10000, '\n');
        getline(inFile, synopsis);
        inFile.ignore(10000, '\n');

        Game game(title, genre, synopsis, releaseYear, rating, primaryConsole, maxCoopCount);

        games.push_back(&games);

    }
    
    inFile.close();
}

void Game::displayListOfSellableItems(const string &outputFileName, vector<Game> &games) const
{
    fstream outFile(outputFileName, ios::out | ios::app);

    if (!outFile)
    {
        cout << "Error opening the output file." << endl;
        return;
    }

    for (int i = 0; i < games.size(); i++)
    {
        outFile << "Title: " << title << endl;
        outFile << "Genre: " << genre << endl;
        outFile << "Primary Console: " << primaryConsole << endl;
        outFile << "Max Coop Count: " << maxCoopCount << endl;
        outFile << "Release Year: " << releaseYear << endl;
        outFile << "Rating: " << rating << endl;
        outFile << "Synopsis: " << synopsis << endl;
        outFile << endl;
    }

    outFile.close();
}

Game::~Game() { }

string Game::getPrimaryConsole() const
{
    return primaryConsole;
}

int Game::getMaxCoopCount() const
{
    return maxCoopCount;
}

double Game::getPrice() const {
    return calculatePrice();
}

double Game::calculatePrice() const {
        if (rating >= 80) {
        return 69.99;
    } else if (rating >= 60) {
        return 49.99;
    } else if (rating >= 50) {
        return 29.99;
    } else {
        return 19.99;
    }
}

void Game::setPrimaryConsole(string primaryConsole)
{
    this->primaryConsole = primaryConsole;
}
    
void Game::setMaxCoopCount(int maxCoopCount)
{
    this->maxCoopCount = maxCoopCount;
}