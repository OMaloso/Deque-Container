#include <iostream>
#include "Deque.h"

CDeque::CDeque() //constructor
{
	startNode = nullptr;
	endNode = nullptr;
}

CDeque::~CDeque() //destructor
{

}

void CDeque::Enqueue_Back(int data) //add an item to the back of the queue
{
	if (startNode == nullptr) //if list is empty, run enqueuefront function to create first node in list
	{
		CDeque::Enqueue_Front(data);
	}
	else //otherwise, add new node to end
	{
		CNode* newNode = new CNode;
		newNode->setData(data);

		newNode->setPreviousNode(endNode);

		endNode->setNextNode(newNode);
		endNode = newNode;

		CDeque::Display(); //display list of data elements 
	}
}

void CDeque::Enqueue_Front(int data) //add an item to the front of the queue
{
	CNode* newNode = new CNode;
	newNode->setData(data);
	if (startNode == nullptr) //if list is empty, create first node in list
	{
		newNode->setNextNode(startNode);
		startNode = newNode;
		endNode = newNode;
	}
	else //otherwise, add new node to front
	{
		CNode* nextNode = startNode;
		nextNode->getNextNode();
		nextNode->setPreviousNode(newNode);
		newNode->setNextNode(startNode);
		startNode = newNode;
	}
	CDeque::Display(); //display list of data elements 
}

void CDeque::Dequeue_Back() //remove the back item from the queue
{
	if (startNode == nullptr) //return output if list is empty
	{
		std::cout << "Cannot remove back item as list is empty." << std::endl;
	}
	else if (startNode->getNextNode() == nullptr) //check if only one node in list
	{
		CDeque::Dequeue_Front();
	}
	else //otherwise, remove last node in list
	{
		CNode* lastNode = endNode;
		endNode = endNode->getPreviousNode();
		endNode->setNextNode(nullptr);
		delete lastNode;
		std::cout << std::endl << "Removed back item." << std::endl;
		CDeque::Display(); //display list of data elements 
	}
}

void CDeque::Dequeue_Front() //remove the front item from the queue
{
	if (startNode == nullptr) //return output if list is empty
	{
		std::cout << "Cannot remove front item as list is empty." << std::endl;
	}
	else if (startNode->getNextNode() == nullptr) //check if only one node in list, if true, then startNode and endNode need to be set to nullptr
	{
		delete startNode;
		startNode = nullptr;
		endNode = nullptr;
		std::cout << std::endl << "Only 1 item in list. Item removed." << std::endl;
		CDeque::Display(); //display list of data elements 
	}
	else //otherwise, remove first node in list
	{
		CNode* firstNode = startNode;
		startNode = startNode->getNextNode();
		startNode->setPreviousNode(nullptr);
		delete firstNode;
		std::cout << std::endl << "Removed front item." << std::endl;
		CDeque::Display(); //display list of data elements 
	}
}

void CDeque::Peek_Front() //return the front item of the queue, but not remove it
{
	if (startNode == nullptr) //return output if list is empty
	{
		std::cout << "Cannot peek as list is empty." << std::endl;
	}
	else
	{
		std::cout << "The front item in the list: " << startNode->getData() << std::endl;
	}
}

void CDeque::Peek_Back() //return the back item of the queue, but not remove it
{
	if (startNode == nullptr) //return output if list is empty
	{
		std::cout << "Cannot peek as list is empty." << std::endl;
	}
	else
	{
		std::cout << "The back item in the list: " << endNode->getData() << std::endl;
	}
}

bool CDeque::IsEmpty() //return true if the queue is empty, otherwise false.
{
	std::cout << "Is list empty?: ";
	if (startNode == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CDeque::Display() //display all node values, beginning from startNode
{
	if (startNode == nullptr) //report if list is now empty. Only happens on Dequeue
	{
		std::cout << "List is now empty." << std::endl;
	}
	else
	{
		CNode* currentNode = startNode;
		int iNumNodes = 1; //variable to hold number of nodes
		std::cout << "Element values in list: " << currentNode->getData() << ", ";
		while (currentNode->getNextNode() != nullptr) //loop through list until reaching nullptr
		{
			currentNode = currentNode->getNextNode();
			std::cout << currentNode->getData() << ", ";
			iNumNodes++; //increase number of nodes by one
		}
		std::cout << std::endl;
		std::cout << "Number of nodes in list: " << iNumNodes << std::endl; //also report number of nodes in list
	}
}
