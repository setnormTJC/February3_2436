// TestingSortingAlgos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include"SortingAlgos.h"

#include<chrono> 
#include<iomanip>

void demoMonkeySort(vector<string> names)
{
	vector<string> copyOfNames = names; 

	constexpr int NUMBER_OF_EXPERIMENTS = 1000; 

	int totalShufflesSoFar = 0; 

	for (int i = 0; i < NUMBER_OF_EXPERIMENTS; ++i)
	{

		int numberOfShufflesThisExperimentTook = MonkeySort(names); 

		totalShufflesSoFar += numberOfShufflesThisExperimentTook;

		//reset to the unsorted list for additional testing: 
		names = copyOfNames;

	}

	cout << "\n\nAVERAGE number of shuffles for " << NUMBER_OF_EXPERIMENTS << " experiments: "
		<< totalShufflesSoFar / NUMBER_OF_EXPERIMENTS<< "\n";

}

void demoNSquaredComparisonsForNaiveSort()
{
	vector<string> names =
	{
		"innovation",
		"ton",
		"first",
		"inappropriate",
		"jury",
		"retailer",
		"interrupt",
		"shallow",
		"technique",
		"death"
	};

	for (int i = 0; i < 90; ++i)
	{
		names.push_back(std::to_string(i));
	}

	naiveSort(names);


	//for N = 100, 4950 comparisons will be done
	//NOTE that sum (i) from i = 0 to N = N(N-1)/2 (an equation from "math class") 
	//and N(N - 1)/2 ~= N^2

}


void compareNaiveAndQuickSortPerformance()
{
	//Let's compare naive sort's execution time to quicksort:
//(We expect quicksort to be QUICKER)

	constexpr int N = 100'000; //0 - 100'000

	auto vecN = generateNRandomNumsBetween0AndN(N);
	auto copyOfVecN = vecN; //


	auto startQuickSortTimer = std::chrono::high_resolution_clock::now();
	quickSort(vecN, 0, vecN.size() - 1);
	auto stopQuickSortTimer = std::chrono::high_resolution_clock::now();

	cout << std::fixed << std::setprecision(2);
	cout << "It took this many nanoseconds for quicksort: "
		<< (stopQuickSortTimer - startQuickSortTimer).count() << "\n";


	//so now, let's compare naiveSort: 
	auto startNaiveSortTimer = std::chrono::high_resolution_clock::now();
	naiveSort(copyOfVecN);
	auto stopNaiveSortTimer = std::chrono::high_resolution_clock::now();

	cout << "For naive sort, THIS many ns were required: "
		<< (stopNaiveSortTimer - startNaiveSortTimer).count();

}

int main()
{
	constexpr int N = 1024; 
	vector<int> nums1024 = generateNRandomNumsBetween0AndN(N); 

	quickSort(nums1024, 0, nums1024.size() - 1); 



	//compareNaiveAndQuickSortPerformance(); 

	//std::sort(nums.begin(), nums.end()); //black box - how does this work? 
	//printVec(vecN); 

	//MiracleSort(names); 

	//demoMonkeySort(names); 

	//so how much better is the `naiveSort`? 
	//naiveSort(names); 

}

