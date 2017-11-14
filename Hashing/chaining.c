#include<stdio.h>
#include<stdlib.h>
#define size 20

struct node 
{
    int data;
    struct node *next;
};
typedef struct node Node;

struct hash
{
    Node *head;
    int count;    
}
typedef struct hash Node_h;

Node_h * hashTable =NULL;

Node *newNode(int key)
{
    Node *tmp=(Node *)malloc(sizeof(Node));
    tmp->data=key;
    return tmp;
}

void insert(int key)
{   int m=size;

    int index=key%m;
    Node *tmp=newNode(key);
    
    if(!hashTable[index]->head)
    {
        hashTable[index]->head=tmp;
        hashTable[index]->count=1;
        return ;
    }
    tmp->next=(hashTable[index]->head);
    hashTable[index]->head=tmp;
    hashTable[index]->count++;
    return;

}

void delete(int key)
{   int m=size;
    int index=key%m,flag=0;
    Node *tmp,*myNode;
    myNode=hashTable[index]->head;
    if(!myNode)
        {
            printf("given data is not present in the table\n");
            return;
        }

    tmp=myNode;
    while(myNode!=NULL)
    {
        if(myNode->data==key)
        {
            flag=1;
            if(myNode==hashTable[index]->head)
                hashTable[index]->head=myNode->next;
            else
                tmp->next=myNode->next;
            
            hashTable[index]->count--;
            free(myNode);
            break;
        }
        tmp=myNode;
        myNode=myNode->next;
    }
    if(flag)
        printf("data deleted from the hashtable\n");
    else
        printf("data is not present in the hastable\n");
    return;
}

void search(int key)
{   
    int m=size;
    int index=key%m,flag=0;
    Node *myNode;
    myNode=hashtable[index]->head;
    if(!myNode)
    {
        printf("item is not available\n");
        return ;
    }
    while(myNode!=NULL)
    {
        if(myNode->data==key)
            {
                printf("element has been found %d ",myNode->data);
                flag=1;
                break;
            }
        myNode=myNode->next;
    }
    if(!flag)
        printf("element not found\n");
    return;
}

void display()
{
    Node *myNode;
    int i;
    for(int i=0;i<size;i++)
    {
        if(hashTable[i]->count==0)
            continue;
        myNode=hashTable[i]->head;
        if(!myNode)
            continue;
        while(myNode!=NULL)
        {
            printf("%d is the value",myNode->data);
            myNode=myNode->next;
        }
    }
    return;
}

