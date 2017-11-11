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
    int n,i,j;
    int o=0,e=0;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            if(arr[i]%2==0)
                {
                    e=e + arr[i];
                    
                }
            else
                {
                    o=o + arr[i];
                }
        }
    insertion_sort(arr,n);

    for(i=0;i<n;i++)
    {   if(arr[i]%2==0)
        printf("%d ",arr[i]);
    }
        printf("%d ",e);
    for(i=0;i<n;i++)
    {   if(arr[i]%2==1)
        printf("%d ",arr[i]);
    }
        printf("%d ",o);
    

return 0;
}