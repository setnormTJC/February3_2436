#pragma once

#include<algorithm>
#include <iostream>
#include<random> 
#include<string> 
#include<vector> 


using std::cout, std::is_sorted, std::string, std::vector;
using std::mt19937, std::random_device;


std::vector<int> generateNRandomNumsBetween0AndN(int N);

/*O(infinity) */
void MiracleSort(vector<string>& strings);

/*
On average, this algo has complexity O(N!). In the BEST case (array is already sorted), it is O(N) 
@returns the number of shuffles it took to get sorted
*/
int MonkeySort(vector<string>& strings);

/*
@param this overload takes INTS
*/
//void naiveSort(vector<int>& nums);

/*
This algorithm has O(N^2) complexity in the average case.  
@param this overload takes STRINGS
*/
void naiveSort(vector<string>& vectorOfStrings);

void naiveSort(vector<int>& vectorOfNums);

template<typename T>
int partition(vector<T>& list, int first, int last)
{
	T pivot;
	//using T here may alleviate confusing indices with elements!

	int index, smallIndex;

	std::swap(list[first], list[(first + last) / 2]);
	pivot = list[first];
	smallIndex = first;

	for (index = first + 1; index <= last; index++)
	{
		if (list[index] < pivot)
		{
			smallIndex++;
			std::swap(list[index], list[smallIndex]);
		}
	}
	std::swap(list[first], list[smallIndex]);

	return smallIndex;
}

template<typename T>
void quickSort(vector<T>& list, int first, int last)
{
	int pivotLocation;

	if (first < last)
	{
		pivotLocation = partition(list, first, last);
		//DIVIDE/partition and conquer!
		quickSort(list, first, pivotLocation - 1); //lower sublist
		//sorts lesser/left ~half of array (if setting pivot to middle)  
		quickSort(list, pivotLocation + 1, last); //upper sublist ("right" half if ascending sort)
	}
}



void printVec(const vector<string> strings);

void printVec(const vector<int>& nums);