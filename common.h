#ifndef COMMON_H
#define COMMON_H

//1.standard header
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//2.Macros
#define SUCCESS 0
#define FAILURE 1
#define LIST_EMPTY 2
#define DATA_NOT_FOUND 3


//3.UDDT

typedef struct node
{
    struct node*prev;
    int data;
    struct node*next;
}Dlist;
int insert_at_first(Dlist **head,Dlist **tail,int data);
int apc_add(char num1[],char num2[]);
int print(Dlist *head,int sign);
int delete_list(Dlist **head,Dlist **tail);
int find_length(int num);
int apc_sub(char num1[],char num2[]);
#endif
