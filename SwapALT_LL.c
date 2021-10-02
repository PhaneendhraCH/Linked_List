/*
Swapping Alternate Nodes in LL
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

void swap_ALT(){  // swap alternate nodes in LL
struct node *first,*alt,*start;
first = head;
start = head;
int p;

while(start!=NULL){
    if (alt->link==NULL)
        return;
    else
    alt = start->link->link;
    
    if(alt!=NULL){
       // printf("\n");
        p = start->data;
        start->data = alt->data;
        alt->data = p;
        //display();
    }
    else{
        break;
    }
    start = start->link->link;
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
swap_ALT();
printf("\nAfter Swapping Alternate Nodes\n");
display();
}
