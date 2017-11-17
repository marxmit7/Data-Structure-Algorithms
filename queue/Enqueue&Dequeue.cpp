#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};
typedef struct node Node;

struct queue
{
    Node *front,*rear;
};
typedef struct queue Queue;

Node *newNode(int key)
{
    Node *tmp=(Node *)malloc(sizeof(Node));
    tmp->data=key;
    tmp->next=NULL;
    return tmp;
}

Queue* createQueue()
{
    Queue* q=(Queue*)malloc(sizeof(Queue));
    q->front=NULL;
    q->rear=NULL;
    return q;
}
//***************************************************************
Node *enqueue(Queue* q,int key)
{
    Node *tmp=newNode(key);
    if(q->rear==NULL)
    {
        q->rear=q->front=tmp;
        return NULL;
    }
    else
    {   
        q->rear->next=tmp;
        q->rear=tmp;
        return q->rear;
    }
}

//***************************************************************
Node *dequeue(Queue *q)
{
    if(q->front==NULL)
        {
            return NULL;
        }
    else 
    {
        Node  *tmp=q->front;
        q->front=q->front->next;
        free(tmp);
    }
    if(q->front==NULL)
        q->rear=NULL;
    return q->front;
}


//***************************************************************

void printqueue(Queue* q)
{
    printf("%d\n",q->front->data);

}


//***************************************************************

int main()
{
    int n;
    Queue* p=createQueue();
    scanf("%d",&n);
    while(n--)
    {
        int x,y;
        scanf("%d",&x);
        if(x==1)
            {
                scanf("%d",&y);
                enqueue(p,y);
            }
        else if(x==2)
            {
                dequeue(p);
            }
        else
            printqueue(p);
    }

return 0;
}