#include<stdio.h>
#include<stdlib.h>


void mergesort(int arr[],int l ,int r)
{
    if(l<r)
    {
        int m= l+ (r-l)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merges(left,l,m,r);
    }

}

void merge(int arr[],int l, int m, int r)
{

    n1 = m-l+1;
    n2 = r-m;
    int k=0,i=0,j=0;
    int left[n1],right[n2];

    for(i=0;i<n1;i++)
        left[i]=arr[l+i];
    for(j=0;j<n2;j++)
        right[j]=arr[m+j+1];

    int k=l,i=0,j=0;

    while(i<n1 && j<n2)
    {
        if(left[i]<=right[j])
        {
            arr[k]=left[i];
            i++;
            k++;
        }
        else
        {
            arr[k]=right[j];
            j++;
            k++;
        }

    }
    while(i<n1)
    {
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=right[j];
        j++;
        k++;
    }
    
}


int mian()
{   printf("enter the no of elements \n");
    int n;
    scanf("%d",&n);
    printf("Create the  array of elements \n" );
    
    int arr[n],i;
    for(i=0;i<n;i++)
        scanf("%d ",&arr[i]);
    
    mergesort(arr,0,n);

}