#include <stdio.h>
#include <stdlib.h>

struct node{
    
    int data;
    struct node *prev;
    struct node *link;
    
}*head,*behead ;

     struct  node *currentnode;
    struct  node *newnode;

void insert(int number){
    
    newnode = malloc(sizeof(struct node));
    newnode->data = number;
    newnode->link = NULL;
    
    if (head==NULL){
    head = newnode;
    currentnode = newnode;
    head->prev = NULL;
    currentnode->prev=NULL;
    }
    else{
        currentnode->link = newnode;
        newnode->prev = currentnode;
        currentnode = newnode;
	behead = newnode;
        
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

/*
void displayend()
{
    struct node *disp;
    disp = head;
    while (disp->link!=NULL){
       // printf("%d\t",disp->data);
        disp = disp->link;
    }
    while(disp!=NULL){
        printf("%d\t",disp->data);
        disp = disp->prev;
    }

}
*/
void displayend()
{
    struct node *disp;
    disp = behead;
    
    while(disp!=NULL){
        printf("%d\t",disp->data);
        disp = disp->prev;
    }

}


void insertfirst(int number){
    
    struct node *addhead;
    addhead  = malloc(sizeof(struct node));
    
    addhead->data = number;
    addhead->link = head;
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
//display();
displayend();
}
