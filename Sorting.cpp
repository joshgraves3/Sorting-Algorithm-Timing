#include "Sorting.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <ctime>

Sorting::Sorting(string fileName) {
	writeNumsToFile(fileName); //create the file 
	runSortAlgorithms(fileName); //run the sort algorithms on the written data
}

Sorting::~Sorting() {}

//write 100,000 random doubles to a file to be sorted
void Sorting::writeNumsToFile(string fileName) {

	ofstream writer(fileName);
	
	if (writer.is_open())
	{
		writer << 10000 << endl;
		for (int i = 0; i < 10000; ++i)
		{
			double random = (double)rand() / (double)RAND_MAX;
			writer << random << endl;
		}
	}
	else
	{
		cout << "File does not exist." << endl;
	}

	writer.close();
}

//run all of the algorithms
void Sorting::runSortAlgorithms(string file) {
	ifstream reader(file);
	
	if (reader.is_open())
	{

		string line;
		int counter = 0;
		int index = 0;
		int index2 = 0;
		int index3 = 0;
		int sizeOfArray;
		double* arr1;
		double* arr2; //make 3 arrays to sort them different ways
		double* arr3;

		while(getline(reader,line)) {
			if (counter == 0)
			{
				sizeOfArray = stoi(line);
				arr1 = (double*) malloc(sizeOfArray*sizeof(double)); //allocate memory for the arrays
				arr2 = (double*) malloc(sizeOfArray*sizeof(double));
				arr3 = (double*) malloc(sizeOfArray*sizeof(double));
			}
			else 
			{
				arr1[index++] = stod(line); //feed the doubles into the arrays 
				arr2[index2++] = stod(line);
				arr3[index3++] = stod(line);

			}
			counter++;
		}
		reader.close();

		selectionSort(arr1, sizeOfArray); //call the different sorting algorithms
		insertionSort(arr2, sizeOfArray);
		cout << "Quick Sort" << endl;
		clock_t begin = clock();
		cout << "	Time started: " << begin << endl;
		quickSort(arr3, 0, sizeOfArray-1);
		clock_t end = clock();
		cout << "	Time ended: " << end << endl;
		cout << "	Time elapsed: " << end - begin << endl;

		free(arr1); //free the allocated memory
		free(arr2);
		free(arr3);
	}
	else
	{
		cout << "File does not exist." << endl;
	}
}

void Sorting::selectionSort(double* myArr, int n) {
	cout << "Selection Sort" << endl;
	clock_t begin = clock();
	cout << "	Time started: " << begin << endl;

	for (int i = 0; i < n; ++i)
	{
		double smallestValue = myArr[i]; //keep track of the smallest value
		int smallestIndex = i; //keep track of where in the array the smallest value is 

		for (int j = i; j < n; ++j) //start at beginning
		{
			if (myArr[j] < smallestValue) //if you find a smaller value, change smallestValue and smallestIndex
			{
				smallestValue = myArr[j];
				smallestIndex = j;
			}
		}
		myArr[smallestIndex] = myArr[i]; //swap in the smaller value to where it should be 
		myArr[i] = smallestValue;
	}

	clock_t end = clock();
	cout << "	Time ended: " << end << endl;
	cout << "	Time elapsed: " << end - begin << endl;
}

void Sorting::insertionSort(double* myArr, int n) {
	cout << "Insertion Sort" << endl;
	clock_t begin = clock();
	cout << "	Time started: " << begin << endl;

	for (int i = 1; i < n; ++i)
	{
		double temp = myArr[i]; //temp to hold the value 
		int j = i;
		while (j > 0 && myArr[j-1] >= temp) {
			myArr[j] = myArr[j-1]; //swap the smaller values to the "sorted" (left) part of the array
			--j;
		}
		myArr[j] = temp;
	}

	clock_t end = clock();
	cout << "	Time ended: " << end << endl;
	cout << "	Time elapsed: " << end - begin << endl;
}

void Sorting::quickSort(double* myArr, int left, int right) {

	int i = left;
	int j = right;
	double temp;
	double pivot = myArr[(left+right)/2];
	while (i <= j) {
		while (myArr[i] < pivot) {
			i++; //move left index until you get a number that is bigger than the pivot
		}
		while (myArr[j] > pivot) {
			j--; //move right index until you get a number that is smaller than the pivot
		}
		if (i <= j) //if i <= j, swap the values to be on the correct side of the pivot and move to the next place from each side 
		{
			temp = myArr[i]; 
			myArr[i] = myArr[j];
			myArr[j] = temp;
			i++;
			j--;
		}
	}

	if (left < j)
	{
		quickSort(myArr, left, j); //quickSort a smaller partition
	}
	if (i < right)
	{
		quickSort(myArr, i, right); //quickSort a smaller partition
	}
}




