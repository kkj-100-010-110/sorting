/**
 * @file quick.hpp
 * @author GYEONG JU KIM (https://github.com/kkj-100-010-110)
 * @brief quick sort
 */
/*
 * divide & conquer
 * 1. Select a pivot
 * 2. Swap items so that
 *      - anything smaller than the pivot is to the left
 *      - anything bigger than the pivot is to the right
 * 3. Put the pivot in place in the array
 * 4. Recursively quicksort the parts of the array to the left and right of the pivot
 * 
 * Space cost of only n + 1, quick sort is just doing swaps. merge sort requires an array of the same size.
 */
#pragma once

#include <iostream>
#include <array>
#include <vector>

/* to pick rightmost item */

template<typename T>
void quickSort_(T arr[], int begin, int end)
{
    if (end - begin > 0)
    {
        T pivot = arr[end]; // pivot
        int i = begin - 1;
        int j = end;
        // partition
        while (true)
        {
            while (arr[++i] < pivot)
                ;
            while (arr[--j] > pivot)
                ;
            if (i >= j)
                break;
            std::swap(arr[i], arr[j]);
        }
        arr[end] = arr[i];
        arr[i] = pivot;
        // int i = begin - 1;
        // for (int j = begin; j < end; j++)
        // {
        //     if (arr[j] <= pivot)
        //     {
        //         std::swap(arr[++i], arr[j]);
        //     }
        // }
        // std::swap(arr[++i], arr[end]);
        // partition

        quickSort_(arr, begin, i-1);
        quickSort_(arr, i+1, end);
    }
}

template<typename T>
void quickSort(T arr[], int n)
{
    quickSort_(arr, 0, n-1);
}

template<typename T, size_t S>
void quickSort_(std::array<T, S>& arr, int begin, int end)
{
    if (end - begin > 0)
    {
        T pivot = arr[end];
        int i = begin - 1;
        int j = end;
        while (true)
        {
            while (arr[++i] < pivot)
                ;
            while (arr[--j] > pivot)
                ;
            if (i >= j)
                break;
            std::swap(arr[i], arr[j]);
        }
        arr[end] = arr[i];
        arr[i] = pivot;

        quickSort_(arr, begin, i-1);
        quickSort_(arr, i+1, end);
    }
}

template<typename T, size_t S>
void quickSort(std::array<T, S>& arr)
{
    quickSort_(arr, 0, arr.size() - 1);
}

template<typename T>
void quickSort_(std::vector<T>& arr, int begin, int end)
{
    if (end - begin > 0)
    {
        // T pivot = arr[end];
        // int i = begin - 1;
        // int j = end;
        // while (true)
        // {
        //     while (arr[++i] < pivot)
        //         ;
        //     while (arr[--j] > pivot)
        //         ;
        //     if (i >= j)
        //         break;
        //     std::swap(arr[i], arr[j]);
        // }
        // arr[end] = arr[i];
        // arr[i] = pivot;
        T pivot = arr[end];
        int i = begin - 1;
        for (int j = begin; j < end; j++)
        {
            if (arr[j] <= pivot)
            {
                std::swap(arr[++i], arr[j]);
            }
        }
        std::swap(arr[++i], arr[end]);

        quickSort_(arr, begin, i-1);
        quickSort_(arr, i+1, end);
    }
}

template<typename T>
void quickSort(std::vector<T>& arr)
{
    quickSort_(arr, 0, arr.size() - 1);
}

/*
 * It is not good for pre-sorted data
 * first partitioning puts items in place with n-1 comparisons
 * second partitioning puts items in place with n-2 comparisons
 * ...
 * O(n^2)
 * Reverse data is the same performance
 * 
 * need the better way to pick a pivot.
 */
/*
 * improve quick sort
 * 1. if partition length <= the cutoff, use insertion sort
 * 2. median of three
 */

/* hybrid algorithm */

template<typename T>
void insertionSort(std::vector<T>& arr, int begin, int end)
{
    for (int i = begin + 1; i <= end; ++i)    // n - 1
    {
        T value = arr[i];
        int idx = i;
        for (int j = i - 1; j >= begin && value < arr[j]; --j, --idx)
        {
            arr[idx] = arr[j];
        }
        arr[idx] = value;
    }
}

template<typename T>
void improvedQuickSort_(std::vector<T>& arr, int begin, int end)
{
    if (end - begin > 1)    // if there are more than 10 elements, it uses insertion sort.
    {   // Quick sort begin.
        // Median of three, improved quick sort
        // 1. Sort the first, middle and last elements of the partition
        int middle = begin + (end - begin) / 2; // (begin + end) / 2
        
        // std::cout << "arr[begin] : " << arr[begin] << ", arr[middle] : " << arr[middle] << ", arr[end] : " << arr[end] << std::endl;
        if (arr[begin] > arr[middle])
        {
            if (arr[begin] > arr[end])
            {
                if (arr[middle] >= arr[end])
                {
                    std::swap(arr[begin], arr[end]);
                }
                else
                {
                    std::swap(arr[begin], arr[end]);
                    std::swap(arr[begin], arr[middle]);
                }
            }
            else
            {
                std::swap(arr[begin], arr[middle]);
            }
        }
        else
        {
            if (arr[middle] > arr[end])
            {
                if (arr[begin] <= arr[end])
                {
                    std::swap(arr[middle], arr[end]);
                }
                else
                {
                    std::swap(arr[middle], arr[end]);
                    std::swap(arr[begin], arr[middle]);
                }
            }
        }
        // std::cout << "arr[begin] : " << arr[begin] << ", arr[middle] : " << arr[middle] << ", arr[end] : " << arr[end] << std::endl;
        // 2. Swap the middle element with the next-to-last element(now the pivot)
        std::swap(arr[middle], arr[end-1]);
        T pivot = arr[end-1];
        // std::cout << "pivot : " << pivot << ", arr[middle] : " << arr[middle] << std::endl;

        // 3. Set up the i and j counters, ignoring the first and last elements
        //      - because we already know the first one is smaller than the pivot,
        //      - and the last element is bigger than the pivot.
        int i = begin;
        int j = end - 1;

        // 4. Partitioning
        while (true)
        {
            while (arr[++i] < pivot)
                ;
            while (arr[--j] > pivot)
                ;
            if (i >= j)
                break;
            std::swap(arr[i], arr[j]);
        }
        arr[end-1] = arr[i];
        arr[i] = pivot;
        // std::cout << "atfer partition arr[end-1] : " << arr[end-1] << ", arr[i] : " << arr[i] << std::endl;

        improvedQuickSort_(arr, begin, i-1);
        improvedQuickSort_(arr, i+1, end);
    }   // Quick sort end
    else
    {
        insertionSort(arr, begin, end);
    }
}

template<typename T>
void improvedQuickSort(std::vector<T>& arr)
{
    improvedQuickSort_(arr, 0, arr.size() - 1);
}