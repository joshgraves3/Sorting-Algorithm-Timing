#ifndef SORTING_H
#define SORTING_H
#include <iostream>
using namespace std;

class Sorting {
	
	public:
		Sorting(string fileName);
		~Sorting();
		void writeNumsToFile(string fileName);
		void runSortAlgorithms(string file);
		void selectionSort(double* arr, int n);
		void insertionSort(double* myArr, int n);
		void quickSort(double* myArr, int left, int right);

};

#endif