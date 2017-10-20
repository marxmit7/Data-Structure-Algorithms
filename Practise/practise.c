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

Node * insert(Node *root)
    {   
        Node *current,*parent;
        Node *tmp=(Node *)malloc(sizeof(Node));
        printf("Enter the data into the node\n");
        int val;
        scanf("%d",&val);
        tmp->data=val;
        tmp->left=NULL;
        tmp->right=NULL;

        if(root==NULL)
            return root=tmp;
        else
        {
            current=root;
            parent=NULL

            while(current!=NULL)
            {
                parent=current;
                if(val<current->data)
                    current=current->left;
                else
                    current=current->right;

            }

            if(val<parent->data)
                parent->left=tmp;
            else 
                parent->right=tmp;
        }

    return root;
    }