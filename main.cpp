#include "Shelf.h"
#include "DiskClass.h"
#include "MovieClass.h"
#include "GameClass.h"
using namespace std;

int main()
{
    movie = new Movie();
    vector<Movie*> movies;

    movie().createListOfSellableItems("inputMovies.txt", movies);

    game = new Game();
    vector<Game*> games;

    game().createListOfSellableItems("inputGames.txt", games);

    return 0;
}