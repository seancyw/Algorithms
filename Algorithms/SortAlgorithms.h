
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

			for (size_t j = i; j < elements.size(); --j) {
				if (j >= 1) {
					if (ascending) {
						if (lesser(elements[j], elements[j - 1]))
							std::swap(elements[j], elements[j - 1]);
					}
					else {
						if (greater(elements[j], elements[j - 1]))
							std::swap(elements[j], elements[j - 1]);
					}
				}
			}
		}
	}

	template<typename T>
	void shellSort(std::vector<T> & elements, bool ascending)
	{
		//Return if no elements
		if (elements.size() == 0) {
			throw std::exception("Error! Cannot process empty array!\n");
			return;
		}

		//Initialize h-th level
		int h = 1;
		while (h < elements.size() / 3)
			h = 3 * h + 1;

		while (h >= 1) {
			//h-sort the array
			for (int i = h; i < elements.size(); ++i) {
				//Insert a[i] among a[i - h], a[i - 2 * h], a[i - 3 * h]....
				for (int j = i; j >= h; j -= h) {
					if (j >= 1) {
						if (ascending) {
							if (lesser(elements[j], elements[j - 1]))
								std::swap(elements[j], elements[j - 1]);
						}
						else {
							if (greater(elements[j], elements[j - 1]))
								std::swap(elements[j], elements[j - 1]);
						}
					}
				}

			}

			//Go to the next h next level
			h = h / 3;
		};
	}

	template<typename T>
	class MergeSort
	{
	public:
		MergeSort(std::vector<T> & data)
			: elements(data)
		{
		}

		void sort(bool ascending)
		{
			//Return if nothing to sort
			if (elements.size() == 0) {
				throw std::exception("Cannot process empty list!");
				return;
			}

			sortHelper(ascending, 0, elements.size());
		}

		

		void merge(bool ascending, int lowIndex, int middleIndex, int highIndex)
		{
			//Merge elements[lowIndex...middleIndex] 
			//with elements[middleIndex+1...highIndex]
			int i = lowIndex;
			int j = middleIndex + 1;

			std::vector<T> mergeArray(elements);

			//Merge back to elements[low..highIndex]
			for (int k = lowIndex; k <= highIndex; ++k) {
				if (i > middleIndex)
					elements[k] = mergeArray[j++];
				else if(j > highIndex)
					elements[k] = mergeArray[i++];
				else if (lesser(mergeArray[j], mergeArray[i]) && ascending)
					elements[k] = mergeArray[j++];
				else
					elements[k] = mergeArray[i++];
			}
		}

	private:
		std::vector<T> elements;

		void sortHelper(int lowIndex, int highIndex, bool ascending)
		{
			if (highIndex <= lowIndex)
				return;

			int middle = (lowIndex + highIndex) / 2;

			//Sort left half
			sortHelper(lowIndex, middle, ascending);

			//Sort right half
			sortHelper(middle + 1, highIndex, ascending);
		}
	};
	
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