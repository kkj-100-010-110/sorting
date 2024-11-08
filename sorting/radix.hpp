/**
 * @file radix.hpp
 * @author GYEONG JU KIM (https://github.com/kkj-100-010-110)
 * @brief radix sort
 */
/*
 * This sorting algorithm fits for int and char.
 * Goal: Sort by each figure.
 * Step 1: Give a single digit to countingSort().
 * Step 2: Count numbers in each element of the array.
 * Step 3: Accumulate countings.
 * Step 4: Sort by its order.
 * Step 5: Repeat 1-4 until sorting the largest digit numbers.
 */

#include <iostream>
#include <array>
#include <vector>

template<typename T>
void countingSort(std::vector<T>& arr, int k, int exp)
{
    // copy arr
	std::vector<T> temp = arr;

	std::vector<T> count(k + 1, 0);
	for (auto& e : arr)
		count[e / exp % 10]++;
	
	for (int i = 1; i < count.size(); i++)
		count[i] += count[i-1];

	for (int i = arr.size() - 1; i >= 0; i--)
		arr[--count[temp[i] / exp % 10]] = temp[i];
}

template<typename T>
void radixSort(std::vector<T>& arr)
{
    // ascii 255
	int k = 255;
	T largest = *max_element(arr.begin(), arr.end());

	for (int exp = 1; largest / exp > 0; exp *= 10)
		countingSort(arr, k, exp);
}