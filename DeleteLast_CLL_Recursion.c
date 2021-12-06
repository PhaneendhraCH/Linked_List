/*

Delete last node of a Circular Linked List using Recursion

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
        newnode->link = head;
       
   }
   
   //return root;
}

struct node *delete_last(struct node *headnode,struct node *parent,struct node *root){
    
    if(root == NULL){
        return NULL;
    }
    
    if (root->link!=headnode){
        parent = root;
        return delete_last(headnode,root,root->link);
    }
    
    else{
        free(root);
        parent->link = headnode;
        return 0;
    }
}


void display(struct node *root)
{
    struct node *disp;
    disp = root;
    while (disp){
        printf("%d\t",disp->data);
        disp = disp->link;
        
        if (disp == head)
            break;
    }
}

int main()
{
head = insert(head,10);
insert(head,20);
insert(head,30);
insert(head,40);
insert(head,50);

display(head);
delete_last(head,NULL,head); // delete last node using recursion.
display(head);

}