#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
typedef struct node Node;
 Node *head=NULL;

//********************************************************************************

Node *addend()
{
    Node *tmp,*p,*q;
    p=head;
    tmp=(Node *)malloc(sizeof(struct node));
    printf("enter the data into the Node\n");
    scanf("%d",&tmp->data);
    tmp->next=NULL;
    if(head==NULL)
    {
        head=tmp;
        tmp->prev=NULL;
        
    }
    else
    {
        while(p!=NULL)
            {
                q=p;
                p=p->next;
            }
        tmp->prev=q;
        q->next=tmp;
    }

    return head;
}
//********************************************************************************
void display()
{
    Node *p;
    p=head;
    printf("NULL-->");
    while(p!=NULL)
    {
        printf(" %d-->",p->data);
        
        p=p->next;
    }
    printf(" NULL\n");
    p=head;
    printf("NULL ");
    while(p!=NULL)
    {
        printf("<--%d ",p->data);
        p=p->next;
    }
    printf("<--NULL");

}

//********************************************************************************
int main()
{
    int choice;
    while(1)
    {
        printf("\n ***enter the option to take the operation***\n");
        printf("\n\t\t\t 1:  add new node at the end\n");
        printf("\n\t\t\t 9:  display the created linked list\n");
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
            case 9:
            {
                display();
                break;
            }
            case 0:
            {
                exit(0);
                break;
            }
            default:
            {
                printf("\n wrong input please try again");
            }
        }
    }

return 0;
}