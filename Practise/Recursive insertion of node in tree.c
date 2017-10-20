#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *left;
    struct node *right;
}
typedef node Node;

Node *root=NULL;
Node * getNode(int val)
[
    Node * tmp=(Node *)malloc(sizeof(Node));
    tmp->data=val;
    tmp->left=tmp->right=NULL;
    return tmp
]

Node * insert(Node *root, int val)
{
    if(root==NULL)
        {
            root=getNode(val);
            return root;
        }

    if(root->data>val)
        root->left=insert(root->left,val);
    else if(root->data<val)
        root->right=insert(root->right,val);

        return root;
}

