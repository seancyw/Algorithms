
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
	void countingSort(std::vector<T> & data, bool ascending)
	{
		if (data.size() == 0) {
			throw std::exception("Nothing to sort!");
			return;
		}

		//Get the maximum element in the list as the maximum counter
		//range
		int maximumElement = *std::max_element(data.begin(), data.end());
		std::vector<int> counter(maximumElement + 1);
		std::fill(counter.begin(), counter.end(), 0);

		//Store count for each element
		for (int i = 0; i < data.size(); ++i)
			++counter[data[i]];
		
		//Recalculate each counter[i] so that it contains the actual
		//position of the elements
		for (int i = 1; i < counter.size(); ++i)
			counter[i] += counter[i - 1];

		//Initialize a temporary array to store the sorted array
		std::vector<T> temp( data.size() );
		for (int i = 0; i < data.size(); ++i) {
			temp[counter[data[i]] - 1] = data[i];
			--counter[data[i]];
		}

		//Copy the sort array back to original array
		data = temp;

		if (!ascending)
			std::reverse(data.begin(), data.end());
	}

	template<typename T>
	void countingSort(std::vector<T> & data, int baseDigit)
	{
		if (data.size() == 0) {
			throw std::exception("Nothing to sort!");
			return;
		}

		//Initialize counter variables in size of 10 as remainder of
		//10 would get value from 0 - 9
		std::vector<int> counter( 10 );
		std::fill(counter.begin(), counter.end(), 0);

		//Store count for each element
		for (int i = 0; i < data.size(); ++i)
			++counter[(data[i] / baseDigit) % 10];

		//Recalculate each counter[i] so that it contains the actual
		//position of the elements
		for (int i = 1; i < counter.size(); ++i)
			counter[i] += counter[i - 1];

		//Initialize a temporary array to store the sorted array
		std::vector<T> temp(data.size());
		for (int i = data.size() - 1; i >= 0; --i) {
			temp[ counter[(data[i] / baseDigit) % 10]  - 1] = data[i];
			--counter[(data[i] / baseDigit) % 10];
		}

		//Copy the sort array back to original array
		data = temp;
	}

	//references from http://www.geeksforgeeks.org/radix-sort/
	template<typename T>
	void radixSort(std::vector<T>& data, bool ascending) 
	{
		//Find the maximum number to know number of digits
		int maximumNumber = *std::max_element(data.begin(), data.end());

		//Do counting sort for every digits
		//Instead of passing digit number, base is passed
		//base is 10^i, where i is current digit number
		for (int base = 1; maximumNumber / base > 0; base *= 10)
			countingSort(data, base);

		//reverse the array if in descending order
		if (!ascending)
			std::reverse(data.begin(), data.end());
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

			sortHelper(0, static_cast<int>(elements.size()) - 1, ascending);
		}


		void merge(int lowIndex, int middleIndex, int highIndex, bool ascending)
		{
			//Index into left subvector
			int leftIndex = lowIndex;

			//Index into right subvector
			int rightIndex = middleIndex + 1;

			//Index into temporary working vector
			int combinedIndex = lowIndex;
			std::vector<T> mergeArray(elements.size());

			//Merge vectors until reaching end of either
			while (leftIndex <= middleIndex && rightIndex <= highIndex) {
				
				//Place smaller of two current elements into result and 
				//move to next space in vector
				if (ascending) {
					if (elements[leftIndex] <= elements[rightIndex])
						mergeArray[combinedIndex++] = elements[leftIndex++];
					else
						mergeArray[combinedIndex++] = elements[rightIndex++];
				}
				else {
					if (elements[rightIndex] >= elements[leftIndex])
						mergeArray[combinedIndex++] = elements[rightIndex++];
					else
						mergeArray[combinedIndex++] = elements[leftIndex++];
				}
			}

			//copy in rest of right vector
			while (rightIndex <= highIndex)
				mergeArray[combinedIndex++] = elements[rightIndex++];

			//copy in rest of left vector
			while (leftIndex <= middleIndex)
				mergeArray[combinedIndex++] = elements[leftIndex++];

			//copy values back to original vector
			for (int i = lowIndex; i <= highIndex; ++i)
				elements[i] = mergeArray[i];
		}

		void printArray() const
		{
			std::for_each(elements.cbegin(), elements.cend(), [](const T & value) { std::cout << value << " ";  });
			std::cout << std::endl;
		}

	private:
		std::vector<T> elements;

		void sortHelper(int lowIndex, int highIndex, bool ascending)
		{
			//test base case
			//if size of vector equals to 1
			if ((highIndex - lowIndex) < 1)
				return;

			//Calculate the middle of vector
			int middle = (lowIndex + highIndex) / 2;

			//Sort left half
			sortHelper(lowIndex, middle, ascending);

			//Sort right half
			sortHelper(middle + 1, highIndex, ascending);

			merge(lowIndex, middle, highIndex, ascending);
		}
	};
	
	template<typename T>
	class QuickSort
	{
	public:
		QuickSort(const std::vector<T> & data)
			: elements(data)
		{
		}

		void sort(bool ascending)
		{
			//Return if nothings to sort
			if (elements.size() == 0) {
				throw std::exception("Elements size is 0, nothing to sort.");
				return;
			}

			//Eliminate dependence on input
			std::random_shuffle(elements.begin(), elements.end());

			//Do sorting
			sortHelper(0, elements.size() - 1, ascending);
		}

		void sortHelper(int lowIndex, int highIndex, bool ascending)
		{
			//Return if the high index is less than lowIndex
			if (highIndex <= lowIndex) {
				throw std::exception("High index must be less than low index.");
				return;
			}

			//Partitioning
			//Left and right scan indices
			int left = lowIndex;
			int right = highIndex;

			//Partitioning item
			T pivot = elements[(lowIndex + highIndex) / 2];

			while (left <= right) {
				//Scan right, scan left, check for scan complete
				//and swap
				if (ascending) {
					while (lesser(elements[left], pivot))
						++left;

					while (greater(elements[right], pivot))
						--right;
				}
				else {
					while (greater(elements[left], pivot))
						++left;

					while (lesser(elements[right], pivot))
						--right;
				}

				if (left <= right) {
					std::swap(elements[left], elements[right]);
					++left;
					--right;
				}
			}

			//Sort left part
			if(lowIndex < right)
				sortHelper(lowIndex, right, ascending);
			
			//Sort right part
			if(left < highIndex)
				sortHelper(left, highIndex, ascending);
		}

		void printArray() const
		{
			std::for_each(elements.cbegin(), elements.cend(), [](const T & value) { std::cout << value << " ";  });
			std::cout << std::endl;
		}

	private:
		std::vector<T> elements;
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