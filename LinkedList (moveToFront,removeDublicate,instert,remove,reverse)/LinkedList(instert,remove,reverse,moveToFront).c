/******************************************************************************

created by @AhmetKara
GitHub: https://github.com/ahmetQara

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    int key;
    struct node *next;
};

    struct node *head=NULL;
    struct node *current=NULL;

void printList(){
    struct node *ptr=head;
    printf("\n[");
    
    while(ptr!=NULL){
        printf("(%d)",ptr->data);
        ptr=ptr->next;
    }
    printf("]");
}

void InstertFirst(int key, int data){
    struct node *link=(struct node*)malloc(sizeof(struct node));
    link->key=key;
    link->data=data;
    link->next=head;
    head=link;
}

struct node* deleteFirst(){
    struct node *tempLink=head;
    head=head->next;
    return tempLink;
}

struct node* deleteWithKey(int key)
{
    struct node* current=head;
    struct node* previous=NULL;
    
   if(head==NULL) return NULL;
    
    while(current->data!=key)
    {
        if(current->next==NULL){
            return NULL;
        }else {
            previous=current;
            current=current->next;
        }
    }
    
    if(current==head){
        head=head->next;
    }else {
        previous->next=current->next;
    }
    return current;
}

void removeDublicate()
{
    struct node* current=head; 
    struct node* temp;
    
    if(current==NULL) return;
    
    while(current->next!=NULL)
        {
            if(current->data==current->next->data)
            {
                temp=current->next->next;
                free(current->next);
                current->next=temp;
            }else
                {
                    current=current->next;
                }
        }
}

void reverse()
{
    struct node *current=head;
    struct node *prev=NULL,*next=NULL;
    
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
}

void moveToFront() // move last item to front
{
    struct node *secLast=NULL;
    struct node *last=head;
    
    while(last->next!=NULL)
    {
        secLast=last;
        last=last->next;
    }
    secLast->next=NULL;
    last->next=head;
    head=last;
}

int main(){
    
    InstertFirst(1,1);
    InstertFirst(2,2);
    InstertFirst(3,3);
    InstertFirst(4,3);
    InstertFirst(4,4);
    InstertFirst(5,4);
    InstertFirst(6,5);
    printList();
    deleteWithKey(2);
    printList();
    removeDublicate();
    printList();
    reverse();
    printList();
    moveToFront();
    printList();
    
}