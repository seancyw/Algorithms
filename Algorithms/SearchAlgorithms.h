
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
	//Return its index
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

	template<typename T>
	void printArray(const std::vector<T> & elements)
	{
		std::for_each(elements.cbegin(), elements.cend(), [](const T& value) { std::cout << value << " "; });
		std::cout << "\n\n";
	}
}

#endif