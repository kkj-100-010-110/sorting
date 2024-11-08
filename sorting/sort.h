/**
 * @file sort.h
 * @author GYEONG JU KIM (https://github.com/kkj-100-010-110)
 * @brief sorting algorithms
 */
#pragma once

/* sorting */
#include "selection.hpp"
#include "bubble.hpp"
#include "insertion.hpp"
#include "merge.hpp"
#include "quick.hpp"
#include "heap.hpp"
#include "radix.hpp"

/* standard library */
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time()
#include <random>   // C++11
#include <chrono>   // Timer


/* random number generator */
int getRandomNumber(int32_t min, int32_t max)
{
    static const double fraction = 1.0 / (RAND_MAX + 1.0);
    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

int getRnadomNumber()
{
    std::random_device  rd;
    std::mt19937        mersenne(rd()); // create a mersenne twister

    std::uniform_int_distribution<> dice(1, 1000); 

    return dice(mersenne);
}

/* 1-100 shuffled array generator */
std::vector<int32_t> oneToHundredShuffleArr()
{
    std::vector<int32_t> arr;
    for (int32_t i = 0; i < 100; i++)
        arr.push_back(i + 1);

    std::random_device  rd;
    std::mt19937        mt(rd());

    std::shuffle(arr.begin(), arr.end(), mt);
    return arr;
}

/* ten thousand shuffled array generator */
std::vector<int32_t> tenThousandShuffleArr()
{
    std::vector<int32_t> arr;
    for (int32_t i = 0; i < 10000; i++)
        arr.push_back(i + 1);

    std::random_device  rd;
    std::mt19937        mt(rd());

    std::shuffle(arr.begin(), arr.end(), mt);
    return arr;
}

/* one million shuffled array generator */
std::vector<int32_t> oneMillionShuffleArr()
{
    std::vector<int32_t> arr;
    for (int32_t i = 0; i < 1000000; i++)
        arr.push_back(i + 1);

    std::random_device  rd;
    std::mt19937        mt(rd());

    std::shuffle(arr.begin(), arr.end(), mt);
    return arr;
}

/* test check */
template<typename T>
void check(std::vector<T> arr, std::vector<T> answer)
{
    if (arr.size() != answer.size())
        std::cerr << "\033[3;41;30mError: they are not the same size.\033[0m\t\t" << std::endl;

    int32_t i;
    for (i = 0; i < arr.size() && arr[i] == answer[i]; i++)
        ;
    if (i == arr.size())
        std::cout << "\033[3;42;30mOK\033[0m\t\t" << std::endl;
    else
        std::cout << "\033[3;41;30mKO\033[0m\t\t" << std::endl;
}

/* timer */
class Timer
{
    using clock_t = std::chrono::high_resolution_clock;
    using secont_t = std::chrono::duration<double, std::ratio<1>>;

    // as soon as Timer objects create, start_time is assigned by time log.
    std::chrono::time_point<clock_t> start_time = clock_t::now();   

public:
    void elapsed()
    {
        // once this function is called, end_time is assigned by time log.
        std::chrono::time_point<clock_t> end_time = clock_t::now();
        // print the difference between start_time and end_time
        std::cout << std::chrono::duration_cast<secont_t>(end_time - start_time).count() << std::endl;
    }
};

/* print */
template<typename T>
void print(T arr[], int32_t n)
{
    for (int32_t i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

template<typename T, size_t S>
void print(std::array<T, S> arr)
{
    for (int32_t i = 0; i < S; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

template<typename T>
void print(std::vector<T> arr)
{
    // for (int32_t i = 0; i < arr.size(); i++)
    //     std::cout << arr[i] << " ";
    // std::cout << std::endl;
    for (auto& e : arr)
        std::cout << e << " ";
    std::cout << std::endl;
}