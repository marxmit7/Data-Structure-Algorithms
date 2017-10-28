#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int key;
    struct node *left;
    struct node *right;
    int height;

};


typedef struct node Node;


int max(int a,int b)
{
    return (a>b)?a:b;
};


int height(Node *root)
{
    if(root==NULL)
        return 0;
    return root->height;
}

Node *newNode(Node *root, int value)
{

    Node *tmp=(Node *)malloc(sizeof(Node));
    tmp->data=value;
    tmp->left=NULL;
    tmp->right=NULL;
    tmp->height=1;
    return (tmp);
}

Node *rightRotate(Node *y)
{
    Node *x=y->left;
    Node *t2=x->right;
    x->right=y;
    y->left=t2;

    x->height= max(height(x->left) ,height(x->right)) +1;
    y->height= max(height(y->left) , height(y->right)) +1;


    return x;
}
Node *leftRotate(Node *x)
{
    Node *y=x->right;
    Node *t2=y->y->left;

    x->left=y;
    y->right=t2;

    x->height=max(height(x->left),height(x->right)) +1;
    y->height= max(heigt(y->left),height(y->right)) +1;

    return y;
}


int getBalance(Node *n)
{
    if(n==NULL)
        return 0;
    return height(n->left) -height(n->right);

}

Node *insert(Node *root,int value)
{
    if(root==NULL)
        return newNode(value);
    if(value<root->data)
        root->left=insert(root->left,value);
    else if(value> root->data)
        root->right=insert(root->right,value);
    else 
        return root;
    
    root->height= 1+ max(height(root->left),height(root->right));

    int balance=getBalace(root);

    if(balance>1 && value<root->left->data)
        return rightRotate(root);
    if(balance <-1 && value>root->right->data)
        return leftRotate(root);
    if(balance >1 && value>root->left->data)
        {
            root->left=leftRotate(root->left);
                return rightRotate(root);
        }
    if(balance<-1 && value<root->right->data)
    {
        node->right=rightRotate(root->right);
            return leftRotate(root);
    }
    
    return root;
}