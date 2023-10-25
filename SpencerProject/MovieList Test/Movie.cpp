/*
 * Movie.cpp
 *
 *  Created on: May 11, 2023
 *      Author: spenc
 */
#include "Movie.h"
#include "Stack.h"

MovieList::MovieList(){
    /*******************************************************
    * CONSTRUCTOR: This method is the constructor for objects in the class MovieList.
    * ----------------------------------------------------
    * IN/CALC
    * VOID
    *
    * OUT/CALC
    * VOID
    *
    * CALC:
	* VOID
	*
	* RETURN:
	* VOID
    *****************************************************/
	// Data table

}

MovieList::~MovieList(){
    /*******************************************************
    * DESTRUCTOR: This method is the destructor for objects in class MovieList.
    * ----------------------------------------------------
    * IN/CALC
    * VOID
    *
    * OUT/CALC
    * VOID
    *
    * CALC:
	* VOID
	*
	* RETURN:
	* VOID
    *****************************************************/
	// Data table
}

void MovieList::CreateList(string inputFileName)
{
    /*******************************************************
    * MUTATOR: The CreateList method of the MovieList class reads movie data from an input file specified by inputFileName parameter and populates the movie list accordingly.
    * The method creates a temporary DVDNode object dvdPtr and opens the input file for reading. It then enters a loop that continues as long as there is valid input in the file.
    * Within each iteration, it retrieves the movie details from the input file, including the title, leading actor, supporting actor, genre, alternate genre, year, rating, and synopsis,
    * storing them in the respective attributes of dvdPtr. The movie information is displayed on the console for verification, and then the dvdPtr is added to the movie list by invoking
    * the Push method inherited from the StackList base class. After the loop finishes, the temporary dvdPtr object is deallocated, the input file is closed, and the method returns.
    * ----------------------------------------------------
    * IN/CALC
    * VOID
    *
    * OUT/CALC
    * DVDNode *dvdPtr //Temporary pointer to store movie information
    *
    * CALC:
	*
	* RETURN:
	* VOID
    *****************************************************/
	// Data table

	DVDNode *dvdPtr;
	dvdPtr = new DVDNode;

	ifstream inFile;
	inFile.open(inputFileName);

	while(inFile)
	{
		getline(inFile, dvdPtr->title);
		getline(inFile, dvdPtr->leadingActor);
		getline(inFile, dvdPtr->supportingActor);
		getline(inFile, dvdPtr->genre);
		getline(inFile, dvdPtr->alternateGenre);
		inFile >> dvdPtr->year;
		inFile >> dvdPtr->rating;
		inFile.ignore(10000, '\n');
		getline(inFile, dvdPtr->synopsis);
		inFile.ignore(10000, '\n');

		cout << "Name: " << dvdPtr->title << endl;

		Push(*dvdPtr);
	}
	delete dvdPtr;
	dvdPtr = NULL;
	inFile.close();
}

void MovieList::DisplayList(string outputFileName) const
{
    /*******************************************************
    * ACCESSOR: The DisplayList method of the MovieList class generates an output file specified by outputFileName, containing a formatted movie list.
    * The method iterates through each node in the movie list using a temporary DVDNode pointer dvdPtr, starting from the head.
    * It writes the movie information, including movie number, title, year, rating, leading actor, supporting actor, genres, and plot synopsis, to the output file in a well-organized format.
    * The PrintHeader function is called to print a header at the beginning of the file. The plot synopsis is wrapped using the WordWrap function to ensure proper formatting.
    * The output file is then closed, completing the display of the movie list.
    * ----------------------------------------------------
    * IN/CALC
    * VOID
    *
    * OUT/CALC
    * DVDNode *dvdPtr //Temporary pointer to traverse the movie list
    *
    * CALC:
	* MovieList tempMovie //Temporary MovieList object
	* int count //Counter variable for movie number
	* ofstream oFile //Output file stream object for writing the file
	*
	* RETURN:
	* VOID
    *****************************************************/
	// Data table
	DVDNode *dvdPtr;
	MovieList tempMovie;
	int count;
	ofstream oFile;

	dvdPtr = head;
	count = 1;

	oFile.open(outputFileName);

	PrintHeader(oFile);

	cout << "\nWriting output file " << outputFileName << endl;

	while(dvdPtr != NULL)
	{
		oFile << "***************************************************************************\n";

		oFile << "MOVIE #:" << setw(2) << count << "        Title: "
				<< TitleString(dvdPtr->title) << endl;
		oFile << "---------------------------------------------------------------------------\n";

		oFile << "Year: " << dvdPtr->year << "        Rating: " << dvdPtr->rating << endl;
		oFile << "---------------------------------------------------------------------------\n";

		oFile << left << setw(18) << "Leading Actor:" << setw(25) << dvdPtr->leadingActor << "Genre 1: " << dvdPtr->genre << endl;
		oFile << setw(18) << "Supporting Actor:" << setw(25)
				<< dvdPtr->supportingActor << "Genre 2: " << dvdPtr->alternateGenre << right << endl;
		oFile << "---------------------------------------------------------------------------\n";

		oFile << "PLOT:" << endl << WordWrap(dvdPtr->synopsis) << endl;
		oFile << "***************************************************************************\n";
		oFile << endl << endl;

		count++;

		dvdPtr = dvdPtr->next;
	}

	oFile.close();

}

string MovieList::WordWrap(string plot) const
{
    /*******************************************************
    * ACCESSOR:
	* The WordWrap method of the MovieList class takes a plot string as input and returns a formatted string with word-wrapping applied.
	* The method initializes a stringstream object stream for building the resulting string.
	* It iterates through each character of the plot string and appends it to the word variable if it is not a space.
	* When a space is encountered, the method checks if adding the current word to the line would exceed the maximum character limit MAX_CHAR.
	* If it does, the current line is added to the stream and line is reset. The word is then appended to the line with a space.
	* Finally, the method adds the last line to the stream and appends the remaining word. The resulting string is obtained from the stream and returned.
    * ----------------------------------------------------
    * IN/CALC
    * VOID
    *
    * OUT/CALC
    * VOID
    *
    * CALC:
	* const int MAX_CHAR //Represents the maximum number of characters before word wrap is applied
	* ostringstream stream //A stringstream object used for building the resulting string
	* string word //Stores the current word being processed during word wrap
	* string line //Stores the current line being constructed during word wrap
	* unsigned int i //Iteration variable used to traverse the characters of the plot string
	*
	* RETURN:
	* Returns the ostringstream variable "stream"
    *****************************************************/
	// Data table

	ostringstream stream; //stringstream for return
	string word;
	string line;
	word = "";
	line = "";

	const int MAX_CHAR = 50;

	for(unsigned int i = 0; i < plot.length(); i++)
	{
		if(plot[i] != ' ')
		{
			word = word + plot[i];
		}
		else
		{
			if(line.length() + word.length() > MAX_CHAR)
			{
				stream << line << endl;
				line = "";
			}

			line = line + word + ' ';
			word = "";
		}
	}

	stream << line;
	if(line.length() + word.length() > MAX_CHAR)
	{
		stream << endl;
	}
	stream << word;

	return stream.str();
}

string MovieList::TitleString(string title) const
{
    /*******************************************************
    * ACCESSOR:
	* The WordWrap method of the MovieList class takes a plot string as input and returns a formatted string with word-wrapping applied.
	* The method initializes a stringstream object stream for building the resulting string.
	* It iterates through each character of the plot string and appends it to the word variable if it is not a space.
	* When a space is encountered, the method checks if adding the current word to the line would exceed the maximum character limit MAX_CHAR.
	* If it does, the current line is added to the stream and line is reset. The word is then appended to the line with a space.
	* Finally, the method adds the last line to the stream and appends the remaining word. The resulting string is obtained from the stream and returned.
    * ----------------------------------------------------
    * IN/CALC
    * VOID
    *
    * OUT/CALC
    *
    * CALC:
	* const int MAX_CHAR //Represents the maximum number of characters allowed for the title, used for truncation and concatenation
	*
	* RETURN:
	* Returns the newly modified title, "title".
    *****************************************************/
	// Data table

	const int MAX_CHAR = 50;

	if(title.length() > MAX_CHAR)
	{
		title = title.substr(0, MAX_CHAR - 3) + "...";
		// cout << title;
	}
	return title;
}

void MovieList::PrintHeader(ostream &oFile) const //CLASS HEADER TO FILE
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
	*****************************************************/
	const char PROGRAMMER[30] = "Spencer Klug";
	const char CLASS[5] = "CS1B";
	const char SECTION[25] = "MW: 7:30p - 9:50p";
	const int LAB_NUM = 5;
	const char LAB_NAME[25] = "OOP - DVD Movie List";
	// OUTPUT – Class Heading
	oFile << left;
	oFile << "**************************************************";
	oFile << "\n* PROGRAMMED BY : " << PROGRAMMER;
	oFile << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	oFile << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	oFile << "\n* LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME;
	oFile << "\n**************************************************\n\n";
	oFile << right;
	return;
}

