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
    tmp->data=value;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;

}
#define count 110
Node *insert(Node *root,int value)
{
    if(root==NULL)
        {
            root=newNode(value);
            return root;
        }
    if(value<root->data)
        root->left=insert(root->left,value);
    if(value>root->data)
        root->right=insert(root->right,value);
    return root;
}

void inorder(Node *root)
{
    if(root==NULL)
        return ;

    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int arr[count],i=0;
void kath(Node *root,int position)
{   
    if(root==NULL)
        return ;

    kath(root->left,position);
    if(root!=NULL)
    {
        arr[i]=root->data;
        i++;
        if(i==position)
            printf("\nthe element present at %dth position is %d \n",i,root->data);
    }
    kath(root->right,position);
    
        
}


int main()
{   Node * root=NULL;
 
   root= insert(root,45);
    
    insert(root,3);
    insert(root,23);
    insert(root,76);
    insert(root,34);
    insert(root,87);
    insert(root,34);
    insert(root,98);
    insert(root,55);
    insert(root,44);
    insert(root,11);
    insert(root,865);
    insert(root,98);
    insert(root,56);
    
    // inorder(root);
    kath(root,4);
}