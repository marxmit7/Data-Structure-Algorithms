int partition(int a[], int start,int end)
{
    int piv=a[end];
    int i=start-1;
    for(int j=start;j<end;j++)
    {
        if(a[j]<piv)
        {
            swap(&a[j],&a[i]);
            i++;
        }
    }
    swap(&a[i+1],&a[end]);
    return i+1;
}

void quicksort(int a[],int start,int end)
{ int q;
    if(start<end)
    {   q=partition(a,start,end);
        quicksort(a,start,q-1);
        quicksort(a,q+1,end);
    }
}

void swap(int *a,int *b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}