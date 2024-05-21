
class CNode
{

private:
	int data; //variable to hold integer data value
	CNode* nextNode; //pointer to next node
	CNode* previousNode; //pointer to previous node

public:
	CNode();

	void setData(int data); //function to set data
	int getData() const;

	void setNextNode(CNode* _nextNode); //function to move to next node
	CNode* getNextNode() const;

	void setPreviousNode(CNode* _previousNode); //function to move to previous node
	CNode* getPreviousNode() const;

};
