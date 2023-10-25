/*
 * Movie.h
 *
 *  Created on: May 11, 2023
 *      Author: spenc
 */

#ifndef MOVIE_H_
#define MOVIE_H_

#include "Stack.h"
class MovieList: public StackList
{
	/*******************************************************
		* The MovieList class is a derived class that extends the functionality of the StackList class, representing a stack-based movie list.
		* It introduces methods for creating and displaying the movie list, along with auxiliary functions for text formatting.
		* The constructor and destructor are responsible for initializing and cleaning up the movie list.
		* The CreateList method takes an input file name as a parameter and populates the movie list by reading movie data from the file.
		* The DisplayList method takes an output file name as a parameter and outputs the movie list to the specified file.
		* Additionally, the class includes private helper functions, such as WordWrap for wrapping plot descriptions,
		* TitleString for formatting movie titles, and PrintHeader for printing a header when displaying the list.
	   * ----------------------------------------------------
	   * CONSTRUCTOR & DESTRUCTOR:
	   * MovieList();  // Constructor declaration
	   * ~MovieList(); // Destructor declaration
	   *
	   *
	   * MUTATORS:
	   * void CreateList(string inputFileName); //Method of the MovieList class reads movie data from an input file and populates the movie list accordingly using name of file parameter.
	   * void DisplayList(string outputFileName) const; //Method of MovieList class that outputs data from an input file into an output file getting its name as a parameter.
	   *
	   * ACCESSORS:
	   * void DisplayList(string outputFileName) const; //Method of MovieList class that outputs data from an input file into an output file getting its name as a parameter.
	   * string WordWrap(string plot) const; //Private Method of MovieList class that manipulates lines of text depending on their length. Gets text from parameter.
	   * string TitleString(string title) const; //Private method used to format movie titles, gets the title name as parameter.
	   * void PrintHeader(ostream &oFile) const; //Outputs class header to output file getting the output file as a parameter.
	   *
	   * ATTRIBUTES:
	   *  VOID
	  *****************************************************/
public:
	 /*********************************
	 *** CONSTRUCTOR / DESTRUCTOR ****
	 *********************************/
	MovieList();  // Constructor declaration
	~MovieList(); // Destructor declaration

	 /******************
	 **** MUTATORS ****
	 ******************/
	void CreateList(string inputFileName);
	void DisplayList(string outputFileName) const;

private:
	 /******************
	 **** ACCESSORS ****
	 ******************/
	string WordWrap(string plot) const;
	string TitleString(string title) const;
	void PrintHeader(ostream &oFile) const;
};



#endif /* MOVIE_H_ */
