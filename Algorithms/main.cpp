#include <iostream>
#include "SearchAlgorithms.h"
#include <ctime>
#include <random>
#include <vector>

enum testCase
{
	LINEAR_SEARCH
};

void linearSearchTest();

int main()
{
	testCase test = LINEAR_SEARCH;

	switch (test)
	{
	case LINEAR_SEARCH:
		linearSearchTest();
		break;

	default:
		break;
	}

	std::cin.ignore();

	return 0;
}

void linearSearchTest()
{
	std::cout << "Linear search test\n\n";

	//Initialize a empty vector to store value
	std::vector<int> intList;

	//initialize random seeds
	srand((unsigned int)time(NULL));

	//Push value to the list
	std::cout << "list contains the followings elements: \n";
	int randomValue;
	for (int iter = 0; iter < 20; ++iter) {
		randomValue = rand() % 250 + 1;
		intList.push_back(randomValue);
		std::cout << randomValue << " ";
	}
	std::cout << "\n\n";

	//Get one of the value from the list
	bool exist = searchAlgorithms::linearSearchValue(intList, intList[10]);
	if (exist)
		std::cout << intList[10] << " is existed on the list\n";
	else
		std::cout << intList[10] << " is not existed on the list\n";
	std::cout << "\n";

	//Check for invalidate value
	randomValue = rand() % 500 + 1;
	exist = searchAlgorithms::linearSearchValue(intList, randomValue);

	if(exist)
		std::cout << randomValue << " is existed on the list\n";
	else
		std::cout << randomValue << " is not existed on the list\n";

	std::cout << "\n";
	//Get one of the value from the list
	int position = searchAlgorithms::linearSearchIndex(intList, intList[8]);
	if (position != -1)
		std::cout << intList[8] << " is on position " << position << " in list\n";
	else
		std::cout << intList[8] << " is not exist in list\n";
	std::cout << "\n";

	//Check for invalidate value
	randomValue = rand() % 500 + 1;
	position = searchAlgorithms::linearSearchIndex(intList, randomValue);
	
	if (position != -1)
		std::cout << randomValue << " is on position " << position << " in list\n";
	else
		std::cout << randomValue << " is not exist in list\n";


}