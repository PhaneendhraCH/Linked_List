/*

    Remove Last Occurence Node from a Linked List using static struct
    (To reduce no.of arguments in the function)

    Author : Phaneendhra

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

struct node *lastoccurence(struct node *current,
                        int value){
    
    static struct node *last,*prior;
    
    if (current==NULL)
        {
            if(last!=NULL && prior!=NULL){          // Removes last occurence of the node
            
            struct node *temp = last->link;         // store node to be removed
            
            last->link = last->link->link;          
            free(temp);                             // free last occurence node
            return 0;
            }
            
            else if(last==NULL && prior!=NULL){     // This is for node present at starting position
            struct node *temp = head;
            head  = head->link;
            free(temp);
            return 0;
            }
            
            else{                                   // If the node is not found 
            printf("Last Occurence not found");
            return NULL;
        }
        }


    if (current->data == value){                    // if the value to be removed is present

       
       last = prior;                                // assign last with prior
       prior = current;                             // assign prior with current (prior contains a node before current node)
       return lastoccurence(current->link,value);    // traverse LL until last node

    }
    
    else{                                           // if the value to be removed is not present
        prior = current;                            // assign prior with current (prior contains a node before current node)
        return lastoccurence(current->link,value);   // traverse LL until last node
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

lastoccurence(head,39);
printf("\n");
display(head);
}/*

    Remove Last Occurence Node from a Linked List

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

struct node *lastoccurence(struct node *current,
                        int value){
    
    static struct node *last,*prior;
    
    if (current==NULL)
        {
            if(last!=NULL && prior!=NULL){          // Removes last occurence of the node
            
            struct node *temp = last->link;         // store node to be removed
            
            last->link = last->link->link;          
            free(temp);                             // free last occurence node
            return 0;
            }
            
            else if(last==NULL && prior!=NULL){     // This is for node present at starting position
            struct node *temp = head;
            head  = head->link;
            free(temp);
            return 0;
            }
            
            else{                                   // If the node is not found 
            printf("Last Occurence not found");
            return NULL;
        }
        }


    if (current->data == value){                    // if the value to be removed is present

       
       last = prior;                                // assign last with prior
       prior = current;                             // assign prior with current (prior contains a node before current node)
       return lastoccurence(current->link,value);    // traverse LL until last node

    }
    
    else{                                           // if the value to be removed is not present
        prior = current;                            // assign prior with current (prior contains a node before current node)
        return lastoccurence(current->link,value);   // traverse LL until last node
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

lastoccurence(head,39);
printf("\n");
display(head);
}