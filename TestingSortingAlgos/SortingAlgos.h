#pragma once

#include<algorithm>
#include <iostream>
#include<random> 
#include<string> 
#include<vector> 


using std::cout, std::is_sorted, std::string, std::vector;
using std::mt19937, std::random_device;


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


quickSort(vector<string>& vectorOfStrings);

void printVec(const vector<string> strings);