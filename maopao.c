//
//  main.m
//  MaoPao
//
//  Created by fangyuxi on 2017/12/31.
//  Copyright © 2017年 fangyuxi. All rights reserved.
//

#include <stdio.h>
#import <stdlib.h>

int main(int argc, const char * argv[]) {
    
    int i = 0;
    int j = 0;
    int n = 0;
    int t = 0;
    
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
    
    for (i = 1; i <= n-1; ++i) {
        
        for (j = 1; j <= n-1; ++j) {
            
            if (a[j] < a[j + 1]) {
                
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    
    printf("运算结果：\n");
    
    for (i = 1; i <= n; ++i) {
        printf("%d \n", a[i]);
    }
    
    
    return 0;
}
