/*

Create a Double Linked List Using Recursion

*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    
    int data;
    struct node *prev;
    struct node *link;
    
}*head,*tail;

struct node *insert(struct node *root,int number){
   
   if (root == NULL){
        
       struct node *newnode;
       newnode = malloc(sizeof(struct node));
       newnode->data = number;
       newnode->prev = NULL;
       newnode->link = NULL;
   
       root = newnode;
       return root;
   }
   
   if (root->link!=NULL){
       return  insert(root->link,number);
   }
   else{
       
        struct node *newnode;
        newnode = malloc(sizeof(struct node));
        newnode->data = number;
        
        root->link = newnode;
        newnode->prev = root;
       
   }
   
   //return root;
}

void display()
{
    struct node *disp;
    disp = head;
    while (disp!=NULL){
        
        printf("%d\t",disp->data);
        disp = disp->link;
        
    }
}

void display_back()
{
    struct node *disp;
    disp = tail;
    while (disp!=NULL){
        
        printf("%d\t",disp->data);
        disp = disp->prev;
        
    }
}

int main()
{
head = insert(head,10);
insert(head,20);
insert(head,30);
insert(head,40);
tail = insert(head,50);

display();
display_back();
}