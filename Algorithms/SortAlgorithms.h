
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

		for (size_t i = 0; i < elements.size(); ++i)
		{
			for (size_t j = i + 1; j < elements.size(); ++j) {
				if (ascending) {
					if (elements[j] < elements[i])
						std::swap(elements[i], elements[j]);
				}
				else {
					if (elements[j] > elements[i])
						std::swap(elements[i], elements[j]);
				}
			}
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