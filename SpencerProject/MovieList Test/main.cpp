/*
 * main.cpp
 *
 *  Created on: May 11, 2023
 *      Author: spenc
 */
#include "Header.h"
#include "Stack.h"
#include "Movie.h"

int main()
{
	   /*******************************************************
	    * CONSTANTS
	    * ----------------------------------------------------
	    * USED FOR CLASS HEADING – ALL WILL BE OUTPUT
	    * ----------------------------------------------------
	    * PROGRAMMER : Programmer's Name
	    * CLASS : Student's Course
	    * SECTION : Class Days and Times
	    * LAB_NUM : Lab Number (specific to this lab)
	    * LAB_NAME : Title of the Lab
	    * Assignment #5 – DVD Movie List Intro to OOP
	    * ----------------------------------------------------
	    * This program allows a user to track their DVDs using Object Oriented Programming. It uses an input file which includes the following attributes for each movie: Title,
	    * Leading actor/actress, Supporting Actor, Genre, Alternate Genre, Year, Rating, and Synopsis. The core functionality is based on a stack data structure implemented as a linked list,
	    * enabling a user to add new movies to the collection and remove movies as needed. The program also provides the ability to access and display movie information,
	    * including the ability to peek at the top movie in the stack and determine the total number of movies in the collection.
	    * ----------------------------------------------------
	    * INPUT/CALC:
	    * string inFileName //A variable to store the input file name provided by the user.
	    * string oFileName //A variable to store the output file name provided by the user.
	    *
	    *
	    * OUTPUT/CALC:
	    * MovieList movie //An instance of the MovieList class used to manage the movie collection.
	    *
	    * CALC:
	    * VOID
	    *
	    * RETURN:
	    * VOID
	    *****************************************************/
	    // Data table

	printHeaderConsole();

	MovieList movie;
	string inFileName;
	string oFileName;

	cout << "What input file would you like to use? ";
	getline(cin, inFileName);

	cout << "What output file would you like to use? ";
	getline(cin, oFileName);

	cout << endl;

	movie.CreateList(inFileName);
	movie.DisplayList(oFileName);

	return 0;
}



