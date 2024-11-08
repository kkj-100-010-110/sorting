/**
 * @file bubble.hpp
 * @author GYEONG JU KIM (https://github.com/kkj-100-010-110)
 * @brief bubble sort
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
void bubbleSort(T arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n - i; j++)
            if (arr[j-1] > arr[j]) std::swap(arr[j-1], arr[j]);
    }
}

template<typename T, size_t S>
void bubbleSort(std::array<T, S>& arr)
{
    for (int i = 0; i < S; i++)
    {
        for (int j = 1; j < S - i; j++)
            if (arr[j-1] > arr[j]) std::swap(arr[j-1], arr[j]);
    }
}

template<typename T>
void bubbleSort(std::vector<T>& arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 1; j < arr.size() - i; j++)
            if (arr[j-1] > arr[j]) std::swap(arr[j-1], arr[j]);
    }
}