#pragma once
#include"Global.h"
#include"AdjList.h"
#include"AdjMatrix.h"
#include"PriorityQueueArray.h"
#include"PriorityQueueHeap.h"

class Algorithms
{
private:
	static int s, t, m_Size;
	static float* d;
	static int*   p;
public:
	static void init(int _s);
	static void resetGraph();

	static float dijkstraListHeap(const AdjList& graphList, int _s, int _t);
	static float dijkstraListArray(const AdjList& graphList, int _s, int _t);
	static float bellmanFordList(const AdjList& graphList, int _s, int _t);

	static float dijkstraMatrixHeap(const AdjMatrix& mat, int _s, int _t);
	static float dijkstraMatrixArray(const AdjMatrix& mat, int _s, int _t);	
	static float bellmanFordMatrix(const AdjMatrix& Mat, int _s, int _t);


	static VertexDistance* buildVDistanceArray();
	static bool relax(const Edge& edge);
	
};

