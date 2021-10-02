/*
swapping successive node in LL
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

void swap_SuccNodes(){  // swap successive node
struct node *first,*alt,*start;
first = head;
start = head;
alt = start->link;
int *p = malloc(sizeof(int));

while(start!=NULL){
    
    if(alt!=NULL){
        *p = start->data;
        start->data = alt->data;
        alt->data = *p;
    }
    else{
        break;
    }
    start = start->link->link;
    if (alt->link == NULL)
        break;
    else
        alt = start->link;
}
free(p);
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
insert(59);
display();
swap_SuccNodes();
printf("\nAfter Swapping successive nodes\n");
display();
}
