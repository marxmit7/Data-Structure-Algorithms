
void bubblesort(int arr[],int n)
{
    int tmp;
    for(int i=0;i<n-1;i++)// n-1 for since the last comparison is aleardy sorted
    {
        for(int k=0;k<n-i-1;k++)// n-i-1 just to leave the comparisons between the aleardy sorted elements
        {
            if(arr[k]>arr[k+1]) //comparison
            {
                tmp=arr[k]; // temporarily assigning the greater value
                arr[k]=arr[k+1]; // assigning the greater value
                arr[k+1]=tmp // assigning the lower value
            }
        }
    }
}