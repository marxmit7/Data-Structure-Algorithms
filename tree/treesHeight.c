int height(Node* root) 
{
    // Write your code here.
    if(root==NULL)
        return -1;
    int x=height(root->left);
    int y=height(root->right);
    if(x>y)
        return x+1;
    else 
    return y+1;
}