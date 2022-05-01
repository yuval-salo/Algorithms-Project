#pragma once
#include"Global.h"

class PriorityQueueHeap {
private:
	VertexDistance* _data;   // Pointer to data array.
	int _maxSize; // Max size of heap.
	int _heapSize; // current size of heap.
	int _allocated; // 1 if heap allocated memory.
	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
	void fixHeap(int node);

public:
	PriorityQueueHeap() :_data(nullptr), _maxSize(0), _heapSize(0), _allocated(-1) {}
	PriorityQueueHeap(int max); // Allocate memory.
	PriorityQueueHeap(VertexDistance* arr, int n); //Turn arr into heap.
	~PriorityQueueHeap();
	float getDistance(VertexDistance vertex);
	void buildHeap(VertexDistance* arr, int n); //create the heap by using floyd algorithem.
	VertexDistance min()const;                   // return the minimum of the heap.
	VertexDistance deleteMin();                  // delete and return the minimum of the heap.
	void insert(VertexDistance item);            // insert a new node into the heap.
	void decreaseKey(int v, float distance);
	void makeEmpty();
	bool isEmpty()const;

	void swap(VertexDistance* a, VertexDistance* b);
};