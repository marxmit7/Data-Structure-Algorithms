#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node Node;

Node *root=NULL;
Node * getNode(int val)
{
    Node * tmp=(Node *)malloc(sizeof(Node));
    tmp->data=val;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}

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

Node * minValue(Node *root)
{
    Node *tmp;
    tmp=root;
    while(tmp->left!=NULL)
        tmp=tmp->left;
    
return tmp;
}

Node * delete(Node *root,int value)
{
    Node * current,*parent,*tempNode;
    tempNode=root;

    if(root==NULL)
        return NULL;
    
    if(value<tempNode->data)
        tempNode->left=delete(tempNode->left,value);
    else if(value>tempNode->data)
        tempNode->right=delete(tempNode->right,value);
    //deletion of node having both the children as NULL
    else
    {
        if(tempNode->left==NULL&&tempNode->right==NULL)
            {
                tempNode=NULL;
                return tempNode;
            }
        else if(tempNode->left==NULL)
        {
            Node *tmp =tempNode->right;
            free(tempNode);
            return tmp;
        }
        else if(tempNode->right==NULL)
        {
            Node *tmp=tempNode->left;
            free(tempNode);
            return tmp;
        }
        else
        {
            Node *tmp=minValue(tempNode->right);
            tempNode->data=tmp->data;
            tempNode->right=delete(tempNode->right,tempNode->data);

        }
    }
    return tempNode;

}


void inorder(Node *root)
{
    if(root==NULL)
    return ;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
int main() {
	/*Code To Test the logic
	  Creating an example tree
	            5
			   / \
			  3   10
			 / \   \
			1   4   11
    */
	root = insert(root,5); root = insert(root,10);
	root = insert(root,3); root = insert(root,4); 
	root = insert(root,1); root = insert(root,11);

	// Deleting node with value 5, change this value to test other cases
	root = delete(root,5);

	//Print Nodes in Inorder
	printf("inorder\n");
	inorder(root);
	printf("\n");
}