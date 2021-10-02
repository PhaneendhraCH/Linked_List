/*
Swapping First and Last Elements in LL
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    
    int data;
    struct node *link;
    
}*head;

     struct  node *currentnode;
    struct  node *newnode;

void insert(int number){
    
    newnode = malloc(sizeof(struct node));
    newnode->data = number;
    newnode->link = NULL;
    
    if (head==NULL){
    head = newnode;
    currentnode = newnode;
    }
    else{
    
        currentnode->link = newnode;
        currentnode = newnode;
    }
}

void swap_FL(){  // swap first node with last node
struct node *first,*succ,*start;
first = head;
start = head;
int p;

while(first!=NULL){
    succ = first->link;    
    if (succ->link!=NULL){
        first = first->link;
    }
    else{
        p = start->data;
        start->data = succ->data;
        succ->data = p;
        return;
    }
}
}

void display()
{
    struct node *disp;
    disp = head;
    
    if (disp==NULL){
        printf("\nNo nodes");
        return;
    }
        
    while (disp!=NULL){

        printf("%d\t",disp->data);
        disp = disp->link;
     
    }
}

int main()
{
insert(11);
insert(20);
insert(35);
insert(38);
insert(39);
display();
swap_FL();
printf("After Swapping First and Last Element\n");
display();
}
