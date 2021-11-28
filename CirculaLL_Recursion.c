/*

Create Circular LL using Recursion

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

int main()
{
head = insert(head,10);
insert(head,20);
insert(head,30);
insert(head,40);
insert(head,50);

display();

}