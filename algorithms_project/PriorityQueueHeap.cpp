#include"PriorityQueueHeap.h"

PriorityQueueHeap::PriorityQueueHeap(int max)
{

	_data = new VertexDistance[max];
	_maxSize = max;
	_heapSize = 0;
	_allocated = 1;
}
PriorityQueueHeap::PriorityQueueHeap(VertexDistance* arr, int n)
{
	buildHeap(arr, n);
}
PriorityQueueHeap::~PriorityQueueHeap()
{
	makeEmpty();
}

float PriorityQueueHeap::getDistance(VertexDistance vertex)
{
	return vertex.d;
}

void PriorityQueueHeap::buildHeap(VertexDistance* arr, int n)
{
	_heapSize = _maxSize = n;
	_data = arr;
	_allocated = 0;

	for (int i = n / 2 - 1; i >= 0; i--)
		fixHeap(i);
}

void PriorityQueueHeap::fixHeap(int node)
{
	int min=node;
	int left = Left(node);
	int right = Right(node);
	if (left < _heapSize)
	{
		if (_data[node].d != -1 && _data[left].d == -1)
			min = node;
		else if (_data[node].d != -1 && _data[left].d != -1)
		{
			if (_data[node].d > _data[left].d)
				min = left;
			else
			{
				min = node;
			}
		}
		else if(_data[left].d !=-1)
		{
			min = left;
		}
		else
		{
			min = node;
		}
	}
	if (right < _heapSize)
	{
		if (_data[min].d != -1 && _data[right].d != -1)
		{
			if (_data[min].d > _data[right].d)
				min = right;
			
		}
		else if (_data[min].d != -1 && _data[right].d == -1)
			min = min;
	
		else if (_data[right].d != -1)
		{
			min = right;
		}
		
	}
	if (min != node)
	{
		swap(&_data[node], &_data[min]);
		fixHeap(min);
	}
}

int PriorityQueueHeap::Left(int node)
{
	return (2 * node + 1);
}
int PriorityQueueHeap::Right(int node)
{
	return (2 * node + 2);
}
int PriorityQueueHeap::Parent(int node)
{
	return (node - 1) / 2;
}
void PriorityQueueHeap::makeEmpty()
{
	if (_allocated)
		delete[] _data;

	_data = nullptr;
}
VertexDistance PriorityQueueHeap::min()const
{
	return _data[0];
}
VertexDistance PriorityQueueHeap::deleteMin()
{
	VertexDistance min = _data[0];
	_heapSize--;
	_data[0] = _data[_heapSize];
	fixHeap(0);
	return (min);
}
void PriorityQueueHeap::insert(VertexDistance item)
{
	if (_heapSize == _maxSize)
		return;
	int i = _heapSize;
	_heapSize++;

	while ((i > 0) && (_data[Parent(i)].d > item.d))
	{
		_data[i] = _data[Parent(i)];
		i = Parent(i);
	}
	_data[i] = item;
}
void PriorityQueueHeap::decreaseKey(int v, float distance)
{
	for (int i = 0; i < _heapSize; i++)
	{
		if (_data[i].vertexNum == v)
		{
			_data[i].d = distance;
			int k = i;
			while ((k > 0) && ((_data[Parent(k)].d == -1)||(_data[Parent(k)].d > _data[k].d)))
			{
				swap(&_data[k], &_data[Parent(k)]);
				k = Parent(k);
		
			}
			

		}
	}
}
bool PriorityQueueHeap::isEmpty()const
{
	return !(_heapSize);
}

void PriorityQueueHeap::swap(VertexDistance* a, VertexDistance* b)
{
	VertexDistance temp = *a;
	*a = *b;
	*b = temp;
}