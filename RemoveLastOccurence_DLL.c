/*

    Remove Last Occurence Node from a Double Linked List using static struct
    (To reduce no.of arguments in the function)

    Author : Phaneendhra

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
       newnode->prev = NULL;
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
        
        root->link = newnode;
        newnode->prev = root;
        tail = newnode;         // tail gets updated for every insertion of a node
   }
   
  // return root;
}


struct node *lastoccurence(struct node *current,
                        int value){
    
    static struct node *last,*prior;
    static int flag = 0;
    
    if (current==NULL)
        {
            if (flag){
                
            if(last!=NULL && prior!=NULL){              // Removes last occurence of the node
                
                if (prior->data ==  value){             // if the node is last node in Double linked list
                    
                    struct node *temp = last->link;
                    
                    last->link->prev = NULL;
                    last->link = NULL;
                    tail = last;
                    free(temp);
                    return 0;
                    
                }
                printf("\nlast : %d prior: %d",last->data,prior->data);
    
                /* If the node is intermediate b/w start and end */
                
                struct node *temp = last->link;         // store node to be removed
                        
                last->link->link->prev = last;
                        
                last->link = last->link->link;          
            
                free(temp);                             // free last occurence node
                return 0;
                
            
            }
            
            else if(last==NULL && prior!=NULL){     // This is for node present at starting position
            
            struct node *temp = head;
            
            temp->link->prev = NULL;
            head  = head->link;
            free(temp);
            return 0;
            }
            else{
                return 0;
            }
            
            }
            
            else{                                   // If the node is not found 
            printf("Last Occurence not found");
            return NULL;
        }
        }


    if (current->data == value){                    // if the value to be removed is present

       flag = 1;                                    // assign flag to one if value is present in node
       last = prior;                                // assign last with prior
       prior = current;                             // assign prior with current (prior contains a node before current node)
       return lastoccurence(current->link,value);    // traverse LL until last node

    }
    
    else{                                           // if the value to be removed is not present
        prior = current;                            // assign prior with current (prior contains a node before current node)
        return lastoccurence(current->link,value);   // traverse LL until last node
    }
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

void display_back()
{
    struct node *disp;
    disp = tail;
    while (disp!=NULL){
        
        printf("%d\t",disp->data);
        disp = disp->prev;
        
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
    lastoccurence(head,50);
    printf("\n");
    display();
    printf("\n");
    display_back();
    
    
}