#include<stdio.h>
#include<stdlib.h>
void insertion_sort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int tmp=arr[i];
        int j=i;
        while(j>0&& tmp<arr[j-1])
        {
            arr[j]=arr[j-1];
            j=j-1;
        }
        arr[j]=tmp;
    }
}

int main()
{
    printf("enter the no of elements \n");
    int n;
    scanf("%d" ,&n);
    int arr[n];
    printf("enter the elements into the array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("sorted array \n");
    insertion_sort(arr,n);
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}