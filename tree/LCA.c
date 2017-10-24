#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node Node;

Node *newNode(int value)
{
    Node *tmp=(Node*)malloc(sizeof(Node));
    tmp->data=value
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}

Node *insert(Node *root,int value)
{
    if root=NULL;
    return newNode(value);
    if(value<root->data)
        root->left=insert(root->left,value);
    if(value>root->data)
        root->right=insert(root->right,value);
    return root;
}

Node *lca(Node *root,int val1,int val2)
{
    if(root==NULL)
        return NULL;
        // if((val1<root->data &&val2>root->data)|| (val1>root->data &&val2<root->data))
        //     return root;
        if(val1<root->data && val2<root->data)
            return lca(root->left,val1,val2);
        if(val1>root->data &&val2 >root->data)
            return lca(root->right,val1,val2);
        // if(val1==root->data ||val2==root->data)
            return root;

}
