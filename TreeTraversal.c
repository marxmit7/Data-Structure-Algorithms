#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *leftchild;
    struct node *rightchild;
};

typedef struct node  Node;

Node *root=NULL;

void insert()
{
    Node *temp,*current,*parent;
    temp=(Node *)malloc(sizeof(Node));
    printf("Enter the element to be inserted\n");
    scanf("%d",&temp->data);
    temp->leftchild=NULL;
    temp->rightchild=NULL;

    if(root==NULL)
    {
        root=temp;
        return ;
    }
    else
    {
        current=root;
        parent=NULL;
        while(1)
        {   
            parent=current;
            if(temp->data < parent->data)
            {
                current=current->leftchild;
                {
                    if(current==NULL)
                    {
                        parent->leftchild=temp;
                        return;
                    }
                }
            }
            else
            {
                current=current->rightchild;
                {
                    if(current==NULL)
                        {
                            parent->rightchild=temp;
                            return;
                        }

                }
            }
        }
    }
    printf("%d has been inserted\n",temp->data);
}

Node *search(int data)
{
    printf("working \n");
    Node *temp;
    temp=root;
    if(data==root->data)
        {
            printf("the data is present in the root node\n");
            return root;
        }


    else
        {
            while(temp->rightchild!=NULL || temp->leftchild!=NULL )
            {
                if(data<temp->data)
                    {
                        temp=temp->leftchild;
                    }
                if(data>temp->data)
                    {
                        temp=temp->rightchild;
                    }
                if(data==temp->data)
                    {
                        printf("Data found \n");
                        return temp;
                    }

            }
            if(temp->rightchild==NULL || temp->leftchild==NULL )
            printf("Data not found\n");
            
        return temp;
        }

}
// Treversal
void preOrderTraversal(Node *root)
    {
        if(root==NULL)
            return ;
        printf("%d ",root->data);
        preOrderTraversal(root->leftchild);
        preOrderTraversal(root->rightchild);
    }

void inOrderTraversal(Node *root)
    {
        if(root==NULL)
            return ;
        inOrderTraversal(root->leftchild);
        printf("%d ",root->data);
        inOrderTraversal(root->rightchild);
    }

void postOrderTraversal(Node *root)
    {
        if(root==NULL)
            return ;
        postOrderTraversal(root->leftchild);
        postOrderTraversal(root->rightchild);
        printf("%d ",root->data);
    }



int main()
{
    int choice ;
    int x;
    while(1)
    {
        printf("\t\t\t --------------------TREE------------------\n");
        printf("\t\t\t Enter the choice \n");
        printf("\t\t\t 1: To enter the element into the tree\n");
        printf("\t\t\t 2: To search a given elenent \n");
        printf("\t\t\t 3: For the preOrderTraversal of the tree\n");
        printf("\t\t\t 4: For the inOrderTraversal of the tree\n");
        printf("\t\t\t 5: For the postOrderTraversal of the tree\n");
        printf("\t\t\t 0: To get out \n");

        scanf("%d",&choice);
        switch(choice)
            {
                case 1:
                    {
                        insert();
                        break;
                    }
                case 2:
                    {   printf("Enter the Data to be searched\n");
                        scanf("%d",&x);
                        search(x);
                        break;
                    }
                case 3:
                    {
                        preOrderTraversal(root);
                        break;
                    }
                case 4:
                    {
                        inOrderTraversal(root);
                        break;
                    }
                case 5:
                    {
                        postOrderTraversal(root);
                        break;
                    }
                case 0:
                    {
                        exit(1);
                        break;
                    }
                default: printf("wrong input try again !!!!!\n");

            }
    }

return 0;
}
