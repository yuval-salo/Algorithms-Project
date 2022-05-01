#pragma once
#include"Global.h"

class AdjMatrix{
private:
	float **m_Matrix;
	int m_Size;

public:
	AdjMatrix():m_Size(0),m_Matrix(nullptr){}
	AdjMatrix(const AdjMatrix& other);
	const AdjMatrix& operator=(const AdjMatrix& other);
	~AdjMatrix();
	AdjMatrix(int _size); 
	Edge* getAllEdges(int* resSize)const;
	bool makeGraphFromFile(ifstream& inputFile, int &s, int& t);
	void makeEmptyGraph(int _size);
	bool isAdjacent(int _u, int _v);
	LinkedList getAdjList(int _u)const;
	bool addEdge(int _u, int _v, float _w);
	void removeEdge(int _u, int _v);
	const int getSize() const { return this->m_Size; }
	bool operator==(const AdjMatrix& other);
	bool operator!=(const AdjMatrix& other);

	void printGraph();
};
