/**
 * @file heap.hpp
 * @author GYEONG JU KIM (https://github.com/kkj-100-010-110)
 * @brief heap sort
 */
/*
 * Step 1: Build the heap
 *          - Make sure our data is in indices 1 to the number of items
 *          - Use linear time algorithm(heapify) to turn the array into a heap
 * Step 2: Actually sort
 *          - Delete max until only one item is left in the heap, swapping root with the last item each time
 */

#pragma once

#include <iostream>
#include <vector>
#include <array>

template<typename T>
void percolateDown(T arr[], int idx, int size)
{
    while (idx < size / 2)
    {
        int left = idx * 2 + 1;
        int right = idx * 2 + 2;
        int max = arr[left] > arr[right] ? left : right == size ? left : right;
        if (arr[idx] < arr[max])
        {
            std::swap(arr[idx], arr[max]);
            idx = max;
        }
        else
            break;
    }
}

template<typename T>
void heapify(T arr[], size_t size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        percolateDown(arr, i, size);
}

template<typename T>
void heapSort_(T arr[], size_t size)
{
    heapify(arr, size);
    for (int i = size - 1; 0 < i; i--)
    {
        std::swap(arr[0], arr[i]);
        percolateDown(arr, 0, i);
    }
}

template<typename T>
void heapSort(T arr[], size_t size)
{
    heapSort_(arr, size);
}

template<typename T, size_t S>
void percolateDown(std::array<T, S>& arr, int idx, int size)
{
    while (idx < size / 2)
    {
        int left = idx * 2 + 1;
        int right = idx * 2 + 2;
        int max = arr[left] > arr[right] ? left : right == size ? left : right;
        if (arr[idx] < arr[max])
        {
            std::swap(arr[idx], arr[max]);
            idx = max;
        }
        else
            break;
    }
}

template<typename T, size_t S>
void heapify(std::array<T, S>& arr)
{
    for (int i = arr.size() / 2 - 1; i >= 0; i--)
        percolateDown(arr, i, arr.size());
}

template<typename T, size_t S>
void heapSort_(std::array<T, S>& arr)
{
    heapify(arr);
    for (int i = arr.size() - 1; 0 < i; i--)
    {
        std::swap(arr[0], arr[i]);
        percolateDown(arr, 0, i);
    }
}

template<typename T, size_t S>
void heapSort(std::array<T, S>& arr)
{
    heapSort_(arr);
}

template<typename T>
void percolateDown(std::vector<T>& arr, int idx, int size)
{
    while (idx < size / 2)
    {
        int left = idx * 2 + 1;
        int right = idx * 2 + 2;
        int max = arr[left] > arr[right] ? left : right == size ? left : right;
        if (arr[idx] < arr[max])
        {
            std::swap(arr[idx], arr[max]);
            idx = max;
        }
        else
            break;
    }
}

template<typename T>
void heapify(std::vector<T>& arr)
{
    for (int i = arr.size() / 2 - 1; i >= 0; i--)
        percolateDown(arr, i, arr.size());
}

template<typename T>
void heapSort_(std::vector<T>& arr)
{
    heapify(arr);
    for (int i = arr.size() - 1; 0 < i; i--)
    {
        std::swap(arr[0], arr[i]);
        percolateDown(arr, 0, i);
    }
}

template<typename T>
void heapSort(std::vector<T>& arr)
{
    heapSort_(arr);
}