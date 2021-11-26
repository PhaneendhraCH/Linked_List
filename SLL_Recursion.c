/*

Create and Reverse a Single Linked List Using Recursion

*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    
    int data;
    struct node *link;
    
}*head;


struct node *reverse(struct node *root){
    
    if (root == NULL){
        return root;
    }
    
    if (root->link == NULL){
        return root;
    }
    
    struct node *node1 = reverse(root->link);
    root->link->link = root;
    root->link = NULL;
    
    return node1;
    
}


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

void display()
{
    struct node *disp;
    disp = head;
    while (disp!=NULL){
        printf("%d\t",disp->data);
        disp = disp->link;
    }
}

int main()
{
head = insert(head,10);
insert(head,20);
insert(head,30);
insert(head,40);
insert(head,50);

display();

head = reverse(head);

display();

}