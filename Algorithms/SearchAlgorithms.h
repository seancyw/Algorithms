
#ifndef SEARCH_ALGORITHM_H
#define SEARCH_ALGORITHM_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

namespace searchAlgorithms {

	//Search a value in a list
	//Return true if the value is inside the list
	template<typename T>
	bool linearSearchValue(const std::vector<T>& list, const T& searchValue)
	{
		//return false if the list is empty
		if (list.size() == 0)
			return false;

		for (size_t index = 0; index < list.size(); ++index) {
			if (list[index] == searchValue)
				return true;
		}

		return false;
	}
	
	//Search a value in a list
	//Return its array index if the value found
	template<typename T>
	int linearSearchIndex(const std::vector<T>& list, const T& searchValue)
	{
		//return false if the list is empty
		if (list.size() == 0)
			return -1;

		for (int index = 0; index < static_cast<int>(list.size()); ++index) {
			if (list[index] == searchValue)
				return index;
		}

		return -1;
	}

	//Search a value in an array
	//Return its array index if the value found
	template<typename T>
	bool linearSearchValue(const T list[], const T& searchValue)
	{
		if (list == nullptr)
			return false;

		for (size_t index = 0; index < list.size(); ++index) {
			if (list[index] == searchValue)
				return true;
		}

		return false;
	}

	//Search a value in an array
	//Return its array index if the value found
	template<typename T>
	int linearSearchIndex(const T list[], const T& searchValue)
	{
		if (list == nullptr)
			return -1;

		for (size_t index = 0; index < list.size(); ++index) {
			if (list[index] == searchValue)
				return index;
		}

		return -1;
	}

	//Search a value in an array
	//Return its index
	template<typename T>
	int binarySearchIndex(std::vector<T> & element, const T& searchValue)
	{
		if (element.size() == 0) {
			throw std::exception("Element size cannot be 0. Cannot perform search");
			return -1;
		}

		//Sort the elements before search
		std::sort(element.begin(), element.end());

		return binarySearchIndexHelper(element, searchValue, 0, element.size());
	}

	template<typename T>
	int binarySearchIndexHelper(std::vector<T> & element, const T& searchValue, const size_t startIndex, const size_t endIndex)
	{
		if (startIndex > endIndex || startIndex == endIndex)
			return -1;

		int middle = static_cast<int>(startIndex + endIndex) / 2;

		if (searchValue == element[middle])
			return middle;
		else if (searchValue < element[middle])
			return binarySearchIndexHelper(element, searchValue, startIndex, middle - 1);
		else if (searchValue > element[middle])
			return binarySearchIndexHelper(element, searchValue, middle + 1, endIndex);
		
		return -1;
	}

	//Search a value in an array
	//Return true if the value is inside the list
	template<typename T>
	bool binarySearchValue(std::vector<T> & element, const T& searchValue)
	{
		if (element.size() == 0) {
			throw std::exception("Element size cannot be 0. Cannot perform search");
			return false;
		}

		//Sort the elements before search
		std::cout << "Sort array before perform searching:\n";
		
		std::sort(element.begin(), element.end());
		
		std::cout << "Array after sort:\n";
		printArray(element);
		
		//Peform binary search
		return binarySearchValueHelper(element, searchValue, 0, element.size());
	}

	template<typename T>
	bool binarySearchValueHelper(std::vector<T> & element, const T& searchValue, const size_t startIndex, const size_t endIndex)
	{
		if (startIndex > endIndex || startIndex == endIndex)
			return false;

		size_t middle = (startIndex + endIndex) / 2;

		if (searchValue == element[middle])
			return true;
		else if (searchValue < element[middle])
			return binarySearchValueHelper(element, searchValue, startIndex, middle - 1);
		else if (searchValue > element[middle])
			return binarySearchValueHelper(element, searchValue, middle + 1, endIndex);
		
		return false;
	}

	//Return true if the value is inside the list
	template<typename T>
	bool jumpSearchValue(std::vector<T> & elements, const T& searchKey)
	{
		//Return if the array is not sorted
		if (!isSorted(elements)) {
			throw std::exception("Array is not sorted before jump search!");
			return false;
		}

		//Find step size to be jumped
		int stepSize = static_cast<int>( floor( sqrt(elements.size()) ) );
		int step     = 0;

		//Find step where the element is presented
		int previousStep = 0;
		while (elements[__min(step, elements.size() - 1)] < searchKey) {
			previousStep = step;

			step += stepSize;

			if (previousStep >= elements.size())
				return false;
		}

		//Doing a linear search for x in block beginning with
		//previous position
		while (elements[previousStep] < searchKey) {
			previousStep++;

			//if the position reached next block or end of array
			//elements is not presented
			if (previousStep == __min(step + 1, elements.size()))
				return false;
		}

		//If element is found
		if (elements[previousStep] == searchKey)
			return true;

		return false;
	}
	
	//Return index if the value is inside the list
	template<typename T>
	int jumpSearchIndex(std::vector<T> & elements, const T& searchKey)
	{
		//Return if the array is not sorted
		if (!isSorted(elements)) {
			throw std::exception("Array is not sorted before jump search!");
			return -1;
		}

		//Find step size to be jumped
		int stepSize = static_cast<int>( floor(sqrt(elements.size())) );
		int step = 0;

		//Find step where the element is presented
		int previousStep = 0;
		while (elements[__min(step, elements.size() - 1)] < searchKey) {
			previousStep = step;

			step += stepSize;

			if (previousStep >= elements.size())
				return -1;
		}

		//Doing a linear search for x in block beginning with
		//previous position
		while (elements[previousStep] < searchKey) {
			previousStep++;

			//if the position reached next block or end of array
			//elements is not presented
			if (previousStep == __min(step + 1, elements.size()))
				return -1;
		}

		//If element is found
		if (elements[previousStep] == searchKey)
			return previousStep;

		return false;
	}

	//References from http://www.geeksforgeeks.org/interpolation-search/
	//Return true if elements if found
	template<typename T>
	bool interpolationSearchValue(std::vector<T> & elements, T & searchKey)
	{
		//Return if the array is not sorted
		if (!isSorted(elements)) {
			throw std::exception("Array is not sorted!");
			return false;
		}

		//Find indexs of low and high index
		int left = 0;
		int right = static_cast<int>( elements.size() ) - 1;

		//As array is sorted, an elements present in array
		//must be within the range
		while (left <= right && searchKey >= elements[left] && searchKey <= elements[right]) {
			//Probing the position with keeping uniform distribution
			//in mind
			int position = left + (((right - left) / (elements[right] - elements[left])) * (searchKey - elements[left]));

			//Return if target found
			if (elements[position] == searchKey)
				return true;

			//if search element is larger, it should be in upper part
			if (elements[position] < searchKey)
				left = position + 1;
			//if search element is smaller, it should be in lower part
			else
				right = position - 1;
		}

		return false;
	}

	//Return index if elements if found
	template<typename T>
	int interpolationSearchIndex(std::vector<T> & elements, T & searchKey)
	{
		//Return if the array is not sorted
		if (!isSorted(elements)) {
			throw std::exception("Array is not sorted!");
			return -1;
		}

		//Find indexs of low and high index
		int left = 0;
		int right = static_cast<int>( elements.size() ) - 1;
		 
		//As array is sorted, an elements present in array
		//must be within the range
		while (left <= right && searchKey >= elements[left] && searchKey <= elements[right]) {
			//Probing the position with keeping uniform distribution
			//in mind
			int position = left + (((right - left) / (elements[right] - elements[left])) * (searchKey - elements[left]));

			//Return if target found
			if (elements[position] == searchKey)
				return position;

			//if search element is larger, it should be in upper part
			if (elements[position] < searchKey)
				left = position + 1;
			//if search element is smaller, it should be in lower part
			else
				right = position - 1;
		}

		return -1;
	}

	//Return true is the array is sorted in ascending order
	template<typename T>
	bool isSorted(std::vector<T> & elements)
	{
		for (int i = 0; i < elements.size() - 1; ++i) {
			if (elements[i] > elements[i + 1])
				return false;
		}

		return true;
	}

	template<typename T>
	void printArray(const std::vector<T> & elements)
	{
		std::for_each(elements.cbegin(), elements.cend(), [](const T& value) { std::cout << value << " "; });
		std::cout << "\n\n";
	}
}

#endif