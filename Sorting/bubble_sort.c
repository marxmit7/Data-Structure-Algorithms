void bubblesort(int arr[],int n)
{
    int tmp;
    for(int i=0;i<n-1;i++)
    {
        for(int k=0;k<n-i-1;k++)
        {
            if(arr[k]>arr[k+1])
            {
                tmp=arr[k];
                arr[k]=arr[k+1];
                arr[k+1]=tmp;
            }
        }
    }
}