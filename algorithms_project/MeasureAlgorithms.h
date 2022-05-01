#include<iostream>
#include<fstream>
#include <iomanip>
#include <chrono>
#include "Algorithms.h"
using namespace std;
#define REF


class MeasureAlgorithms {
public:
	static void Measure_Adjacency_Dijkstra_heap(const AdjList& graphList, int _s, int _t, string outTextName);
	static void Measure_Adjacency_Dijkstra_array(const AdjList& graphList, int _s, int _t, string outTextName);
	static void Measure_Adjacency_Bellman_Ford(const AdjList& graphList, int _s, int _t, string outTextName);
	static void Measure_Matrix_Dijkstra_heap(const AdjMatrix& graphList, int _s, int _t, string outTextName);
	static void Measure_Matrix_Dijkstra_array(const AdjMatrix& graphList, int _s, int _t, string outTextName);
	static void Measure_Matrix_Bellman_Ford(const AdjMatrix& Mat, int _s, int _t, string outTextName);

};