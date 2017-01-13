//
//  main.m
//  LinkedList
//
//  Created by fangyuxi on 2017/1/12.
//  Copyright © 2017年 fangyuxi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define BOOL int
#define TRUE 1
#define FALSE 0

typedef struct Data {

    void *data;
} Data;

typedef struct Node {
    Data data;
    struct Node *next;
    struct Node *pre;
} Node;

typedef struct link {
    BOOL isLoop;
    struct Node *head;
} link;


/**
 create a one-way linked list

 @param dataArray data
 @param count count of data
 @return head pointer
 */
struct Node * createOneWayLink(struct Data *dataArray, int count){
    
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    if (head == NULL) {
        return NULL;
    }
    head->data = *(struct Data *)malloc(sizeof(struct Data));
    head->pre = NULL;
    
    struct Node *preNode = head;
    for (int i = 0; i < count; ++i) {
        struct Node *node = (struct Node *)malloc(sizeof(struct Node));
        node->data = dataArray[i];
        node->pre = NULL;
        if (preNode) {
            preNode->next = node;
        }
        preNode = node;
        node->next = NULL;
    }
    return head;
}

/**
 create a Loop linked list
 
 @param dataArray data
 @param count count of data
 @return head pointer
 */
struct Node * createLoopLink(struct Data *dataArray, int count){
    
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    if (head == NULL) {
        return NULL;
    }
    head->data = *(struct Data *)malloc(sizeof(struct Data));
    head->pre = NULL;
    
    struct Node *preNode = head;
    for (int i = 0; i < count; ++i) {
        struct Node *node = (struct Node *)malloc(sizeof(struct Node));
        node->data = dataArray[i];
        node->pre = NULL;
        if (preNode) {
            preNode->next = node;
            node->pre = preNode;
        }
        preNode = node;
        (i == count - 1) ? (node->next = head,head->pre = node) : (node->next = NULL);
    }
    
    return head;
}


/**
 reverse

 @param link one-way linked list
 @return head
 */
struct link * reverseOneWayLink(struct link *link){
    
    if (!link) {
        return NULL;
    }
    if (link->isLoop) {
        return NULL;
    }
    struct Node *head = link->head;
    struct Node *current = head->next;
    struct Node *pnext = current->next;
    struct Node *pre = NULL;
    current->next = NULL;
    while (pnext) {
        
        pre = pnext->next;
        pnext->next = current;
        current = pnext;
        pnext = pre;
    }
    
    head = current;
    link->head = head;
    
    return link;
}

void printLink(struct link *link){
    
    if (!link || !link->head) {
        return;
    }
    
    struct Node *current = link->head->next;
    
    while (current) {
        struct Data data = current->data;
        printf("%d",*(int *)data.data);
        current = current->next;
    }
}


int main(int argc, const char * argv[]) {
    
    struct Data *dataArray = calloc(100, sizeof(struct Data));
    int *array = calloc(100, sizeof(int));
    
    for (int i = 0; i < 100; ++i) {
        array[i] = i;
        dataArray[i].data = &array[i];
    }
    
    struct Node *head = createLoopLink(dataArray, 100);
    
    //创建单向链表
    struct link *oneWayLinkedList = (struct link *)malloc(sizeof(struct link));
    oneWayLinkedList->isLoop = FALSE;
    oneWayLinkedList->head = head;
    
    
    printLink(oneWayLinkedList);
    struct link *reverseLink = reverseOneWayLink(oneWayLinkedList);
    printLink(reverseLink);
    
    
    return 0;
}

























