#include<stdio.h>
#include<stdlib.h>

int isitbst(Node *root)
{   
    if (root==NULL)
        return 1;
    if(root->left!=NULL && root->left->data>root->data)
        return 0;
    if(root->right!=NULL && root->right->data<root->data)
        return 0;
    if(!isitbst(root->left) || !isitbst(root->right))
        return 0;
}