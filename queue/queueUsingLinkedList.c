#include<stdio.h>
#include<stdlib.h>

struct qnode
{
    int data;
    struct qnode *next;
}*front=NULL,*rear=NULL;

typedef struct qnode *qnode;

void insert()
{   qnode tmp;
    int val;
    tmp=(qnode)malloc(sizeof(qnode));
    printf("enter the data into the queue\n");
    scanf("%d",&val);
    tmp->data=val;
    tmp->next=NULL;

    if(front==NULL)
    {
        front =rear=tmp;
    }
    else 
    {
        rear->next=tmp;
        rear=tmp;
    }
    printf("insertion is succesfull\n");
}

void delete()
{
    if(front==NULL)
    {printf("queue is underflow\n");
    return ;
    }
    else 
    {
        qnode p;
        p=front;
        front=front->next;
        printf("%d has been removed from the memory\n",p->data);
        free(p);
    }
}

void display()
{qnode p=front;
    if(p==NULL)
    {
        printf("the queue is empty\n");
    }
    else
    {
        while(p!=NULL)
        {
            printf("( %d )---",p->data);
            p=p->next;
        }
        printf("( NULL )\n");
    }
}

int  main()
{
    int choice ;
    while(1)
    {
        printf("\t\t\t******-------> enter the choice from the below menu <-------****** \n");
        printf("\t\t\t       1: to insert element into the queue \n");
        printf("\t\t\t       2: to delete element from the queue \n");
        printf("\t\t\t       3: to display the elements present in the queue  \n");
        printf("\t\t\t       4: to exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
                break;
            default: printf("wrong input\n");
        }

    }
return 0;
}
