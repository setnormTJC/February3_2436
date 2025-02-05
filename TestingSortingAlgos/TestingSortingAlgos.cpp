// TestingSortingAlgos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include"SortingAlgos.h"

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

int main()
{
	vector<string> names =
	{
		"Alice",
		"Carol",
		"Bob", 
		"Darth", 
		"Eve"
	};

	demoMonkeySort(names); 

	//so how much better is the `naiveSort`? 
	//naiveSort(names); 

}

