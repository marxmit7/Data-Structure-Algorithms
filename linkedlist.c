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
//****************************************************************************
Node *addbeg()
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
        printf("\n\t\t\t 3:  display the created linked list\n");
        printf("\n\t\t\t 0: to exit the operation\n");
        printf("\n\t\t\t***enter the option to be done***\n");
        scanf("%d",&choice);
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
            {   display();
                break;
            }
            case 0:
            {
                exit(0);
                break;
            }
            default: 
            
                printf("\nwrong input entered\n");
                break;
        }
    }
return 0;
}
