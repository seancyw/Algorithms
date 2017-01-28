
#ifndef SORTALGORITHMS_H
#define SORTALGORITHMS_H

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

namespace sortAlgorithms
{
	template<typename T>
	void bubbleSort(std::vector<T> & elements, bool ascending)
	{
		if (elements.size() == 0) {
			std::exception("Error! Cannot process empty array.\n");
			return;
		}

		//Use to check if the list is sorted
		//Return directly if the list is sorted
		bool isSorted = true;
		for (size_t i = 0; i < elements.size(); ++i)
		{
			isSorted = true;

			for (size_t j = i + 1; j < elements.size(); ++j) {
				if (ascending) {
					//Swap elements if the elements if current elements is
					//lesser than the previous
					if (lesser(elements[j], elements[i])) {
						std::swap(elements[i], elements[j]);
						isSorted = false;
					}
				}
				else {
					//Swap elements if the elements if current elements is
					//greater than the previous
					if (greater(elements[j], elements[i])) {
						std::swap(elements[i], elements[j]);
						isSorted = false;
					}
				}
			}

			//Break the loops if the list is sorted 
			if (isSorted)
				break;
		}
	}

	template<typename T>
	void selectionSort(std::vector<T> & elements, bool ascending)
	{
		if (elements.size() == 0) {
			throw std::exception("Error! Cannot process empty array.\n");
			return;
		}

		//Determine which elements to swap with the current index
		//element for minimum or maximum
		size_t index = 0;

		for (size_t i = 0; i < elements.size(); ++i) {

			index = i;

			for (size_t j = i + 1; j < elements.size(); ++j) {
				if (ascending) {
					if (lesser(elements[j], elements[index]))
						index = j;
				}
				else {
					if (greater(elements[j], elements[index]))
						index = j;
				}
			}

			//Swap the elements with the current index for the minimum
			//or maximum
			if(i != index)
				std::swap(elements[i], elements[index]);
		}
	}
	
	template<typename T>
	void insertionSort(std::vector<T> & elements, bool ascending)
	{
		//Return if no elements
		if (elements.size() == 0) {
			throw std::exception("Error! Cannot process empty array!\n");
			return;
		}

		for (size_t i = 1; i < elements.size(); ++i) {

			if (ascending) {
				for (size_t j = i; j < elements.size(); --j) {
					if (j >= 1) {
						if (lesser(elements[j], elements[j - 1]))
							std::swap(elements[j], elements[j - 1]);
					}
				}
			}
			else {
				for (size_t j = i; j < elements.size(); --j) {
					if (j >= 1) {
						if (greater(elements[j], elements[j - 1]))
							std::swap(elements[j], elements[j - 1]);
					}
				}
			}
		}
	}

	template<typename T>
	bool greater(const T& value1, const T& value2)
	{
		return value1 > value2;
	}

	template<typename T>
	bool lesser(const T& value1, const T& value2)
	{
		return value1 < value2;
	}

	template<typename T>
	void printArray(const std::vector<T> & elements)
	{
		std::for_each(elements.cbegin(), elements.cend(), [](const T & value) { std::cout << value << " ";  });
		std::cout << std::endl;
	}

}

#endif