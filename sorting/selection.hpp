/**
 * @file selection.hpp
 * @author GYEONG JU KIM (https://github.com/kkj-100-010-110)
 * @brief selection sort
 */
/*
 * 1. find the largest number in an array [0..n] and move to the last
 * 2. find the largest number in an array [0..n-1] and move to the last
 * 3. ...
 */
#pragma once

#include <array>
#include <vector>

template<typename T>
void selectionSort(T arr[], int n)
{
    for (int last = n-1; last > 0; last--)      // (n - 1)
    {
        int largest = 0;
        for (int i = 1; i <= last; i++)         // find the largest (n - 1)
        {
            if (arr[largest] < arr[i]) largest = i;
        }
        std::swap(arr[largest], arr[last]);     // constant
    }
}

template<typename T, size_t S>
void selectionSort(std::array<T, S>& arr)
{
    for (int last = S - 1; last > 0; last--)
    {
        int largest = 0;
        for (int i = 1; i <= last; i++)
        {
            if (arr[largest] < arr[i]) largest = i;
        }
        std::swap(arr[largest], arr[last]);
    }
}

template<typename T>
void selectionSort(std::vector<T>& arr)
{
    for (int last = arr.size() - 1; last > 0; last--)
    {
        int largest = 0;
        for (int i = 1; i <= last; i++)
        {
            if (arr[largest] < arr[i]) largest = i;
        }
        std::swap(arr[largest], arr[last]);
    }
}