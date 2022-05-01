#include"AdjMatrix.h"
#include <string>
#define SIZE 50

AdjMatrix::AdjMatrix(int _size) : m_Size(_size)
{
	makeEmptyGraph(m_Size);
}
AdjMatrix::AdjMatrix(const AdjMatrix& other)
{
	*this = other;
}
AdjMatrix:: ~AdjMatrix()
{
	for (int i = 0; i < m_Size; i++)
	{
		delete[] m_Matrix[i];
	}

	delete[] m_Matrix;
}

const AdjMatrix& AdjMatrix::operator=(const AdjMatrix& other)
{
	if (*this != other)
	{
		m_Size = other.m_Size;
		m_Matrix = new float* [m_Size * sizeof(float*)];


		for (int i = 0; i < m_Size; i++)
		{
			m_Matrix[i] = new float[m_Size * sizeof(float)];
		}

		for (int i = 0; i < m_Size; i++)
		{
			for (int j = 0; j < m_Size; j++)
			{
				m_Matrix[i][j] = other.m_Matrix[i][j];
			}
		}

	}
	return *this;
}
bool AdjMatrix::makeGraphFromFile(ifstream& inputFile, int &s, int &t)
{
	string checker;
	char buffer[SIZE];
	buffer[0] = '\0';
	int size;
	inputFile >> size >> s >> t;
	if (size <= 0 || size < s || size < t)
	{
		return false;
	}
	makeEmptyGraph(size);
	getline(inputFile, checker);

	while (!inputFile.eof())
	{
		getline(inputFile, checker);
		if(checker == "")
		{
			break;
		}
		int v, u;
		float weight;
		sscanf(checker.c_str(), "%d %d %f%s" , &v, &u, &weight, buffer);
		if (!isAdjacent(v, u) && weight >= 0 && (v <= size && u <= size))
		{
			addEdge(v, u, weight);
		}
		else
		{
			return false;
		}
	}
	return true;
	
}
void AdjMatrix::makeEmptyGraph(int _size)
{
	m_Size = _size;
	m_Matrix = new float* [_size * sizeof(float*)];


	for (int i = 0; i < _size; i++)
	{
		m_Matrix[i] = new float[_size * sizeof(float)];
	}

	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			m_Matrix[i][j] = -1;
		}
	}
}
bool AdjMatrix::isAdjacent(int _u, int _v)
{
	if (m_Matrix[_u - 1][_v - 1] != -1)
	{
		return true;
	}
	return false;
}
LinkedList AdjMatrix::getAdjList(int _u)const
{
	LinkedList result;
	Node* newNode;
	result.makeEmpty();

	for (int i = 0; i < m_Size; i++)
	{
		if (m_Matrix[_u - 1][i] != -1)
		{
			newNode = Node::makeNewNode(i + 1, m_Matrix[_u - 1][i]);
			result.insertToTail(newNode);
		}
	}

	return result;
}
Edge* AdjMatrix::getAllEdges(int* resSize)const
{
	int size = 0;
	for(int i=0; i<m_Size; i++)
	{
		for(int j=0; j<m_Size; j++)
		{
			if (m_Matrix[i][j] != -1)
			{
				size++;
			}
		}
	}
	if(0 == size)
	{
		*resSize = 0;
		return nullptr;
	}
	
	Edge* result = new Edge[size];
	int k = 0;
	
	for (int i = 0; i < m_Size; i++)
	{
		for (int j = 0; j < m_Size; j++)
		{
			if (m_Matrix[i][j] != -1)
			{
				result[k].u = i + 1;
				result[k].v = j + 1;
				result[k].w = m_Matrix[i][j];
				k++;
			}
		}
	}

	*resSize = size;
	return result;
}

bool AdjMatrix::addEdge(int _u, int _v, float _w)
{
	if (isAdjacent(_u, _v))
		return false;

	m_Matrix[_u - 1][_v - 1] = _w;
	return true;
}
void AdjMatrix::removeEdge(int _u, int _v)
{
	m_Matrix[_u - 1][_v - 1] = -1;
}

bool AdjMatrix::operator==(const AdjMatrix& other)
{
	bool res = true;
	if (m_Size != other.m_Size)
	{
		res = false;
	}
	for (int i = 0; i < m_Size && res; i++)
	{
		for (int j = 0; j < m_Size && res; j++)
		{
			if (m_Matrix[i][j] != other.m_Matrix[i][j])
			{
				res = false;
			}
		}
	}
	return res;
}
bool AdjMatrix:: operator!=(const AdjMatrix& other)
{
	return !(*this == other);
}



void AdjMatrix::printGraph()
{
	for (int i = 0; i < m_Size; i++)
	{
		for (int j = 0; j < m_Size; j++)
		{
			if (m_Matrix[i][j] != -1)
			{
				std::cout << "weight from " << i + 1 << " to " << j + 1 << " is: " << m_Matrix[i][j] << endl;
			}
		}
	}
}