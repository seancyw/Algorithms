
#ifndef SEARCH_ALGORITHM_H
#define SEARCH_ALGORITHM_H

#include <iostream>
#include <vector>

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

		for (size_t index = 0; index < list.size(); ++index) {
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


}

#endif