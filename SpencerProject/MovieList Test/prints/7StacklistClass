/*
 * Stack.cpp
 *
 *  Created on: May 11, 2023
 *      Author: spenc
 */
#include "Stack.h"

StackList::StackList()
{
    /*******************************************************
    * CONSTRUCTOR: This method is the constructor for objects in the class StackList.
    * ----------------------------------------------------
    * IN/CALC
    * VOID
    *
    * OUT/CALC
    * VOID
    *
    * CALC:
	*
	* RETURN:
	* VOID
    *****************************************************/
	// Data table
	head = NULL;
	stackCount = 0;
}

StackList::~StackList()
{
    /*******************************************************
    * DESTRUCTOR: This method is the destructor for objects in the class StackList. It iteratively deletes each node in a linked list starting from the head node.
    * It creates a temporary pointer dvdPtr and assigns it the value of head. Then, it enters a loop that continues as long as dvdPtr is not NULL.
    * Within each iteration, it updates the head to point to the next node, deletes the node pointed to by dvdPtr, and updates dvdPtr to the new head node.
    * This process effectively deallocates memory and clears the entire linked list.
    * ----------------------------------------------------
    * IN/CALC
    * VOID
    *
    * OUT/CALC
    * VOID
    *
    * CALC:
	* DVDNode *dvdPtr //Temporary pointer used for traversal and deletion
	*
	* RETURN:
	* VOID
    *****************************************************/
	// Data table
	DVDNode *dvdPtr;

	dvdPtr = head;

	while (dvdPtr != NULL)
	{
		head = head->next;
		delete dvdPtr;

		dvdPtr = head;

	}

}

void StackList::Push(DVDNode newDVD)
{
	/*******************************************************
	* MUTATOR: The Push function is a member function of the StackList class that adds a new node containing DVD information to the top of the stack.
	* The function takes a parameter newDVD of type DVDNode, representing the DVD to be added.
	* Inside the function, a new dynamic memory allocation is performed to create a new DVDNode object, and the newDVD is assigned to the newly allocated object using the dereference operator.
	* The next pointer of the new node is set to the current head pointer, and the head pointer is updated to point to the new node, making it the new top of the stack.
	* The function does not return any value (void return type).
	*
	* INPUT/CALC:
	* VOID
	*
	* OUTPUT/CALC:
	* VOID
	*
	* CALC:
	* DVDNode *dvdPtr //Temporary pointer used to create a new node and update the stack
	*
	* RETURN:
	* VOID
	*****************************************************/
	// Data table

	DVDNode *dvdPtr;
	dvdPtr = new DVDNode;

	*dvdPtr = newDVD;



	dvdPtr->next = head;
	head = dvdPtr;
}


DVDNode StackList::Pop()
{
	/*******************************************************
	* MUTATOR: The Pop function is a member function of the StackList class that removes and returns the top node from the stack.
	* It throws a runtime_error if the stack is empty. Inside the function, a temporary pointer dvdPtr is created, pointing to the current head node.
	* The head pointer is updated to point to the next node in the stack, removing the top node. The DVD information is copied from the popped node to a DVDNode variable poppedDVD.
	* The memory occupied by the popped node is freed using the delete operator, and dvdPtr is set to NULL.
	* Finally, the function returns poppedDVD, representing the DVD that was popped from the stack.
	*
	* INPUT/CALC:
	* VOID
	*
	* OUTPUT/CALC:
	* VOID
	*
	* CALC:
	* DVDNode *dvdPtr //Temporary pointer used to guide head be copied to poppedDVD.
	* DVDNode poppedDVD //Stores the popped DVD information.
	*
	* RETURN:
	* Returns a copy of the popped DVD, "poppedDVD".
	*****************************************************/
	// Data table
    if (head == NULL) {
        throw runtime_error("Stack is empty. Cannot pop element.");
    }

    DVDNode *dvdPtr;
    DVDNode poppedDVD;

    dvdPtr = head;
    head = dvdPtr->next;
    poppedDVD = *dvdPtr;

    delete dvdPtr;
    dvdPtr = NULL;

    return poppedDVD;
}

