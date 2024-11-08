#include "sort.h"

int main()
{
    /* a case for 10 numbers */
    int a[10]={3, 31, 48, 73, 8, 65, 20, 29, 11, 15};
    std::array<int, 10> b{3, 31, 48, 73, 8, 65, 20, 29, 11, 15};
    std::vector<int> c{3, 31, 48, 73, 8, 65, 20, 29, 11, 15};
    std::vector<int> d{7, 8, 10, 2, 26, 4, 19, 5, 3, 16, 11, 6, 13, 12};
    std::vector<char> e{'b', 'e', 'd', 'n', 'l', 'f', 'c', 'p', 'z', 'i', 'a'};

    /* basic tests */
    // selectionSort(a, 10);
    // selectionSort(b);
    // selectionSort(c);
    // bubbleSort(a, 10);
    // bubbleSort(b);
    // bubbleSort(c);
    // insertionSort(a, 10);
    // insertionSort(b);
    // insertionSort(c);
    // mergeSort(a, 10);
    // mergeSort(b);
    // mergeSort(c);
    // quickSort(a, 10);
    // quickSort(b);
    // quickSort(c);
    // heapSort(a, 10);
    // heapSort(b);
    // heapSort(c);
    // radixSort(c);
    // radixSort(e);
    // improvedQuickSort(d);

    // print(a, 10);
    // print(b);
    // print(c);
    // print(d);
    // print(e);

    // all basic tests OK

    /* 1-100 array test */
    std::cout << "1-100 test" << std::endl;
    std::vector<int32_t> oneToHundred;
    oneToHundred = oneToHundredShuffleArr();
    std::vector<int32_t> test1 = oneToHundred;
    std::vector<int32_t> test2 = oneToHundred;
    std::vector<int32_t> test3 = oneToHundred;
    std::vector<int32_t> test4 = oneToHundred;
    std::vector<int32_t> test5 = oneToHundred;
    std::vector<int32_t> test6 = oneToHundred;
    std::vector<int32_t> test7 = oneToHundred;
    std::vector<int32_t> test8 = oneToHundred;

    // std::cout << "before sorting" << std::endl;
    // print(oneToHundred);
    // std::cout << "sorted" << std::endl;
    std::sort(oneToHundred.begin(), oneToHundred.end());
    // print(oneToHundred);
    std::cout << "selection" << std::endl;
    Timer t1;
    selectionSort(test1);
    t1.elapsed();
    check(test1, oneToHundred);
    std::cout << "bubble" << std::endl;
    Timer t2;
    bubbleSort(test2);
    t2.elapsed();
    check(test2, oneToHundred);
    std::cout << "insertion" << std::endl;
    Timer t3;
    insertionSort(test3);
    t3.elapsed();
    check(test3, oneToHundred);
    std::cout << "merge" << std::endl;
    Timer t4;
    mergeSort(test4);
    t4.elapsed();
    check(test4, oneToHundred);
    std::cout << "quick" << std::endl;
    Timer t5;
    quickSort(test5);
    t5.elapsed();
    check(test5, oneToHundred);
    std::cout << "heap" << std::endl;
    Timer t6;
    improvedQuickSort(test6);
    t6.elapsed();
    check(test6, oneToHundred);
    std::cout << "radix" << std::endl;
    Timer t7;
    improvedQuickSort(test7);
    t7.elapsed();
    check(test7, oneToHundred);
    std::cout << "improved quick" << std::endl;
    Timer t8;
    improvedQuickSort(test8);
    t8.elapsed();
    check(test8, oneToHundred);

    /* ten thousand test */
    std::cout << "1-10000 test" << std::endl;
    std::vector<int32_t> tenThousand;
    tenThousand = tenThousandShuffleArr();
    std::vector<int32_t> test11 = tenThousand;
    std::vector<int32_t> test12 = tenThousand;
    std::vector<int32_t> test13 = tenThousand;
    std::vector<int32_t> test14 = tenThousand;
    std::vector<int32_t> test15 = tenThousand;
    std::vector<int32_t> test16 = tenThousand;
    std::vector<int32_t> test17 = tenThousand;
    std::vector<int32_t> test18 = tenThousand;

    std::sort(tenThousand.begin(), tenThousand.end());
    std::cout << "selection" << std::endl;
    Timer t11;
    selectionSort(test11);
    t11.elapsed();
    check(test11, tenThousand);
    std::cout << "bubble" << std::endl;
    Timer t12;
    bubbleSort(test12);
    t12.elapsed();
    check(test12, tenThousand);
    std::cout << "insertion" << std::endl;
    Timer t13;
    insertionSort(test13);
    t13.elapsed();
    check(test13, tenThousand);
    std::cout << "merge" << std::endl;
    Timer t14;
    mergeSort(test14);
    t14.elapsed();
    check(test14, tenThousand);
    std::cout << "quick" << std::endl;
    Timer t15;
    quickSort(test15);
    t15.elapsed();
    check(test15, tenThousand);
    std::cout << "heap" << std::endl;
    Timer t16;
    improvedQuickSort(test16);
    t16.elapsed();
    check(test16, tenThousand);
    std::cout << "radix" << std::endl;
    Timer t17;
    improvedQuickSort(test17);
    t17.elapsed();
    check(test17, tenThousand);
    std::cout << "improved quick" << std::endl;
    Timer t18;
    improvedQuickSort(test18);
    t18.elapsed();
    check(test18, tenThousand);

    /* one-million test */
    std::cout << "1-1000000 test" << std::endl;
    std::vector<int32_t> oneMillion;
    oneMillion = oneMillionShuffleArr();
    std::vector<int32_t> test111 = oneMillion;
    std::vector<int32_t> test112 = oneMillion;
    std::vector<int32_t> test113 = oneMillion;
    std::vector<int32_t> test114 = oneMillion;
    std::vector<int32_t> test115 = oneMillion;
    std::sort(oneMillion.begin(), oneMillion.end());

    std::cout << "merge" << std::endl;
    Timer t111;
    mergeSort(test111);
    t111.elapsed();
    check(test111, oneMillion);
    std::cout << "quick" << std::endl;
    Timer t112;
    quickSort(test112);
    t112.elapsed();
    check(test112, oneMillion);
    std::cout << "heap" << std::endl;
    Timer t113;
    improvedQuickSort(test113);
    t113.elapsed();
    check(test113, oneMillion);
    std::cout << "radix" << std::endl;
    Timer t114;
    improvedQuickSort(test114);
    t114.elapsed();
    check(test114, oneMillion);
    std::cout << "improved quick" << std::endl;
    Timer t115;
    improvedQuickSort(test115);
    t115.elapsed();
    check(test115, oneMillion);

    return 0;
}