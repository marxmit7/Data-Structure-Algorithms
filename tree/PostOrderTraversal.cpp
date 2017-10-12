#include<iostream>
#include<stdlib.h>
using namespace std;
//level order traversing of tree
struct node 
{
    int data;
    struct node *leftchild;
    struct node *rightchilde;
};

typedef struct node Node;
Node *root =NULL;
// function prototypes
Node ** createQueue(int *,int *);
void enQueue(Node ** root,int *,Node *);
Node *deQueue(Node**,int *);

void printLevelOrder(Node * root)
{   
    int rear,front;
    Node ** queue=createQueue(&front,&rear);
    Node * tempNode=root;

    while(tempNode)
    {
        printf("%d",tempNode->data);
        if(tempNode->leftchild)
            enQueue(queue,&rear,tempNode->leftchild);
        if(tempNode->rightchild)
            enQueue(queue,&rear,tempNode->rightchild);
        tempNode=deQueue(queue,&front); //deQueue node and make it tempNode
    }
}

Node **createQueue(int *front ,int *rear)
{
    Node ** queue=(Node**)malloc(sizeof(Node*)*1000);
    *rear= *front = 0;
    return queue;
}

void enQueue(Node**queue,int *rear,Node* newNode)
{
    queue[*rear]=newNode;
    (*rear)++;
}

Node *deQueue(Node**queue,int *front)
{
    (*front)++;
    return queue[*front -1];
}

Node * newNode(int data)
{
    Node * temp=(Node*)malloc(sizeof(Node));
    temp->data=data;
    temp->leftchild=NULL;
    temp->rightchild=NULL;
    return temp;
}

int main()
{
    
}