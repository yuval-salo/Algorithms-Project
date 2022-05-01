#pragma once
#include"Global.h"

struct Vertex
{
	int verNum;
	LinkedList ListOfAdj;
};

class AdjList {
private:
	Vertex* m_arr;
	int m_Size;

public:
	AdjList():m_arr(nullptr),m_Size(0) {}
	~AdjList();
	AdjList(const AdjList& other);
	const AdjList& operator=(const AdjList& other);
	bool makeGraphFromFile(ifstream& inputFile);
	void makeEmptyGraph(int _size);
	bool isAdjacent(int _u, int _v);
	Edge* getAllEdges(int* resSize)const;
	const LinkedList& getAdjList(int _u)const ;
	void addEdge(int _u, int _v, float _w);
	const int getSize() const { return this->m_Size; }
	void removeEdge(int _u, int _v);
	void printGraph();

};
