#if 0

Detecting loop in linked list 
Source : https://www.javatpoint.com/detect-loop-in-a-linked-list

#endif

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
}*head;



struct node *insert(int num ){
    
    struct node *temp = malloc(sizeof(struct node));
    temp->data = num;
    temp->link = NULL;
    return temp;
    
}

int countnodes(struct node *temp){
    
    int count=1;
    struct node *n = temp;
    while(temp->link!=n){
        temp = temp->link;
        count++;
    }
    return count;
    
}

int detectloop(struct node *temp) {  
    
       struct node *S = temp, *F=temp;  
       
       while(S && F && F->link) {  
           
        S=S->link;  
        F=F->link->link;  
        
        if(F==S)  
        {  
           printf("loop exists\n");  
           return  countnodes(S);
        }  
    }  
return 0;  
}  


void display(struct node *temp){
    while(temp){
        printf("%d ",temp->data);
        temp = temp->link;
    }
}

int main(){
    head = insert(10);
    head->link = insert(20);
    head->link->link = insert(30);
    head->link->link->link  = head->link;
    //display(head);
    printf("Total No.of nodes residing in a loop : %d",detectloop(head));
    
}