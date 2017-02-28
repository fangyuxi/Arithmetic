//
//  InsertionSort.hpp
//  Algorithm
//
//  Created by fangyuxi on 2017/2/17.
//  Copyright © 2017年 fangyuxi. All rights reserved.
//

#ifndef InsertionSort_hpp
#define InsertionSort_hpp

#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>


using namespace std;

struct Student{
    
    string name;
    int score;
    
    bool operator<(const Student& otherStudent){
        return score != otherStudent.score ?
        score < otherStudent.score : name < otherStudent.name;
    }
    
    friend ostream& operator<<(ostream &os, const Student &student){
        
        os<<"Student: "<<student.name<<" "<<student.score<<endl;
        return os;
    }
};

//选择排序
template<typename T>
void selectionSort(T arr[], int count){
    
    for (int outerIndex = 0; outerIndex < count; ++outerIndex) {
        
        int minIndex = outerIndex;
        for (int innerIndex = outerIndex + 1; innerIndex < count; ++innerIndex) {
            if (arr[innerIndex] < arr[minIndex]) {
                minIndex = innerIndex;
            }
            
            swap(arr[outerIndex] , arr[minIndex]);
            
        }
    }
    
}

#endif /* InsertionSort_hpp */
