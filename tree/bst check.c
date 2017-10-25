int checkBST(Node* root) 
{
    if(root==NULL)
        return 1;
    if(root->left!=NULL && maxvalue(root->left)>root->data)
        return 0;
    else if(root->right!=NULL && minvalue(root->right)<root->data)
        return 0;
    if(! checkBST(root->left) ||  !checkBST(root->right))
        return 0;
    return 1;
}

int maxvalue(Node *root)
{
    Node *tmp;
    tmp=root;
    while(tmp->right!=NULL)
        tmp=tmp->right;
    return tmp->data;
}

int minvalue(Node *root)
{
    Node *tmp;
    tmp=root;
    while(tmp->left!=NULL)
        tmp=tmp->left;
    return tmp->data;
}