#include "SortingAlgos.h"

std::vector<int> generateNRandomNumsBetween0AndN(int N)
{
	std::vector<int> randomNumbers;
	std::random_device rd;
	std::mt19937 generator(rd());

	std::uniform_int_distribution<> distribution(0, N);

	for (int i = 0; i < N; ++i) {
		randomNumbers.push_back(distribution(generator));
	}

	return randomNumbers;
}

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
	int comparisonCounter = 0; 
	int swapCounter = 0; 

	for (int outer = 0; outer < vectorOfStrings.size() - 1; ++outer)
	{
		for (int inner = outer + 1; inner < vectorOfStrings.size(); ++inner)
		{
			comparisonCounter++; 

			if (vectorOfStrings[inner] < vectorOfStrings[outer]) //our comparison operation 
			{
				std::swap(vectorOfStrings[inner], vectorOfStrings[outer]); //our swap op. 
				swapCounter++; 

				//printVec(vectorOfStrings); 
			}
		}
	} //end outer loop 
	
	cout << "TOTAL comparisons: " << comparisonCounter << "\n";
	cout << "Total SWAPS: " << swapCounter << "\n";

}

void naiveSort(vector<int>& vectorOfNums)
{
	int comparisonCounter = 0;
	int swapCounter = 0;

	for (int outer = 0; outer < vectorOfNums.size() - 1; ++outer)
	{
		for (int inner = outer + 1; inner < vectorOfNums.size(); ++inner)
		{
			comparisonCounter++;

			if (vectorOfNums[inner] < vectorOfNums[outer]) //our comparison operation 
			{
				std::swap(vectorOfNums[inner], vectorOfNums[outer]); //our swap op. 
				swapCounter++;
			}
		}
	} //end outer loop 

	cout << "TOTAL comparisons: " << comparisonCounter << "\n";
	cout << "Total SWAPS: " << swapCounter << "\n";

}


void printVec(const vector<string> strings)
{
	for (const auto& string : strings)
	{
		cout << string << " ";
	}
	cout << "\n";
}

void printVec(const vector<int>& nums)
{
	for (const auto& num : nums)
	{
		cout << num << " ";
	}
	cout << "\n";
}
