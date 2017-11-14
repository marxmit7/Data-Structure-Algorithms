
//quadratic probing

#include<stdio.h>
#include<stdlib.h>

#define size 30

int hashTable[size];

void hashinit()
{
    for(int i=0;i<size;i++)
        hashTable[i]=-1;
}

/* 
h(k,i)=[h'(k) + c1*i + c2*i*i] mod m
h'[k]=key mod m
*/

void insertquadratic(int key)
{
    int index=0,m=size;
    int hkey=key%m;
    int i=0;
    index=(hkey + 3*i + 5*i*i)%m;

    while(hashTable[index]!=-1 && i<size)
        {
            index=(hkey + 3*i + 5*i*i)%m;
            i++;
        }
    hashTable[index]=key;
}

int search(int keyfind)
{
    int index=0,m=size;
    int hkey=key%m;
    int i=0;
    index=(hkey +3*i + 5*i*i)%m;
    while(hashTable[index]!=keyfind && hashTable[index]!=-1)
        {
            index=(hkey +3*i + 5*i*i)%m;
            i++;
            
        }
        if(i>=size)
            return -1;
        else
            return index;
}

void delete(int delkey)
{
    int index=search(delkey)
    if(index==-1)
        printf("element not found\n");
    else
        hashTable[index]=-1;
}

