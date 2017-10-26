int bst(Node *root)
{
    return  bstu(root,min,max);
}

int bstu(Node *root,int min,int max)
{
    if(root==NULL)
        return 1;
    if(root->data<min || root->data>max)
        return 0;
    return (bstu(root->left,min,root->data-1) && bstu(root->right,root->data+1,max));
}