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
	SELECTION_SORT,
	INSERTION_SORT,
	SHELL_SORT,
	MERGE_SORT,
	QUICK_SORT,
	COUNTING_SORT,
	RADIX_SORT,
	BUCKET_SORT
};

void linearSearchTest();
void binarySearchTest();
void bubbleSortTest();
void selectionSortTest();
void insertionSortTest();
void shellSortTest();
void mergeSortTest();
void quickSortTest();
void countingSortTest();
void radixSortTest();
void bucketSortTest();

int main()
{
	testCase test = BUCKET_SORT;

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

	case INSERTION_SORT:
		insertionSortTest();
		break;

	case SHELL_SORT:
		shellSortTest();
		break;

	case MERGE_SORT:
		mergeSortTest();
		break;

	case QUICK_SORT:
		quickSortTest();
		break;

	case COUNTING_SORT:
		countingSortTest();
		break;

	case RADIX_SORT:
		radixSortTest();
		break;

	case BUCKET_SORT:
		bucketSortTest();
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

void insertionSortTest()
{
	std::cout << "Insertion sort test\n\n";

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
	sortAlgorithms::insertionSort(intList, true);

	std::cout << "\nAfter sorting in ascending order, the lists contains: ";
	sortAlgorithms::printArray(intList);

	//Sort the list in descending order
	sortAlgorithms::insertionSort(intList, false);

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
	sortAlgorithms::insertionSort(doubleList, true);

	std::cout << "\nAfter sorting in ascending order, the lists contains: ";
	sortAlgorithms::printArray(doubleList);

	//Sort the list in descending order
	sortAlgorithms::insertionSort(doubleList, false);

	std::cout << "\nAfter sorting in descending order, the lists contains: ";
	sortAlgorithms::printArray(doubleList);

	std::cout << "\n";
}

void shellSortTest()
{
	std::cout << "Shell sort test\n\n";

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
	sortAlgorithms::shellSort(intList, true);

	std::cout << "\nAfter sorting in ascending order, the lists contains: ";
	sortAlgorithms::printArray(intList);

	//Sort the list in descending order
	sortAlgorithms::shellSort(intList, false);

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
	sortAlgorithms::shellSort(doubleList, true);

	std::cout << "\nAfter sorting in ascending order, the lists contains: ";
	sortAlgorithms::printArray(doubleList);

	//Sort the list in descending order
	sortAlgorithms::shellSort(doubleList, false);

	std::cout << "\nAfter sorting in descending order, the lists contains: ";
	sortAlgorithms::printArray(doubleList);

	std::cout << "\n";
}

void mergeSortTest()
{
	std::cout << "Merge sort test\n\n";

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
	sortAlgorithms::MergeSort<int> mergeIntSort(intList);
	mergeIntSort.sort(true);

	std::cout << "\nAfter sorting in ascending order, the lists contains: ";
	mergeIntSort.printArray();

	//Sort the list in descending order
	mergeIntSort.sort(false);

	std::cout << "\nAfter sorting in descending order, the lists contains: ";
	mergeIntSort.printArray();

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
	sortAlgorithms::MergeSort<double> mergeDoubleSort(doubleList);
	mergeDoubleSort.sort(true);

	std::cout << "\nAfter sorting in ascending order, the lists contains: ";
	mergeDoubleSort.printArray();

	//Sort the list in descending order
	mergeDoubleSort.sort(false);

	std::cout << "\nAfter sorting in descending order, the lists contains: ";
	mergeDoubleSort.printArray();

	std::cout << "\n";
}

void quickSortTest()
{
	std::cout << "Quick sort test\n\n";

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
	sortAlgorithms::QuickSort<int> quickIntSort(intList);
	quickIntSort.sort(true);

	std::cout << "\nAfter sorting in ascending order, the lists contains: ";
	quickIntSort.printArray();

	//Sort the list in descending order
	quickIntSort.sort(false);

	std::cout << "\nAfter sorting in descending order, the lists contains: ";
	quickIntSort.printArray();

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
	sortAlgorithms::QuickSort<double> quickDoubleSort(doubleList);
	quickDoubleSort.sort(true);

	std::cout << "\nAfter sorting in ascending order, the lists contains: ";
	quickDoubleSort.printArray();

	//Sort the list in descending order
	quickDoubleSort.sort(false);

	std::cout << "\nAfter sorting in descending order, the lists contains: ";
	quickDoubleSort.printArray();

	std::cout << "\n";
}

void countingSortTest()
{
	std::cout << "Counting sort test\n\n";

	//Initialize a empty vector to store value
	std::vector<int>    intList;

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
	sortAlgorithms::countingSort(intList, true);

	std::cout << "\nAfter sorting in ascending order, the lists contains: ";
	sortAlgorithms::printArray(intList);

	//Sort the list in descending order
	sortAlgorithms::countingSort(intList, false);

	std::cout << "\nAfter sorting in descending order, the lists contains: ";
	sortAlgorithms::printArray(intList);

	std::cout << "\n";
}

void radixSortTest()
{
	std::cout << "Radix sort test\n\n";

	//Initialize a empty vector to store value
	std::vector<int>    intList;

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
	sortAlgorithms::radixSort(intList, true);

	std::cout << "\nAfter sorting in ascending order, the lists contains: ";
	sortAlgorithms::printArray(intList);

	//Sort the list in descending order
	sortAlgorithms::radixSort(intList, false);

	std::cout << "\nAfter sorting in descending order, the lists contains: ";
	sortAlgorithms::printArray(intList);

	std::cout << "\n";
}

void bucketSortTest()
{
	std::cout << "Bucket sort test\n\n";

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
	sortAlgorithms::bucketSort(intList, true);

	std::cout << "\nAfter sorting in ascending order, the lists contains: ";
	sortAlgorithms::printArray(intList);

	//Sort the list in descending order
	sortAlgorithms::bucketSort(intList, false);

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
	sortAlgorithms::bucketSort(doubleList, true);

	std::cout << "\nAfter sorting in ascending order, the lists contains: ";
	sortAlgorithms::printArray(doubleList);

	//Sort the list in descending order
	sortAlgorithms::bucketSort(doubleList, false);

	std::cout << "\nAfter sorting in descending order, the lists contains: ";
	sortAlgorithms::printArray(doubleList);

	std::cout << "\n";
}