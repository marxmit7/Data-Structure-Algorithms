node * delete(node * root,int val)
{
    node * current;
    if(root==NULL)
        return root;
    if(val<root->val)
        root->left=delete(root->left,val);
    else if(val>root->val)
        root->right=delete(root->right,val);
    else
    {//o child
        if(root->left==NULL&& root->right==NULL)
        {
            free(root);
            root=NULL;
        }
        //for 1 child
        else if(root->left==NULL)
        {
            node * tmp=root;
            root=root->right;
            free(tmp);
            return root;
        }
        else if(root->right==NULL)
        {
            node * tmp=root;
            root=root->left;
            free(tmp);
            return root;

        }
        else//for 2 children
        {
            node * tmp=find(root->right);
            root->data=tmp->data;
            root->right=delete(root->right,tmp->data);
        }


    }

    return root;
}