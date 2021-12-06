/*
	
	Delete last node of a Single Linked List using Recursion
	Author : Phaneendhra

*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    
    int data;
    struct node *link;
    
}*head;


struct node *insert(struct node *root,int number){
   
   if (root == NULL){
        
       struct node *newnode;
       newnode = malloc(sizeof(struct node));
       newnode->data = number;
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
        newnode->link = NULL;
        
        root->link = newnode;
       
   }

}

struct node *delete_last(struct node *parent,struct node *root){
    
    if(root == NULL){
        return NULL;
    }
    
    if (root->link!=NULL){
        parent = root;
        return delete_last(root,root->link);
    }
    
    else{
        parent->link = NULL;
        return 0;
    }
}

void display(struct node *root)
{
    struct node *disp;
    disp = root;
    while (disp!=NULL){
        printf("%d\t",disp->data);
        disp = disp->link;
    }
}


int main()
{
head = insert(head,10);
insert(head,25);
insert(head,35);
insert(head,45);
insert(head,65);
display(head);

delete_last(NULL,head); // delete last node using recursion.
display(head);

return 0;
}