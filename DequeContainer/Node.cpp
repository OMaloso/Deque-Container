#include "Node.h"

CNode::CNode()
{
	data = -1;
	nextNode = nullptr; //set pointer to null on creation
	previousNode = nullptr; //set pointer to null on creation
}

void CNode::setData(int data) //function to set data
{
	this->data = data;
}

int CNode::getData() const
{
	return this->data;
}

void CNode::setNextNode(CNode* _nextNode) //function to move to next node
{
	this->nextNode = _nextNode;
}

CNode* CNode::getNextNode() const //function to get next node
{
	return this->nextNode;
}

void CNode::setPreviousNode(CNode* _previousNode) //function to move to previous node
{
	this->previousNode = _previousNode;
}

CNode* CNode::getPreviousNode() const //function to get previous node
{
	return this->previousNode;
}