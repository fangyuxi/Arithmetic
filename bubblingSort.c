//
//  main.m
//  MaoPao
//
//  Created by fangyuxi on 2017/12/31.
//  Copyright © 2017年 fangyuxi. All rights reserved.
//

#include <stdio.h>
#import <stdlib.h>

#define BOOL int
#define TRUE 1
#define FALSE 0


/**
 冒泡排序

 @param a array
 @param count array count
 @param ascending ascending ?
 */
void bubblingSort(int *a, int count, BOOL ascending)
{
    int t = 0;
    for (int i = 1; i <= count-1; ++i) {
        
        for (int j = 1; j <= count-1; ++j) {
            
            if (ascending? a[j] > a[j + 1] : a[j] < a[j + 1]) {
                
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int i = 0;
    int n = 0;
    
    printf("请输入排序的数字个数\n");
    scanf("%d", &n);
    int *a = calloc(n, sizeof(int));
    printf("ok 请输入要排序的数字\n");
    
    for (i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if (i == n) {
            printf("输入结束\n");
        }
        printf("输入成功，请继续输入\n");
    }
    
    //排序
    bubblingSort(a, n, TRUE);
    
    printf("运算结果：\n");
    
    for (i = 1; i <= n; ++i) {
        printf("%d \n", a[i]);
    }
    
    return 0;
}
