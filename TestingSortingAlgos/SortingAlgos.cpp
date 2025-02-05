#include "SortingAlgos.h"

void MiracleSort(vector<string>& strings)
{
	while (!is_sorted(strings.begin(), strings.end()))
	{
		//wait for Zeus to come down from Olympus and sort the array
	}
}


int MonkeySort(vector<string>& strings)
{
	random_device rd{}; 
	mt19937 rng(rd());


	int shuffleCount = 0; 
	while (!is_sorted(strings.begin(), strings.end()))
	{
		//shuffle and hope for the best: 
		std::shuffle(strings.begin(), strings.end(), rng);
		shuffleCount++; 

		//printVec(strings); 

	}

	std::cout << "It took this many shuffles to get sorted: " << shuffleCount << "\n";

	return shuffleCount; 
}

void naiveSort(vector<string>& vectorOfStrings)
{
	for (int outer = 0; outer < vectorOfStrings.size() - 1; ++outer)
	{
		for (int inner = outer + 1; inner < vectorOfStrings.size(); ++inner)
		{
			if (vectorOfStrings[inner] < vectorOfStrings[outer])
			{
				std::swap(vectorOfStrings[inner], vectorOfStrings[outer]);

				printVec(vectorOfStrings); 
			}
		}
	}
}


void printVec(const vector<string> strings)
{
	for (const auto& string : strings)
	{
		cout << string << " ";
	}
	cout << "\n";
}
