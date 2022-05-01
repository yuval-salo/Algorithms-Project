#include"AdjList.h"
#include <string>
#define SIZE 50

AdjList::~AdjList()
{
	delete[] m_arr;
}
AdjList::AdjList(const AdjList& other)
{
	*this = other;
}
const AdjList& AdjList::operator=(const AdjList& other)
{
	if (this != &other)
	{
		m_Size = other.m_Size;
		m_arr = new Vertex[m_Size];
		for (int i = 0; i < m_Size; i++)
		{
			m_arr[i] = other.m_arr[i];
		}
	}
	return *this;
}

bool AdjList::makeGraphFromFile(ifstream& inputFile)
{
	string checker;
	char buffer[SIZE];
	buffer[0] = '\0';
	int s, t, size;
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
		if (checker[0] == '\0')
		{
			break;
		}
		int v, u;
		float weight;
		sscanf(checker.c_str(), "%d %d %f%s", &v, &u, &weight, buffer);
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


void AdjList::makeEmptyGraph(int _size)
{
	m_arr = new Vertex[_size];
	m_Size = _size;
}
bool AdjList::isAdjacent(int _u, int _v)
{
	return (m_arr[_u - 1].ListOfAdj.isInTheList(_v));
}
Edge* AdjList::getAllEdges(int* resSize) const
{
	int size = 0;
	for (int i = 0; i < m_Size; i++)
	{
		Node* temp = m_arr[i].ListOfAdj.getHead();
		while (temp!=nullptr)
		{
			size++;
			temp = temp->_next;
		}
	}
	if (0 == size)
	{
		*resSize = 0;
		return nullptr;
	}

	Edge* result = new Edge[size];
	int k = 0;

	for (int i = 0; i < m_Size; i++)
	{
		Node* temp = m_arr[i].ListOfAdj.getHead();
		while (temp != nullptr)
		{
			result[k].u = i + 1;
			result[k].v = temp->_verNum;
			result[k].w = temp->_weight;
			temp = temp->_next;
			k++;
		}
	}

	*resSize = size;
	return result;
}
void AdjList::addEdge(int _u, int _v, float _w)
{
	Node* newNode = Node::makeNewNode(_v, _w, nullptr);
	m_arr[_u - 1].ListOfAdj.insertToTail(newNode);
	
}
const LinkedList& AdjList::getAdjList(int _u)const
{
	return m_arr[_u - 1].ListOfAdj;
}
void AdjList::printGraph()
{
	for (int i = 0; i < m_Size; i++)
	{
		cout << "The adj of vertex " << i + 1 << " are:\n " << m_arr[i].ListOfAdj << endl;

	}
}

