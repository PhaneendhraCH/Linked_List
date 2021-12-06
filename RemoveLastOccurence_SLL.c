/*

    Remove Last Occurence Node from a Linked List
    
    P.S : Need to update more
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
   
}

struct node *lastoccurence(struct node *prior,
                        struct node *last,
                        struct node *current,
                        int value){
    
    if (current==NULL)
        return;
    
    if (current->link ==NULL)
    {
        if (last!=NULL){
            struct node *temp = last->link;
            last->link = last->link->link;
            free(temp);
            return;
        }
        
        else{
            printf("Last Occurence not found");
            return;
        }
        
    }

    if (current->data == value){

       last = prior; 
       prior = current;
       return lastoccurence(prior,last,current->link,value);

    }
    
    else{
        prior = current;
        return lastoccurence(prior,last,current->link,value);
    }
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
insert(head,35);
insert(head,38);

display(head);

lastoccurence(NULL,NULL,head,39);
printf("\n");
display(head);
}