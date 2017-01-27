
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
					if (elements[j] < elements[i]) {
						std::swap(elements[i], elements[j]);
						isSorted = false;
					}
				}
				else {
					//Swap elements if the elements if current elements is
					//greater than the previous
					if (elements[j] > elements[i]) {
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
					if (elements[j] < elements[index])
						index = j;
				}
				else {
					if (elements[j] > elements[index])
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
	void printArray(const std::vector<T> & elements)
	{
		std::for_each(elements.cbegin(), elements.cend(), [](const T & value) { std::cout << value << " ";  });
		std::cout << std::endl;
	}

}

#endif