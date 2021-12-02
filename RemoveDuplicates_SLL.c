/*

	Remove Duplicates in a Single Linked List 
	
	Author : Phaneendhra
*/


#include <stdio.h>
#include <stdlib.h>

struct node{
    
    int data;
    struct node *link;
    
}*head;

void remove_duplicate()
{
   struct node *current = head;
   
   struct node *next;
   
   while (current!=NULL){
       
       next = current;
       
       while(next->link!=NULL){
         
             
           if (current->data == next->link->data)
           {
               next->link = next->link->link;
           }
           else{
           next = next->link;
           }
       
       }
       
       current = current->link;
   }
   return;
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
insert(head,20);
insert(head,10);
insert(head,50);
insert(head,30);


remove_duplicate();

display();

}