#include<stdio.h>
#include<stdlib.h>

#define size 30

int hashTable[size];

void hashinit()
{
    for(int i=0;i<size;i++)
        hashTable[i]=-1;
}

void insertdouble(int key)
{
    int index=0,m1=size,m2=size-1;
    int h1=key%m1;
    int h2=key%m2;
    int index= (h1 + i*h2)%m;

    while(hashTable[index]!=-1)
        {
            index=(h1 + i*h2)%m;
            i++;
        }
        hashTable[index]=key;

}

int search(int keyfind)
{
    int index=0,m1=size,m2-size-1;
    int h1=key%m1;
    int h2=key%m2;
    int index=(h1 + i*h2)%m;
    while(hashTable[index]!=keyfind && hashTable[index]!=-1)
    {   i++;
        index=(h1+ i*h2)%m ;
    }
    if(index==-1)
        return -1;
    else 
        return index;
}

void delete(int delkey)
{
    int index=search(delkey);
    if(index==-1)
        printf("data not found\n");
    else
        hashTable[index]=-1;
}