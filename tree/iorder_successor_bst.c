#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node *right;
};

typedef struct node Node ;

Node *newNode(int value)
{
    Node * tmp=(Node *)malloc(sizeof(Node));
    tmp->data=value;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}

Node * insert(Node *root,int value)
{
    if(root==NULL)
        {
            root=newNode(value);
            return root;
        }
    if(value<=root->data)
    {
        root->left=insert(root->left,value);
    }
    else 
    {
        root->right=insert(root->right,value);
    }
return root;
}



Node *findpresuc(Node *root,Node *&pre,Node *&suc,int value)
{   
    if (root==NULL)
        return ;
        //largest value in left subtree will be the  predecessor of the element
    if(root->data==value)
    {
        if(root->left!=NULL)
        {
            Node *tmp=root->left;
            while(tmp->right!=NULL)
            {
                tmp=tmp->right;
            }
            pre=tmp;
        }
        //minimum value in right subtree will be the successor of the element
        if(root->right!=NULL)
        {
            Node *tmp=root->right;
            while(tmp->left!=NULL)
                tmp=tmp->left;
            suc=tmp;
        }
    
        return;    
    }

    else
    {
        if(value<root->data)
        {
            suc=root;
            findpresuc(root->left,pre,suc,value);
        }
        else 
        {
            pre=root;
            findpresuc(root->right,pre ,suc,value);
        }


    }
}


int main()
{
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 32);
    insert(root, 22);
    insert(root, 45);
    insert(root, 73);
    insert(root, 66);
    insert(root, 823);

    int value = 45;
    Node* pre = NULL, *suc = NULL;
    
    findPreSuc(root, pre, suc, key);
}