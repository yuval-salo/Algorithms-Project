#pragma once
#include"Global.h"

struct Edge
{
	int u, v;
	float w;
};

//struct Edge;

struct Node {

	int _verNum;
	float _weight;
	Node* _next;

public:
	static Node* makeNewNode(int verNum, float weight, Node* next = nullptr)
	{
		Node* res = new Node();
		res->_verNum = verNum;
		res->_weight = weight;
		res->_next = next;
		return res;
	}
};

class LinkedList {
private:
	
	Node* head;
	Node* tail;
public:
	LinkedList() :head(nullptr), tail(nullptr) {}
	LinkedList(const LinkedList& other);
	const LinkedList& operator=(const LinkedList& other);
	~LinkedList();
	void makeEmpty();
	bool isEmpty();
	Node* getHead();
	void insertToTail(Node* newNode);
	bool isInTheList(int vertex);
	friend ostream& operator<<(ostream& os, const LinkedList& myList);
	
};
