//this program is the application  of enque to insert and delete element from a queue using array
#include<stdio.h>
#include<stdlib.h>
int front =-1,rear=-1;
#define max 10
int arr[max];
void insert()
{
    int val;
    if(rear>=max-1)
    {
        printf("########################  overflow  ###########################\n");
        return;
    }
    else if(front==-1&&rear==-1)
            front=rear=0;
    else    
        {
        rear++;
        } 
        printf(" \t\t\t\tenter the element to be inserted\n");
        scanf("%d",&val);
    arr[rear]=val;
}

void  delete()
{int  tmp;
    if(front==-1 ||front>rear)
    {printf("underflow\n");
    return ;}
    else 
    {   tmp=arr[front];
        front++;
    }
    printf("%d has been deleted",tmp);
}

void display()
{
    if(front==-1&&rear==-1)
        printf("queue is empty\n");
    else
    {
        for(int i=front;i<=rear;i++)
        {
            printf("%d\t",arr[i]);
        }
    }
    printf("\n");
}

int main()
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
}
