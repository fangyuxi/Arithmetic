//
//  BubbleSort.h
//  Algorithm
//
//  Created by fangyuxi on 2017/2/24.
//  Copyright © 2017年 fangyuxi. All rights reserved.
//

#ifndef BubbleSort_h
#define BubbleSort_h

#include <stdio.h>
#include <algorithm>

using namespace std;

template<typename T>
void bubbleSort(T arr[], int n){
    
    bool flag = true;
    for (int i = 0; i < n - 1 && flag; i++) {
        flag = false;
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                flag = true;
            }
            
        }
    }
}

#endif /* BubbleSort_h */
