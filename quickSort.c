//
//  main.m
//  QuickSort
//
//  Created by fangyuxi on 2017/12/30.
//  Copyright © 2017年 fangyuxi. All rights reserved.
//

#include <stdio.h>
#import <stdlib.h>

#define BOOL int
#define TRUE 1
#define FALSE 0

/**
 quick sort

 @param a array
 @param left start
 @param right end
 @param ascending ascending ?
 */
void quickSort(int *a, int left, int right, BOOL ascending)
{
    if (a == NULL || left > right) {
        return;
    }
    
    int i = left;
    int j = right;
    int vernier = a[left]; //游标
    int tmp = 0;
    
    while (i != j) {
        
        //先从右边比较游标
        while (i < j && ((!ascending)? (a[j] <= vernier) : (a[j] >= vernier))) {
            j--;
        }
        //再从左边比较游标
        while (i < j && ((!ascending)? (a[i] >= vernier) : (a[j] <= vernier))) {
            i++;
        }
        
        if (i < j) {
            //i和j未相遇的时候交换ij的值
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
    
    //ij相遇，更换游标继续计算
    a[left] = a[i];
    a[i] = vernier;
    
    quickSort(a, left, i - 1, ascending);
    quickSort(a, i + 1, right, ascending);
    return;
    
}

int main(int argc, const char * argv[]) {
    
    int i = 0;
    int n = 0;
    
    printf("请输入排序的数字个数\n");
    scanf("%d", &n);
    int *a = calloc(n + 1, sizeof(int));
    printf("ok 请输入要排序的数字\n");
    
    for (i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        printf("输入成功，请继续输入\n");
        
        if (i == n) {
            printf("输入结束\n");
        }
    }
    
    //排序
    quickSort(a, 1, n, FALSE);
    
    //打印结果
    printf("运算结果：\n");
    for (i = 1; i <= n; ++i) {
        printf("%d \n", a[i]);
    }
    
    return 0;
}
