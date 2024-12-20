/**
 * @file merge.hpp
 * @author GYEONG JU KIM (https://github.com/kkj-100-010-110)
 * @brief merge sort
 */
/*
 * divide & conquer
 */
#pragma once

#include <iostream>
#include <array>
#include <vector>

template<typename T>
void merge(T arr[], int begin, int middle, int end)
{
    T* subArr = new T[end - begin + 1];
    int left = begin, right = middle + 1, idx = 0;

    while (left <= middle && right <= end)
    {
        if (arr[left] < arr[right]) subArr[idx++] = arr[left++];
        else subArr[idx++] = arr[right++];
    }

    while (left <= middle)
        subArr[idx++] = arr[left++];
    
    while (right <= end)
        subArr[idx++] = arr[right++];

    for (int i = begin, j = 0; i <= end && j < idx; i++, j++)
        arr[i] = subArr[j];

    delete[] subArr;
}

template<typename T>
void mergeSort_(T arr[], int begin, int end) // begin = the first index, end = the last index
{
    if (begin < end)
    {
        int middle = begin + (end - begin) / 2;  // '(begin + end) / 2'
        mergeSort_(arr, begin, middle);          // divide
        mergeSort_(arr, middle+1, end);          // divide
        merge(arr, begin, middle, end);          // merge
    }
}

template<typename T>
void mergeSort(T arr[], int n)
{
    mergeSort_(arr, 0, n-1);
}

template<typename T, size_t S>
void merge(std::array<T, S>& arr, int begin, int middle, int end)
{
    std::array<T, S> subArr; // not good. it causes wasted memory
    int left = begin, right = middle+1, idx = 0;

    while (left <= middle && right <= end)
    {
        if (arr[left] < arr[right]) subArr[idx++] = arr[left++];
        else subArr[idx++] = arr[right++];
    }

    while (left <= middle)
        subArr[idx++] = arr[left++];

    while (right <= middle)
        subArr[idx++] = arr[right++];
    
    for (int i = begin, j = 0; i <= end && j < idx; i++, j++)
        arr[i] = subArr[j];
}

template<typename T, size_t S>
void mergeSort_(std::array<T, S>& arr, int begin, int end)
{
    if (begin < end)
    {
        int middle = begin + (end - begin) / 2;
        mergeSort_(arr, begin, middle);
        mergeSort_(arr, middle+1, end);
        merge(arr, begin, middle, end);
    }
}

template<typename T, size_t S>
void mergeSort(std::array<T, S>& arr)
{
    mergeSort_(arr, 0, arr.size()-1);
}

// template<typename T>
// void merge(std::vector<T>& arr, int begin, int middle, int end)
// {
//     std::vector<T> subArr;
//     int left = begin, right = middle+1;

//     while (left <= middle && right <= end)
//     {
//         if (arr[left] < arr[right]) subArr.emplace_back(arr[left++]);
//         else subArr.emplace_back(arr[right++]);
//     }

//     while (left <= middle)
//         subArr.emplace_back(arr[left++]);

//     while (right <= end)
//         subArr.emplace_back(arr[right++]);
    
//     for (int i = begin, j = 0; i <= end && j < subArr.size(); i++, j++)
//         arr[i] = subArr[j];
// }

// template<typename T>
// void mergeSort_(std::vector<T>& arr, int begin, int end)
// {
//     if (begin < end)
//     {
//         int middle = begin + (end - begin) / 2;
//         mergeSort_(arr, begin, middle);
//         mergeSort_(arr, middle+1, end);
//         merge(arr, begin, middle, end);
//     }
// }

// template<typename T>
// void mergeSort(std::vector<T>& arr)
// {
//     mergeSort_(arr, 0, arr.size()-1);
// }

/*
 * Creating a subarray every time cost a lot
 * Better way below
 */

template<typename T>
void merge(std::vector<T>& arr, int begin, int middle, int end, std::vector<T>& tmp)
{
    int left = begin, right = middle+1;
    int k = begin;

    while (left <= middle && right <= end)
    {
        if (arr[left] < arr[right]) tmp[k++] = arr[left++];
        else tmp[k++] = arr[right++];
    }

    while (left <= middle)
        tmp[k++] = arr[left++];

    while (right <= end)
        tmp[k++] = arr[right++];

    for (int i = begin; i <= end; i++)
        arr[i] = tmp[i];
}

template<typename T>
void mergeSort_(std::vector<T>& arr, int begin, int end, std::vector<T>& tmp)
{
    if (begin < end)
    {
        int middle = begin + (end - begin) / 2;
        mergeSort_(arr, begin, middle, tmp);
        mergeSort_(arr, middle+1, end, tmp);
        merge(arr, begin, middle, end, tmp);
    }
}

template<typename T>
void mergeSort(std::vector<T>& arr)
{
    std::vector<T> tmp(arr.size());
    mergeSort_(arr, 0, arr.size() - 1, tmp);
}

/*
 * a bit improved one
 */

template<typename T>
void insertion(std::vector<T>& arr, int begin, int end)
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
void improvedMergeSort_(std::vector<T>& arr, int begin, int end, std::vector<T>& tmp)
{
    if (end - begin > 20)
    {
        int middle = begin + (end - begin) / 2;
        improvedMergeSort_(arr, begin, middle, tmp);
        improvedMergeSort_(arr, middle+1, end, tmp);
        merge(arr, begin, middle, end, tmp);
    }
    else
    {
        insertion(arr, begin, end);
    }
}

template<typename T>
void improvedMergeSort(std::vector<T>& arr)
{
    std::vector<T> tmp(arr.size());
    improvedMergeSort_(arr, 0, arr.size() - 1, tmp);
}