//starting with the  basic of tree
#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *left ;
    struct node *right;
};

typedef struct node Node;
Node *tree=NULL;

Node* insert(Node *root)
{
    Node *tempNode,*current,*parent;
    tempNode=(Node*)malloc(sizeof(Node));
    printf("Enter the data of the Node element\n");
    scanf("%d",tempNode->data);
    tempNode->left=NULL;
    tempNode->right=NULL;

    if(root==NULL)
        root=tempNode;
    
    else
        {
            current =root;
            parent= NULL;

            while(current!=NULL)
            {
                parent=current;
                if(tempNode->data<current->data)
                    current=current->left;
                else 
                    current=current->right;
            }
            if(tempNode->data<parent->data)
                parent->left=tempNode;
            else
                parent->right=tempNode;
        }
    return root;
}

void preOrderTraversal(Node *root)
{
    if(root==NULL)
    return ;
    printf("%d ",root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);

}
void inOrderTraversal(Node *root)
{
    if(root==NULL)
    return;
    inOrderTraversal(root->left);
    printf("%d ",root->data );
    inOrderTraversal(root->right);
}
void postOrderTraversal(Node *root)
{
    if(root==NULL)
    return ;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ",root->data);
}

void smallestelement(Node *root)
{
    Node *temp=root;
    if(root==NULL)
        printf("no element exist\n");
    else
    {
        while(temp->left!=NULL)
        {
            temp=temp->left;
        }
        printf("smallest element in the tree is %d \n",temp->data);
    }
}
void largestelement(Node *root)
{
    Node *temp=root;
    if(root==NULL)
        printf("no element exist\n");
    else
    {
        while(temp->right!=NULL)
        {
            temp=temp->left;
        }
        printf("largest element in the tree is %d\n",temp->data);
        
    }
}