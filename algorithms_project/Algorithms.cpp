#include "Algorithms.h"
using namespace std;

int Algorithms::s = 0;
int Algorithms::t = 0;
int Algorithms::m_Size = 0;
float* Algorithms::d;
int* Algorithms::p;

void Algorithms::init(int _s)
{
	for(int i=0; i<m_Size; i++)
	{
		p[i] = -1;
		d[i] = -1;
	}
	
	d[_s - 1] = 0;
}

void Algorithms::resetGraph()
{
	if (d!=nullptr)
	{
		delete[] d;
	}
	if (p != nullptr)
	{
		delete[] p;
	}

	d = new float[m_Size];
	p = new int[m_Size];
}

float Algorithms::bellmanFordMatrix(const AdjMatrix& Mat, int _s, int _t)
{
	s = _s;
	t = _t;
	m_Size = Mat.getSize();
	resetGraph();
	init(s);
	int numberOfEdges;
	Edge* edgesArr = Mat.getAllEdges(&numberOfEdges);


	for (int i = 0; i < m_Size - 1; i++)
	{
		for (int j = 0; j < numberOfEdges; j++)
		{
			relax(edgesArr[j]);
		}
	}
	for (int i = 0; i < numberOfEdges; i++)
	{
		if (relax(edgesArr[i]))
		{
			cout << "NEGATIVE-CYCLE" << endl;
			return -1;
		}
	}
	return d[t - 1];
}

float Algorithms::bellmanFordList(const AdjList& graphList, int _s, int _t)
{
	s = _s;
	t = _t;
	m_Size = graphList.getSize();
	resetGraph();
	init(s);
	int numberOfEdges;
	Edge* edgesArr = graphList.getAllEdges(&numberOfEdges);
	for (int i = 0; i < m_Size - 1; i++)
	{
		for (int j = 0; j < numberOfEdges; j++)
		{
			relax(edgesArr[j]);
		}
	}
	for (int i = 0; i < numberOfEdges; i++)
	{
		if (relax(edgesArr[i]))
		{
			cout << "NEGATIVE-CYCLE" << endl;
			return -1;
		}
	}
	return d[t - 1];
}

float Algorithms::dijkstraMatrixHeap(const AdjMatrix& mat, int _s, int _t)
{
	s = _s;
	t = _t;
	m_Size = mat.getSize();
	resetGraph();
	init(s);
	VertexDistance* dataArray = buildVDistanceArray();
	PriorityQueueHeap Q (dataArray,m_Size);

	while (!Q.isEmpty())
	{
		VertexDistance u = Q.deleteMin();
		LinkedList u_AdjList = mat.getAdjList(u.vertexNum);
		Node* temp = u_AdjList.getHead();
		while (temp != nullptr)
		{
			Edge adjacent = { u.vertexNum,temp->_verNum,temp->_weight };
			if (relax(adjacent))
			{
				Q.decreaseKey(adjacent.v,d[adjacent.v-1]);
			}
			temp = temp->_next;
		}
	}
	return d[t - 1];
}

float Algorithms::dijkstraMatrixArray(const AdjMatrix& mat, int _s, int _t)
{
	s = _s;
	t = _t;
	m_Size = mat.getSize();
	resetGraph();
	init(s);
	VertexDistance* dataArray = buildVDistanceArray();
	PriorityQueueArray Q(dataArray, m_Size);

	while (!Q.isEmpty())
	{
		VertexDistance u = Q.deleteMin();
		LinkedList u_AdjList = mat.getAdjList(u.vertexNum);
		Node* temp = u_AdjList.getHead();
		while (temp != nullptr)
		{
			Edge adjacent = { u.vertexNum,temp->_verNum,temp->_weight };
			if (relax(adjacent))
			{
				Q.decreaseKey(adjacent.v, d[adjacent.v - 1]);
			}
			temp = temp->_next;
		}
	}
	return d[t - 1];
}

float Algorithms::dijkstraListHeap(const AdjList& graphList, int _s, int _t)
{
	s = _s;
	t = _t;
	m_Size = graphList.getSize();
	resetGraph();
	init(s);
	VertexDistance* dataArray = buildVDistanceArray();
	PriorityQueueHeap Q(dataArray, m_Size);

	while (!Q.isEmpty())
	{
		VertexDistance u = Q.deleteMin();
		LinkedList u_AdjList = graphList.getAdjList(u.vertexNum);
		Node* temp = u_AdjList.getHead();
		while (temp != nullptr)
		{
			Edge adjacent = { u.vertexNum,temp->_verNum,temp->_weight };
			if (relax(adjacent))
			{
				Q.decreaseKey(adjacent.v, d[adjacent.v - 1]);
			}
			temp = temp->_next;
		}
	}
	return d[t - 1];
}

float Algorithms::dijkstraListArray(const AdjList& graphList, int _s, int _t)
{
	s = _s;
	t = _t;
	m_Size = graphList.getSize();
	resetGraph();
	init(s);
	VertexDistance* dataArray = buildVDistanceArray();
	PriorityQueueArray Q(dataArray, m_Size);

	while (!Q.isEmpty())
	{
		VertexDistance u = Q.deleteMin();
		LinkedList u_AdjList = graphList.getAdjList(u.vertexNum);
		Node* temp = u_AdjList.getHead();
		while (temp != nullptr)
		{
			Edge adjacent = { u.vertexNum,temp->_verNum,temp->_weight };
			if (relax(adjacent))
			{
				Q.decreaseKey(adjacent.v, d[adjacent.v - 1]);
			}
			temp = temp->_next;
		}
	}
	return d[t - 1];
}

VertexDistance* Algorithms::buildVDistanceArray()
{
	VertexDistance* res = new VertexDistance[m_Size];
	for (int i = 0; i < m_Size; i++)
	{
		res[i].d = d[i];
		res[i].vertexNum = i + 1;
	}
	return res;
}

bool Algorithms::relax(const Edge& edge)
{

	bool isRelaxed = false;
	
	if(-1 == d[edge.u - 1])
	{
		isRelaxed = false;
		
	}
	else if(-1 == d[edge.v - 1]&& -1 != d[edge.u - 1])
	{
		d[edge.v - 1] = d[edge.u - 1] + edge.w;
		p[edge.v - 1] = edge.u;
		isRelaxed = true;
	}
	else if(d[edge.v - 1] > d[edge.u - 1] + edge.w)
	{
		d[edge.v - 1] = d[edge.u - 1] + edge.w;
		p[edge.v - 1] = edge.u;
		isRelaxed = true;
	}

	return isRelaxed;
}