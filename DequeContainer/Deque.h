
#include "Node.h"

class CDeque
{

private:
	CNode* startNode; //pointer pointing to first node 
	CNode* endNode; //pointer pointing to last node 

public:
	CDeque();
	~CDeque();

	void Enqueue_Back(int data); //add an item to the back of the queue

	void Enqueue_Front(int data); //add an item to the front of the queue

	void Dequeue_Back(); //remove the back item from the queue

	void Dequeue_Front(); //remove the front item from the queue

	void Peek_Front(); //return the front item of the queue, but not remove it

	void Peek_Back(); //return the back item of the queue, but not remove it

	bool IsEmpty(); //return true if the queue is empty, otherwise false.

	void Display(); //display all nodes
};

