/*

Create a Double Circular Linked List Using Recursion

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
       newnode->prev = newnode;
       newnode->link = newnode;
   
       root = newnode;
       return root;
   }
   
   if (root->link!=head){
       return  insert(root->link,number);
   }
   else{
       
        struct node *newnode;
        newnode = malloc(sizeof(struct node));
        newnode->data = number;
        
        root->link = newnode;
        newnode->prev = root;
        newnode->link = head;
       
   }
   
   //return root;
}

void display()
{
    struct node *disp;
    disp = head;
    while (disp){
        
        printf("%d\t",disp->data);
        disp = disp->link;
        
        if (disp == head)
            break;
    }
}

void display_back()
{
    struct node *disp;
    disp = tail;
    while (disp!=NULL){
        
        printf("%d\t",disp->data);
        disp = disp->prev;
        
        if (disp == tail)
            break;
    }
}

int main()
{
head = insert(head,10);

insert(head,20);
insert(head,30);
insert(head,40);

head->prev = tail = insert(head,50);

display();
display_back();
}