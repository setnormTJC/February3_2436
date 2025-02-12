// SortingObjectsOfAClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<algorithm>
#include<iomanip>
#include <iostream>
#include<vector>


class Poem
{
public: 
	int numberOfLines; 
	bool doesItRhyme; 
	std::string author; 

	Poem() = default; 
	Poem(int numberOfLines, bool doesItRhyme, std::string author)
		:numberOfLines(numberOfLines), doesItRhyme(doesItRhyme), author(author)
		//member-initilaizer syntax
	{
		//empty
	}

};

void printPoems(const std::vector<Poem>& poems)
{
	for (const Poem& currentPoem : poems)
	{
		std::cout << std::left << std::setw(6) << currentPoem.numberOfLines; 
		std::boolalpha; 
		std::cout << std::left << std::setw(6) << currentPoem.doesItRhyme;
		std::cout << std::left << std::setw(25) << currentPoem.author; 
		std::cout << "\n";
	}
}

int main()
{
	Poem oneRing{ 4, true, "JRR Tolkien" };

	std::vector<Poem> poems =
	{
		oneRing,
		Poem(20, true, "Dromgoole"), //this is constructing an "anonymous object" inplace
		Poem(10, true, "Author of Kilkenny cats"),
		Poem(12312, false, "some poem")
	}; 

	std::cout << "The ORIGINAL (unsorted) list\n";
	printPoems(poems);

	std::sort(poems.begin(), poems.end(), 
		[]
		(const Poem& firstPoem, const Poem& secondPoem)
		{
			return firstPoem.author < secondPoem.author; 
		}); //custom comparator required 

	std::cout << "\n\nsorted by author...?\n"; 
	printPoems(poems); 
}
