//
//  main.cpp
//  Algorithm
//
//  Created by fangyuxi on 2017/2/17.
//  Copyright © 2017年 fangyuxi. All rights reserved.
//

#include <iostream>
#include "SelectionSort.hpp"
#include "InsertionSort.hpp"
#include "BubbleSort.hpp"
#include "SortTest.h"
#include "MergeSort.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    
    // 测试模板函数，传入自定义结构体Student数组
    Student d[4] = { {"D",90} , {"C",100} , {"B",95} , {"A",95} };
    selectionSort(d,4);
    for( int i = 0 ; i < 4 ; i ++ )
        cout<<d[i];
    cout<<endl;
    
    //int n = 10;
    //int *arr = SortTest::generateRandomArray(n, 0,n);
    //int *arr1 = SortTest::copyIntArray(arr, n);
    
    //SortTest::testSort("selectionSort", bubbleSort, arr, n);
    //SortTest::testSort("insertionSort", insertionSort, arr1, n);
    //
    //delete [] arr;
    //delete [] arr1;
    
    int arr[10] = {6,1,5,7,10,2,8,3,4,9};
    mergeSort(arr, 10);
    SortTest::printArray(arr, 10);
    return 0;
}
