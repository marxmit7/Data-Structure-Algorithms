#include<stdio.h>
#include<stdlib.h>
//stacks using linked list
struct snode
{
    int data;
    struct snode *next;
};
typedef struct snode *Snode;
Snode start=NULL;

void push(int x)
{   
    Snode temp,p;
    temp=( Snode)malloc(sizeof(struct snode));
    temp->data=x;
    if(start==NULL)
    {
        start=temp;
        temp->next=NULL;
    }
    else
    {
        temp->next=start;
        start=temp;
    }
}

int pop()
{ Snode tmp;
    int p;
    if(start==NULL)
        printf("empty stack\n");
    else{
        tmp=start;
        start=start->next;
        p=tmp->data;
        free(tmp);
    }
return p;
}

void display()
{
    Snode p;
    p=start;
    while(p!=NULL)
    {
        printf ("%d---->",p->data);
        p=p->next;
    }
    printf("\n");

}

int main()
{
    int choice ,x;
    while(1)
    {
        printf("enter the choice\n");
        printf("1: to push the element \n");
        printf("2: to pop the element\n");
        printf("3: to display the elements of the stack\n");
        printf("4 to exit\n");

        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("enter the element to be pushed\n");
                scanf("%d",&x);
                push(x);
                break;
            case 2:
                printf("%d has been popped\n",pop());
                break;
            case 3:
                printf(" displaying the elements\n");
                display();
                break;
            case 4:
                exit(1);

            
        }
    }
}
