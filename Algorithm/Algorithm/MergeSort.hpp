//
//  MergeSort.h
//  Algorithm
//
//  Created by fangyuxi on 2017/2/28.
//  Copyright © 2017年 fangyuxi. All rights reserved.
//

#ifndef MergeSort_h
#define MergeSort_h

#include <stdio.h>
#include <algorithm>

using namespace std;

template <typename T>
void __merged(T arr[], int l, int mid, int r){
    
    T aux[r - l + 1];
    
    for (int i = l; i <= r; i++) {
        aux[i - l] = arr[i];
    }
    
    int i = l;
    int j = mid + 1;
    
    for (int k = l; k <= r; k++) {
        
        if (i > mid) {
            arr[k] = aux[j - l];
            j++;
        }
        else if (j > r){
            arr[k] = aux[i - l];
            i++;
        }
        
        else if (aux[i - l] < aux[j - l]) {
            arr[k] = aux[i - l];
            i++;
        }
        else {
            arr[k] = aux[j - l];
            j++;
        }
    }
}

template <typename T>
void __mergeSort(T arr[], int l, int r){
 
    if (l >= r) {
        return;
    }
    int mid = (l + r) / 2;
    printf("l:%d,mid:%d,r:%d \n", arr[l],arr[mid],arr[r]);
    
    
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid + 1, r);
    __merged(arr, l, mid,r);
    printf("merge l:%d,mid:%d,r:%d \n", arr[l],arr[mid],arr[r]);
}

template <typename T>
void mergeSort(T arr[], int n) {
    
    __mergeSort(arr, 0, n-1);
}
#endif /* MergeSort_h */
