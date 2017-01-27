#include <iostream>
#include "SearchAlgorithms.h"
#include "SortAlgorithms.h"
#include <ctime>
#include <random>
#include <vector>

enum testCase
{
	LINEAR_SEARCH,
	BINARY_SEARCH,
	BUBBLE_SORT,
	SELECTION_SORT
};

void linearSearchTest();
void binarySearchTest();
void bubbleSortTest();
void selectionSortTest();

int main()
{
	testCase test = SELECTION_SORT;

	switch (test)
	{
	case LINEAR_SEARCH:
		linearSearchTest();
		break;

	case BINARY_SEARCH:
		binarySearchTest();
		break;

	case BUBBLE_SORT:
		bubbleSortTest();
		break;

	case SELECTION_SORT:
		selectionSortTest();
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
		std::cout << randomValue << " is on position " << position + 1 << " in list\n";
	else
		std::cout << randomValue << " is not exist in list\n";
}

void binarySearchTest()
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
	bool exist = searchAlgorithms::binarySearchValue(intList, intList[10]);
	if (exist)
		std::cout << intList[10] << " is existed on the list\n";
	else
		std::cout << intList[10] << " is not existed on the list\n";
	std::cout << "\n";

	//Check for invalidate value
	randomValue = rand() % 500 + 1;
	exist = searchAlgorithms::binarySearchValue(intList, randomValue);

	if (exist)
		std::cout << randomValue << " is existed on the list\n";
	else
		std::cout << randomValue << " is not existed on the list\n";

	std::cout << "\n";
	//Get one of the value from the list
	int position = searchAlgorithms::binarySearchIndex(intList, intList[8]);
	if (position != -1)
		std::cout << intList[8] << " is on position " << position << " in list\n";
	else
		std::cout << intList[8] << " is not exist in list\n";
	std::cout << "\n";

	//Check for invalidate value
	randomValue = rand() % 500 + 1;
	position = searchAlgorithms::binarySearchIndex(intList, randomValue);

	if (position != -1)
		std::cout << randomValue << " is on position " << position + 1 << " in list\n";
	else
		std::cout << randomValue << " is not exist in list\n";
}

void bubbleSortTest()
{
	std::cout << "Bubble sort test\n\n";

	//Initialize a empty vector to store value
	std::vector<int>    intList;
	std::vector<double> doubleList;

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
	std::cout << "\n";

	//Sort the list in ascending order
	sortAlgorithms::bubbleSort(intList, true);

	std::cout << "\nAfter sorting in ascending order, the lists contains: ";
	sortAlgorithms::printArray(intList);

	//Sort the list in descending order
	sortAlgorithms::bubbleSort(intList, false);

	std::cout << "\nAfter sorting in descending order, the lists contains: ";
	sortAlgorithms::printArray(intList);

	std::cout << "\n";

	//Push value to the list
	std::cout << "list contains the followings elements: \n";

	double doubleRandomValue;
	for (int iter = 0; iter < 20; ++iter) {
		doubleRandomValue = (rand() % 500 + 1) + iter / 10.;
		doubleList.push_back(doubleRandomValue);
		std::cout << doubleRandomValue << " ";
	}
	std::cout << "\n";

	//Sort the list in ascending order
	sortAlgorithms::bubbleSort(doubleList, true);

	std::cout << "\nAfter sorting in ascending order, the lists contains: ";
	sortAlgorithms::printArray(doubleList);

	//Sort the list in descending order
	sortAlgorithms::bubbleSort(doubleList, false);

	std::cout << "\nAfter sorting in descending order, the lists contains: ";
	sortAlgorithms::printArray(doubleList);

	std::cout << "\n";
}

void selectionSortTest()
{
	std::cout << "Selection sort test\n\n";

	//Initialize a empty vector to store value
	std::vector<int>    intList;
	std::vector<double> doubleList;

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
	std::cout << "\n";

	//Sort the list in ascending order
	sortAlgorithms::selectionSort(intList, true);

	std::cout << "\nAfter sorting in ascending order, the lists contains: ";
	sortAlgorithms::printArray(intList);

	//Sort the list in descending order
	sortAlgorithms::selectionSort(intList, false);

	std::cout << "\nAfter sorting in descending order, the lists contains: ";
	sortAlgorithms::printArray(intList);

	std::cout << "\n";

	//Push value to the list
	std::cout << "list contains the followings elements: \n";

	double doubleRandomValue;
	for (int iter = 0; iter < 20; ++iter) {
		doubleRandomValue = (rand() % 500 + 1) + iter / 10.;
		doubleList.push_back(doubleRandomValue);
		std::cout << doubleRandomValue << " ";
	}
	std::cout << "\n";

	//Sort the list in ascending order
	sortAlgorithms::selectionSort(doubleList, true);

	std::cout << "\nAfter sorting in ascending order, the lists contains: ";
	sortAlgorithms::printArray(doubleList);

	//Sort the list in descending order
	sortAlgorithms::selectionSort(doubleList, false);

	std::cout << "\nAfter sorting in descending order, the lists contains: ";
	sortAlgorithms::printArray(doubleList);

	std::cout << "\n";
}