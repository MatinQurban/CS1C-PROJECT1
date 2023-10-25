/*
 * Stack.h
 *
 *  Created on: May 11, 2023
 *      Author: spenc
 */

#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct DVDNode
{
 string title; // store movie's title
 string leadingActor; // store leading actor/actress
 string supportingActor; // store supporting actor/actress
 string genre; // store movie’s genre
 string alternateGenre; // store movie’s alternate genre
 int year; // store movie’s release year
 int rating; // store movie’s rating
 string synopsis; // store movie’s synopsis
 DVDNode *next; // linked list next pointer
};

class StackList // Base Class - Using linked list implementation
{
	/*******************************************************
		* The StackList class represents a stack data structure using a linked list implementation. It provides methods to manipulate and access the stack.
		* The class has a constructor and destructor for initializing and cleaning up the stack.
		* The Push method creates a new DVDNode and adds it to the top of the stack by inserting it at the front of the linked list.
		* The Pop method returns the DVDNode at the top of the stack, removes it from the stack, and deletes it.
		* The class also includes accessor methods such as IsEmpty to check if the stack is empty, Peek to return the DVDNode at the top of the stack,
		* and Size to return the number of elements in the stack. The stack is maintained using the head pointer and the stackCount variable keeps track of the total number of elements in the stack.
	   * ----------------------------------------------------
	   * CONSTRUCTOR & DESTRUCTOR:
	   * Constructor StackList()
	   * Destructor ~StackList()
	   *
	   *
	   * MUTATORS:
	   *  void Push(DVDNode newDVD); //Creates a DVDNode, add a DVDNode in the stack, by adding to the front of the linked List
	   *  DVDNode Pop(); //Return the DVDNode in the top of the stack, removes the DVDNode from the stack, deletes the DVDNode.
	   *
	   * ACCESSORS:
	   * bool IsEmpty() const; // check if stack is empty
	   * DVDNode Peek() const; // return the DVDNode at the top of the stack
	   * int Size() const; // return the number of people in the stack
	   *
	   * ATTRIBUTES:
	   *  DVDNode *head; // head pointer for stack
	   *  int stackCount; // total number of persons in the stack
	   *****************************************************/
public:
 /*********************************
 *** CONSTRUCTOR / DESTRUCTOR ****
 *********************************/
 StackList();
 ~StackList();
 /******************
 **** MUTATORS ****
 ******************/
 void Push(DVDNode newDVD); //Creates a DVDNode, add a DVDNode in the stack, by adding to the front of the linked List
 DVDNode Pop(); //Return the DVDNode in the top of the stack, removes the DVDNode from the stack, deletes the DVDNode.
 /******************
 **** ACCESSORS ****
 ******************/
 bool IsEmpty() const; // check if stack is empty
 DVDNode Peek() const; // return the DVDNode at the top of the stack
 int Size() const; // return the number of people in the stack

protected:
 /******************
 **** ATTRIBUTES ****
 ******************/
 DVDNode *head; // head pointer for stack
 int stackCount; // total number of persons in the stack
};



#endif /* STACK_H_ */
