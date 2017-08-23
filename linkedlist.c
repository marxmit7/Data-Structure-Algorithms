#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* start=NULL;
typedef struct node Node;
// Node * create()
// {
//     Node *tmp;
//     tmp=(Node*)malloc(sizeof(struct node));
//     tmp->next=NULL;
//     return tmp;
// }
//*********************************************************************************
Node *addend() //addition of  node at the end of the linked list
{
    Node *temp,*p;
    temp=(Node*)malloc(sizeof(struct node));
    printf("enter the data to be added into the node\n");
    scanf("%d",&temp->data);
    if(start==NULL)
    {  
        temp->next=NULL;
        start=temp;
    }
    else
    {
        p=start;
        while(p->next!=NULL)
            p=p->next;
        p->next=temp;
        temp->next=NULL;
    }
    return start;
}
//*************************************************************************
Node* addnth(int pos)// for the addition at the nth position
{
    Node *tmp,*p,*q;
    tmp=(Node*)malloc(sizeof(struct node));
    p=start;
    printf("enter the data into the node\n");
    scanf("%d",&tmp->data);
    int x=pos-1;
    if(x==0)
    {
        tmp->next=start;
        start=tmp;
        return start;
    }
    else
    {
        while(x--)
        {   q=p;
            p=p->next;
        }
    tmp->next=p;
    q->next=tmp;
    }
return start;
}
//****************************************************************************

Node *addbeg()//for the  addition of the node at the begining
{
    Node *tmp;
    tmp=(Node*)malloc(sizeof(struct node));
    printf("enter the data into the new node \n");
    scanf("%d",&tmp->data);
    tmp->next=start;
    start=tmp;
    return start;
}
//****************************************************************************
Node *delend()
{
    Node *p,*q;
    p=start;
    while(p->next!=NULL)
        {
            q=p; //selection of previous node
            p=p->next;
        }
    q->next=NULL;
    free(p);
    return start;
}
//****************************************************************************
Node *delnth(int pos)
{
    Node *p,*q;
    p=start;
    int x=pos-1;
    if(pos==1)
    {
        start=start->next;
        free(p);
    }
    else
    {
        while(x--)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        free(p);
    }
    return start;
}
//****************************************************************************
Node *circle()
{
    Node *p;
    p=start;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=start;
return start;
}

//****************************************************************************
//reversing a linked list 
Node *Reverse()
{
    Node *prev,*current,*next;
    current=start;
    prev=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    start=prev;
return start;
}

//****************************************************************************
void display()
{
    Node *q;
    q=start;
    printf("final linked list is \n\n\t\t\t\tSTART-->");
    while(q!=NULL)
    {  
        printf(" %d-->",q->data);
        q=q->next;
    }
    printf("NULL\n\n");
}   

int main()
{
    int i,choice;
    // printf("enter the no of linked list\n");
    // scanf("%d",&n);
    
while(1)
    {
        printf("\n ***enter the option to take the operation***\n");
        printf("\n\t\t\t 1:  add new node at the end\n");
        printf("\n\t\t\t 2:  add new node at the beggining of the linked list\n");
        printf("\n\t\t\t 3:  add new node at nth position\n");
        printf("\n\t\t\t 4:  delete the last node of the linked list\n");
        printf("\n\t\t\t 5:  delete the nth node of the linked list\n");
        printf("\n\t\t\t 6:  make it a circular linkedlist\n");
        printf("\n\t\t\t 7:  reverse the current linkedlist\n");
        printf("\n\t\t\t 9:  display the created linked list\n");
        printf("\n\t\t\t 0: to exit the operation\n");
        printf("\n\t\t\t***enter the option to be done***\n");
        here: scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
            {
                addend();
                break;
            }
            case 2:
            {
                addbeg();
                break;
            }
            case 3:
            {   int pos;
                printf("enter the nth position at which the node to be add\n");
                scanf("%d",&pos);
                addnth(pos);
                break;
            }
            case 4:
            {
                delend();
                printf("last node of the linkedlist has been deleted\n");
                break;
            }
            case 5:
            { printf("enter the nth position of the node to be deleted\n");
                int a;
                scanf("%d",&a);
                delnth(a);
                printf("%dth node has been deleted",a);
                break;
            }
            case 6:
            {
                circle();
                printf("now the linked list is circular\n");
                break;
            }
            case 7:
            {
                Reverse();
                printf("the linked list has been reversed\n");
                break;
            }
            case 9:
            {   display();
                break;
            }
            case 0:
            {
                exit(0);
                break;
            }
            default: 
            {
                printf("\nwrong input entered please try again\n");
            
            }
        }
    }
return 0;
}
