//
//  InsertionSort.hpp
//  Algorithm
//
//  Created by fangyuxi on 2017/2/23.
//  Copyright © 2017年 fangyuxi. All rights reserved.
//

#ifndef InsertionSort_h
#define InsertionSort_h

#include <stdio.h>
#include <algorithm>

using namespace std;

template<typename T>
void insertionSort(T arr[], int n){
    
    for (int i = 1; i < n; i++) {
        
        T e = arr[i];
        int j;
        for (j = i; j > 0 && arr[j - 1] > e; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = e;
    }
}

#endif /* InsertionSort_h */
