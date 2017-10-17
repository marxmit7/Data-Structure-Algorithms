void topview(node*root)
{
    int arr[100];
    int i=0;
    node * tmp;
    tmp=root->left;
    while(tmp!=NULL)
    {
        arr[i]=tmp->data;
        i++;
        tmp=tmp->left;
    }
    while(i--)
    {
        printf("%d ",arr[i]);
    }
    tmp=root;

    while(tmp!=NULL)
    {
        printf("%d ",tmp->data);
        tmp=tmp->right;

    }

}