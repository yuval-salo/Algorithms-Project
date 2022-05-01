#pragma once
#include"Global.h"


class PriorityQueueArray
{
private:
	VertexDistance* _data;
	int _currSize;
	VertexDistance _currMin;
	int _indexMin;

public:
	PriorityQueueArray() :_data(nullptr), _currSize(0), _indexMin(-1), _currMin({ 0,0 }) {}
	PriorityQueueArray(VertexDistance* arr, int n);
	~PriorityQueueArray();
	void makeEmpty();
	bool isEmpty()const;
	//void Insert(float d, int vertexNum);
	void decreaseKey(int v, float distance);
	VertexDistance min()const;              
	VertexDistance deleteMin();

};


