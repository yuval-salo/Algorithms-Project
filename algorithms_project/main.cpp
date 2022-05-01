#include"Global.h"
#include"MeasureAlgorithms.h"
#include"InputValidation.h"
/*
The program receives graph data from a text file, builds a graph, once as a Adjacency matrix and once
As Adjacency list.
The program implements a number of solutions to the problem of minimum distances from origin Single to single destination:

1.Adjacency Dijkstra heap 
2.Adjacency Dijkstra array
3.Adjacency Bellman Ford 
4.Matrix Dijkstra heap
5.Matrix Dijkstra array
6.Matrix Bellman Ford

The program analyzes the differences between the different solutions in terms of running times.
Prints on screen the minimum path weight from s to t in each of the different implementations, and prints
the file named in the second argument has the runtime in each of the 6 implementations.
*/
	
	
int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Invalid input";
		exit(1);
	}
	AdjMatrix matrix;
	AdjList list;
	int s, t;
	if (!input_validation(argv[1],REF matrix ,REF list, REF s, REF t))
	{
		cout << "Invalid input";
		exit(1);
	}
	string outTextName = argv[2];
	MeasureAlgorithms::Measure_Adjacency_Dijkstra_heap(list, s, t, outTextName);
	MeasureAlgorithms::Measure_Adjacency_Dijkstra_array(list, s, t, outTextName);
	MeasureAlgorithms::Measure_Adjacency_Bellman_Ford(list, s, t, outTextName);
	MeasureAlgorithms::Measure_Matrix_Dijkstra_heap(matrix, s, t, outTextName);
	MeasureAlgorithms::Measure_Matrix_Dijkstra_array(matrix, s, t, outTextName);
	MeasureAlgorithms::Measure_Matrix_Bellman_Ford(matrix, s, t, outTextName);
	return 0;
}


