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


void insertfirst(int number){
    
    struct node *addhead;
    addhead  = malloc(sizeof(struct node));
    
    addhead->data = number;
    addhead->link = head->link;
    head = addhead;
}

void deletefirst(){
    struct node *newhead,*linked;
    newhead = head;
    head = newhead->link;
    free(newhead);
}


void deletelast(){
    
     struct node *temp,*bfl;
     temp = head;
     
     while(temp!=NULL){
         bfl = temp ->link;
         if(bfl->link == NULL){
             temp->link = NULL;
             free(bfl);
             break;
         }
         else{
            temp = temp->link;   
         }
     }
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
printf("\nAfter inserting at  first node : ");
insertfirst(90);
display();
}
