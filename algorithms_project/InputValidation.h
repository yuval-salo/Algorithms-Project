#pragma once
#include"Global.h"


bool input_validation(char* inputName, AdjMatrix& A, AdjList& B, int& s, int& t)
{
	int size;

	ifstream  inputFile;
	inputFile.open(inputName);
	if (!inputFile)
	{
		return false;
	}
	bool res = A.makeGraphFromFile(inputFile, REF s, REF t);
	inputFile.seekg(0);
	if (res)
	{
		B.makeGraphFromFile(inputFile);
	}
	return res;
}


