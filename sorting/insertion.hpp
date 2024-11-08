/**
 * @file insertion.hpp
 * @author GYEONG JU KIM (https://github.com/kkj-100-010-110)
 * @brief insertion sort
 */
/*
 * 1. find the largest number in an array [0..n] and move to the last
 * 2. find the largest number in an array [0..n-1] and move to the last
 * 3. ...
 */
#pragma once

#include <array>
#include <vector>
#include <iostream>

template<typename T>
void insertionSort(T arr[], int n)
{
    for (int i = 1; i < n; i++)             // (n - 1) 
    {
        T tmp = arr[i];                     // to copy target data
        int idx = i;                        // the index of the target data
        for (int j = i - 1; j >= 0; j--)    // all data before target data is sorted, so find the target place.
        {                                   // if the target is the largest, 1. if the target is the lowest, i - 1.
            if (arr[j] > tmp)
            {
                arr[idx] = arr[j];
                idx = j;
            }
            else
            {
                arr[idx] = tmp;
                break;
            }
        }
    }
}

template<typename T, size_t S>
void insertionSort(std::array<T, S>& arr)
{
    for (int i = 1; i < S; i++)
    {
        T tmp = arr[i];
        int idx = i;
        for (int j = i - 1; j >= 0 && arr[j] > tmp; j--)
        {
            arr[idx] = arr[j];
            idx = j;
        }
        arr[idx] = tmp;
    }
}

template<typename T>
void insertionSort(std::vector<T>& arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        T tmp = arr[i];
        int idx = i;
        for (int j = i - 1; j >= 0 && arr[j] > tmp; j--)
        {
            arr[idx] = arr[j];
            idx = j;
        }
        arr[idx] = tmp;
    }
}