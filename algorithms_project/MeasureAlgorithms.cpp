#include "MeasureAlgorithms.h"

void MeasureAlgorithms::Measure_Adjacency_Dijkstra_heap(const AdjList& graphList, int _s, int _t,  string outTextName)
{
	float result;
	auto start = chrono::high_resolution_clock::now();

	// unsync the I/O of C and C++. 
	ios_base::sync_with_stdio(false);

	result = Algorithms::dijkstraListHeap(REF graphList, _s, _t);// Here you put the name of the function you wish to measure

	auto end = chrono::high_resolution_clock::now();

	// Calculating total time taken by the program. 
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	ofstream myfile(outTextName); // The name of the file which is in argv[2]

	myfile << "Time taken by function Adjacency Dijkstra heap is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();

	cout << "Adjacency Dijkstra heap " << result << endl;
}
void MeasureAlgorithms::Measure_Adjacency_Dijkstra_array(const AdjList& graphList, int _s, int _t, string outTextName)
{
	float result;

	auto start = chrono::high_resolution_clock::now();

	// unsync the I/O of C and C++. 
	ios_base::sync_with_stdio(false);

	result = Algorithms::dijkstraListArray(REF graphList, _s, _t);// Here you put the name of the function you wish to measure

	auto end = chrono::high_resolution_clock::now();

	// Calculating total time taken by the program. 
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	ofstream myfile(outTextName, std::ios_base::app); // The name of the file which is in argv[2]

	myfile << "Time taken by function Adjacency Dijkstra array is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();

	cout << "Adjacency Dijkstra array " << result << endl;

}
void MeasureAlgorithms::Measure_Adjacency_Bellman_Ford(const AdjList& graphList, int _s, int _t, string outTextName)
{
	float result;

	auto start = chrono::high_resolution_clock::now();

	// unsync the I/O of C and C++. 
	ios_base::sync_with_stdio(false);

	result = Algorithms::bellmanFordList(REF graphList, _s, _t);// Here you put the name of the function you wish to measure

	auto end = chrono::high_resolution_clock::now();

	// Calculating total time taken by the program. 
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	ofstream myfile(outTextName, std::ios_base::app); // The name of the file which is in argv[2]

	myfile << "Time taken by function Adjacency Bellman Ford is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();

	cout << "Adjacency Bellman Ford " << result << endl;

}
void MeasureAlgorithms::Measure_Matrix_Dijkstra_heap(const AdjMatrix& Mat, int _s, int _t, string outTextName)
{
	float result;

	auto start = chrono::high_resolution_clock::now();

	// unsync the I/O of C and C++. 
	ios_base::sync_with_stdio(false);

	result = Algorithms::dijkstraMatrixHeap(REF Mat, _s, _t);// Here you put the name of the function you wish to measure

	auto end = chrono::high_resolution_clock::now();

	// Calculating total time taken by the program. 
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	ofstream myfile(outTextName, std::ios_base::app); // The name of the file which is in argv[2]

	myfile << "Time taken by function Matrix Dijkstra heap is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();

	cout << "Matrix Dijkstra heap " << result << endl;

}
void MeasureAlgorithms::Measure_Matrix_Dijkstra_array(const AdjMatrix& Mat, int _s, int _t, string outTextName)
{
	float result;

	auto start = chrono::high_resolution_clock::now();

	// unsync the I/O of C and C++. 
	ios_base::sync_with_stdio(false);

	result = Algorithms::dijkstraMatrixArray(REF Mat, _s, _t);// Here you put the name of the function you wish to measure

	auto end = chrono::high_resolution_clock::now();

	// Calculating total time taken by the program. 
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	ofstream myfile(outTextName, std::ios_base::app); // The name of the file which is in argv[2]

	myfile << "Time taken by function Matrix Dijkstra array is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();

	cout << "Matrix Dijkstra array " << result << endl;

}
void MeasureAlgorithms::Measure_Matrix_Bellman_Ford(const AdjMatrix& Mat, int _s, int _t, string outTextName)
{

	float result;

	auto start = chrono::high_resolution_clock::now();

	// unsync the I/O of C and C++. 
	ios_base::sync_with_stdio(false);

	result = Algorithms::bellmanFordMatrix(REF Mat, _s, _t);// Here you put the name of the function you wish to measure

	auto end = chrono::high_resolution_clock::now();

	// Calculating total time taken by the program. 
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	ofstream myfile(outTextName, std::ios_base::app); // The name of the file which is in argv[2]

	myfile << "Time taken by function Matrix Bellman Ford is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();

	cout << "Matrix Bellman Ford " << result << endl;

}
