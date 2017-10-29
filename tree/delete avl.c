struct node 
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

typedef struct node Node;

Node *newNode(int value)
{
    Node *tmp=(Node *)malloc(sizeof(Node));
    tmp->data=value;
    tmp->left=NULL;
    tmp->right=NULL;
    tmp->height=1;
}
 
int height (Node *root)
{
    if(root==NULL)
        return 0;
     return  root->height;
}

int max(int a,int b)
{
    return (a>b)?a:b;
}


Node *rightRotate(Node *y)
{
    Node *x=y->left;
    Node *t2=x->right;

    x->right=y;
    y->left=t2;

    x->height= max(height(x->left) , height(x->right)) +1;
    y->height=max(height(y->left),height(y->right)) +1;

    return x;
}

Node *leftRotate(Node *x)

{
    Node *y=x->right;
    Node *t2=y->left;

    y->left=y;
    x->right=t2;

    y->height=max(height(y->let),height(y->right)) +1;
    x->height=max(height(x->left),height(x->right)) +1;

    return y;
}

int getBalance(Node *root)
{   if(root==NULL)
        return 0;
    return height(root->left) - height(root->right);
}



Node *insert(Node *root,int value)
{
    if(root==NULL)
        return newNode(value);
    if(value<root->data)
        root->left=insert(root->left,value);
    else if(value>root->data)
        root->right=insert(root->right,value);
    else    
        root;

    root->height= 1+ max(height(root->left),height(root->right));
    
    int balance- getBalance(root);

    if(balance >1 && value<root->left->data)
        return rightRotate(root);
    if(balance <-1 && value>root->right->data)
        return leftRotate(root);
    if(balance >1 && value >root->left->data)
        {
            root->left=leftRotate(root->left);
            return rightRotate(root);
        }
    if(balance <-1 && value <root->right->data)
        {
           root->right= rightRotate(root->right);
            return leftRotate(root);
        }

    return root;
}


Node *delete(Node *root,int delval)
{
    if(root==NULL)
        return root;
    if(delval<root->data)
        root->left=delete(root->left,delval);
    else if(delval>root->data)
        root->right=delete(root->right,delval);
    
    else
    {
        if(root->left==NULL && root->right ==NULL)
            {
                free(root);
                return root;
            }
       else if(root->left==NULL)
            {
                Node *tmp=root->right;
                free(root);
                return tmp;
            }
        else if(root->right==NULL)
            {
                Node *tmp=root->left;
                free(root);
                return tmp;
            }
        else
        {
            Node *tmp=minNode(root->right);
                root->data=tmp->data;
                tmp->right=delete(root->right,tmp->data);
        }
    }
    
    if(root==NULL)
        return root;

    root->height=1+ max(height(root->left),height(root->right));

    int balance=getBalance(root);

    if(balance>1 && getBalance(root->left)>=0)
        return rightRotate(root);
    if(balance >1 && getBalance(root->left)<0)
    {
        root->left=leftRotate(root->left);
        return  rightRotate(root);
    }
    if(balance<-1 && getBalance(root->right)<=0)
        return leftRotate(root);
    if(balance <-1 && getBalance(root->right)>0)
        {
            root->right=rightRotate(root->right);
            return leftRotate(root);
        }
    return root;



}
