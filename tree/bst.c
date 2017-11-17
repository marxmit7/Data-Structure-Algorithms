#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *left;
    struct node *right;
}
typedef struct node Node;

Node *root=NULL;

Node *newNode(int key)
{
    Node *tmp=(Node*)malloc(sizeof(Node));
    tmp->data=key;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}

Node *insert(Node *root,int key)
{
    if(root==NULL)
        return newNode(key);
    if(key<root->data)
        root->left=insert(root->left,key);
    else if(key>root->data)
        root->right=insert(root->right,key);
    else
        {
            printf("Dublicate or invalid input\n");
            return;
        }

    return root;
}


int height(Node *root)
{   if(root==NULL)
        return 0;
    return 1+max(height(root->left),height(root->right));
}

void inOrder(Node *root)
{
    if(root==NULL)
        return ;
    inOrder(root->left);
    printf("%d",root->data);
    inOrder(root->right);
}

void preOrder(Node *root)
{
    if(root==NULL)
        return ;
    printf("%d",root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    if(root==NULL)
        return ;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d",root->data);
}


using namespace std;
void levelOrder(Node *root)
{
    if(root==NULL)
        return;
    queue<Node*> = p;
    p.push(root);

    while(!p.empty())
    {
        Node *current=p.front();
        
            printf("%d",current->data);
        p.pop();
        if(current->left!=NULL)
            p.push(current->left);
        if(current->right!=NULL)
            p.push(current->right);
    }

}

Node *search(Node *root,int key)
{
    Node *tmp=root;
    while(tmp!=NULL || tmp->data==key)
    {
        if(key<tmp->data)
            tmp=tmp->left;
        else if(key>tmp->data)
            tmp=tmp->right;
        else
            return tmp;
    }
    return tmp;
}

Node *maxNode(Node *root)
{
    Node *tmp=root;
    while(tmp->right!=NULL)
        tmp=tmp->right;
    return tmp;
}

Node *minNode(Node *root)
{
    Node *tmp=root;
    while(tmp->left!=NULL)
        tmp=tmp->left;
    return tmp;
}

Node *deleteNode(Node *root,int key)
{
    if(root==NULL)
        return root;
    if(key<root->data)
        root->left=deleteNode(root->left,key);
    else if(key>root->data)
        root->right=deleteNode(root->right,key);
    else
        {
            if(root->left==NULL &&root->right==NULL)
                {
                    free(root);
                    root=NULL;
                }
            else if(root->right==NULL)
                {
                    Node *tmp=root;
                    root=root->left;
                    free(tmp);
                    return root;
                }
            else if(root->left==NULL)
            {
                Node *tmp=root;
                root=root->left;
                free(tmp);
                return root;
            }
            else
            {
                Node *tmp=minNode(root->right);
                root->data=tmp->data;
                root->right=deleteNode(root->right,key);
                free(tmp);

            }

        }
        return root;
}

