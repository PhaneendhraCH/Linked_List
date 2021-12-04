/*
Swapping Alternate Nodes in LL using Recursion
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    
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
   
   //return root;
}


struct node *swap_SuccNodes_rec(struct node *root){
    
    if (root == NULL)
        return NULL;
        
    if (root->link == NULL)
        return root;
        
    struct node *start = root;
    struct node *next;
    next = start->link;
    
    int p;
    
    p = start->data;
    start->data = next->data;
    next->data = p;
    
    return swap_SuccNodes_rec(next->link);
    
    
}

void display(struct node *root)
{
    struct node *disp;
    disp = root;
    
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
head = insert(head,11);
insert(head,20);
insert(head,35);
insert(head,38);
insert(head,39);

display(head);

swap_SuccNodes_rec(head);
printf("\nAfter Swapping Alternate Nodes\n");
display(head);
}