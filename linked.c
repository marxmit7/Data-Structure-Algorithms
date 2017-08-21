#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* start=NULL;
typedef struct node Node;
Node * create()
{
    Node *tmp;
    tmp=(Node*)malloc(sizeof(struct node));
    return tmp;
}
Node *addend(Node *start,int data)
{
    Node *temp,*p;
    temp=create();
    temp->data=data;
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

Node * display(Node *start)
{
    Node *q;
    q=start;
    printf("final linked list is \n");
    while(q!=NULL)
    {
        printf("%d",q->data);
        q=q->next;
    }
    return start;
}   

int main()
{
    int i,x,n;
    printf("enter the no of linked list\n");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("enter the data of the linked list no %d\n",i+1);
        scanf("%d",&x);
        addend(start,x);
    }
    display(start);

return 0;
}
