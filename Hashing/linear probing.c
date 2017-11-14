#include<stdio.h>
#include<stdlib.h>

#define size 22
int hashTable[size];

void hashinit()
{
    for(int i=0;i<size;i++)
        hashTable[i]=-1;
}

//displauing of hash table

void display()
{
    for(int i=0;i<size;i++)
        printf("%d",hashTable[i]);
    
}
/* 
inserting value in  linear probing
h[k,i]=(h'[k]+i)mod m
where m is the size of the hash table
h'[k]= key mod m
mod= %  operator
*/
void linearInsert(int key)
{
    int index=0, m=size;
    int hkey=key%m;
    index=(hkey)%m;
    while(hashTable[index]!=-1 && i<size)
        {
            index= (hkey+i)%m;
            i++;
        }
    hashTable[index]=key;
}


int search(int keyfind)
{
    int index=0,m=size;
    int hkey=keyfind%m;
    for(int i=0;i<size;i++)
    {
        index=(hkey+i)%m;
        if(hashTable[index]==keyfind)
            return index;
        else
            return -1;
    }
}

void deletelinear(int delkey)
{
    int index=search(delkey);
    if(index==-1)
        printf("cannot delete the value in the index\n");
    else 
        hashTable[index]=-1;
}

