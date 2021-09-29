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

void display()
{
    struct node *disp;
    disp = head;
    while (disp!=NULL){
        printf("%d\t",disp->data);
        disp = disp->link;
    }
    //printf("Last node is : %d\n",disp->data);
}



void insertend(int number){
    
    struct node *recr,*newadded;
    recr = head;
    newadded =  malloc(sizeof(struct node));
    newadded->data = number;
    while (recr->link!=NULL){
        recr = recr->link;
    }
    recr->link = newadded;  
}


int main()
{
insert(10);
insert(20);
insert(30);
insert(40);
insert(50);
insert(60);
printf("Initial List : ");
display();
printf("\nAfter inserting at  end node : ");
insertend(80);
display();
}
