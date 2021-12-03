/*

    Merge two linked list and sort them
    
    Author : Phaneendhra

*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    
    int data;
    struct node *link;
    
}*l1,*l2;


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


void merge_linkedlist(struct node *first, struct node *second){
    
    struct node *root = first;
    
    while(root->link!=NULL)
        root = root->link;
        
    root->link = second;
    printf("Two Linked List merged successfully\n");
    return;
}

void sort_linkedlist(struct node *root){
    
    struct node *node_first,*node_second,*non_repeat;
    int hold_val;
    
    for(node_first=root;node_first!=NULL;node_first=node_first->link){
        
        for (node_second=node_first->link;node_second!=NULL;node_second=node_second->link){
            
            if (node_second->data < node_first->data){
                
                hold_val = node_first->data;
                node_first->data = node_second->data;
                node_second->data = hold_val;
            }
        }
        
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
l1 = insert(l1,10);
insert(l1,20);
insert(l1,30);
insert(l1,40);
insert(l1,20);

l2 = insert(l2,100);
insert(l2,500);
insert(l2,26);
insert(l2,9);
insert(l2,63);


merge_linkedlist(l1,l2);    // merge two linked list
display(l1);

sort_linkedlist(l1);        // sort resultant linked list
display(l1);

}