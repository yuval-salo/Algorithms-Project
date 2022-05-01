#include"LinkedList.h"



LinkedList::~LinkedList()
{
	Node* current = head;
	Node* next;
	while (current != nullptr)
	{
		next = current->_next;
		delete current;
		current = next;
	}
}
LinkedList::LinkedList(const LinkedList& other)
{
	*this = other;
}

const LinkedList& LinkedList::operator=(const LinkedList& other)
{
	if (this != &other)
	{
		makeEmpty();
		Node* newNode;
		Node* temp = other.head;
		while (temp != nullptr)
		{
			newNode = Node::makeNewNode(temp->_verNum, temp->_weight);
			insertToTail(newNode);
			temp = temp->_next;
		}
	}
	return *this;
}

void LinkedList::makeEmpty()
{
	Node* temp = head;
	while (temp != nullptr)
	{
		head = head->_next;
		delete temp;
		temp = head;
	}

	head = tail = nullptr;
}
bool LinkedList::isEmpty()
{
	return (head == nullptr);
}
Node* LinkedList::getHead()
{
	return head;
}
void LinkedList::insertToTail(Node* newNode)
{
	if (tail == nullptr)
	{
		head = tail = newNode;
	}
	else
	{
		tail->_next = newNode;
		tail = tail->_next;
	}

}
bool LinkedList::isInTheList(int vertex)
{
	bool res = false;
	Node* temp = head;
	while (temp != nullptr&& !res)
	{
		if (temp->_verNum == vertex)
			res = true;
		temp = temp->_next;
	}
	return res;
}
ostream& operator<<(ostream& os, const LinkedList& myList)
{
	Node* temp = myList.head;
	while (temp != nullptr)
	{
		os << temp->_verNum << ": " << temp->_weight << endl;
		temp = temp->_next;
	}
	return os;
}
