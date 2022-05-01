#include "PriorityQueueArray.h"

PriorityQueueArray::PriorityQueueArray(VertexDistance* arr, int n)
{
	_currSize = n;
	_data = arr;

	for (int i = 0; i < n; i++)
	{
		if (_data[i].d == 0) // first minimum is the vertex with 0 as d
		{
			_currMin = _data[i];
			_indexMin = i;
			break;
		}
	}
}

PriorityQueueArray::~PriorityQueueArray()
{
	// if no allocated
	_currSize = 0;
	_data = nullptr;
	
}

void PriorityQueueArray::makeEmpty()
{
	_currSize = 0;
	_data = nullptr;
}

bool PriorityQueueArray::isEmpty() const
{
	return (_currSize==0);
}

//void PriorityQueueArray::Insert(float d, int vertexNum)
//{
//
//}

void PriorityQueueArray::decreaseKey(int v, float distance)
{
	for(int i=0; i<_currSize;i++)
	{
		if (_data[i].vertexNum == v)
		{
			_data[i].d = distance;

			if (_currMin.d == -1)
			{
				_currMin = _data[i];
				_indexMin = i;
			}
			else
			{
				if (_data[i].d < _currMin.d)
				{
					_currMin = _data[i];
					_indexMin = i;
				}
			}
		}
	}
}

VertexDistance PriorityQueueArray::min() const
{
	return _currMin;
}

VertexDistance PriorityQueueArray::deleteMin()
{
	VertexDistance res = _currMin;
	for (int i = _indexMin; i < _currSize-1; i++)
	{
		if (_currMin.vertexNum == _data[i + 1].vertexNum && _currMin.d == _data[i + 1].d)
		{
			_indexMin = i + 1;
		}
		_data[i] = _data[i + 1];
	
	}
	_currSize--;
	if (_currSize != 0)
	{
		_currMin = _data[0];
		_indexMin = 0;
		for (int i = 1; i < _currSize; i++)
		{
			if (_currMin.d == -1)
			{
				if (_data[i].d != -1)
				{
					_currMin = _data[i];
					_indexMin = i;
				}
			}
			else
			{
				if (_currMin.d > _data[i].d && _data[i].d != -1)
				{
					_currMin = _data[i];
					_indexMin = i;
				}
			}
		}
	}
	return res;
}
