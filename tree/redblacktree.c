//implementation of red black tree reference wikipedia.org
#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *left;
    struct node *right;
    char color;
};

typedef struct node Node;

Node *root=NULL;

Node *newNode(int value)
{
    Node *tmp=(Node*)malloc(sizeof(Node));
    tmp->data=value;
    tmp->left=NULL;
    tmp->right=NULL;
    tmp->color='r';
}

Node *parent(Node *n)
{
    return n->parent;
}

Node *gparent(Node *p)
{
    Node *x=parent(p);
    if(x==NULL)
        return NULL;
    return parent(x);
}

Node *sibling(Node *s)
{
    Node *sb=parent(s);
    if(sb==NULL)
        return NULL;
    if(s==sb->left)
        return sb->right;
    else return sb->left;

}

Node *uncle(Node *u)
{
    Node *p=parent(u);
    // if(tmp==NULL)
    //     return NULL;
    // Node *tmp1=parent(tmp);
    // if(tmp1==NULL)
    //     return NULL;
    // if(tmp==tmp1->left)
    //     return tmp->right;
    // else return tmp->left;
    Node *g=gparent(u);
    if(g==NULL)
        return NULL;
    else return sibling(p);
}

// void leftRotate(Node *x)
// {
//     Node *y=x->right;
//     Node *tmp=y->left;

//     y->left=x;
//     x->right=tmp;
// }

void left_rotate(Node *n)
{
    Node *nnew=n->right;
    assert(nnew!=LEAF);
    n->right=nnew->left;
    nnew->left=n;
    nnew->parent = n->parent;
    n->parent = nnew;    

}
void right_rotate(Node *n)
{
    Node *nnew=n->left;
    assert(nnew!=LEAF)
    n->left=nnew->right;
    nnew->right=n;
    nnew->parent=n->parent;
    n->parent=nnew;

}

Node *insert(Node *root,Node *n)
{
    insert_rescue(root,n);
    insert_repair_tree(n);
    root=n;
    while(parent(root)!=NULL)
    root=parent(root);
    return n;
}

void insert_rescue(Node *root,Node n)
{
    if(root!=NULL && n->key<root->key)
    {
        if(root->left!=LEAF)
            insert_rescue(root->left,n);
            return ;
        else root->left=n;
    }
    else if(root!=NULL )
    {
        if(root->right!=LEAF)
            insert_rescue(root->right,n);
            return ;
        else root->right=n;
    }

    n->parent=root;
    n->left=LEAF;
    n->right=LEAF;
    n->color=RED;

}
"""What happens next depends on the color of other nearby nodes. There are several cases of red–black tree insertion to handle:

N is the root node, i.e., first node of red–black tree
N's parent (P) is black
P is red (so it can't be the root of the tree) and N's uncle (U) is red
P is red and U is black """

void insert_repair_tree(Node *n)
{
    if(parent(n)==NULL)
        insert_case1(n);
    else if(parent(n)->color==BLACK)
        insert_case2(n);
    else if(uncle(n)->color==RED)
        insert_case3(n);
    else    
        insert_case4(n);
}
"""
Note that:

Property 1 (every node is either red or black) and Property 3 (all leaves are black) always holds.
Property 2 (the root is black) is checked and corrected with case 1.
Property 4 (red nodes have only black children) is threatened only by adding a red node, repainting a node from black to red, or a rotation.
Property 5 (all paths from any given node to its leaves have the same number of black nodes) is threatened only by adding a black node, repainting a node, or a rotation. 

"""
void insert_case1(Node *n)
{
    if(parent(n)==NULL)
        n->color=BLACK;
}

void insert_case2(Node *n)
{
    return ;
        
}

void insert_case3(Node *n)
{
    parent(n)->color=RED;
    uncle(n)->color=RED;
    Node *g=grandparet(n)->color=BLACK;
    insert_repair_tree(g);
}

void insert_case4(Node *n)
{
    Node *p=parent(n);
    Node *g=grandparent(n);
    if(n==g->left->right)
        left_rotate(p);
        n=n->left;
    else if(n==g->right->left)
        right_rotate(p);
        n=n->right;
    insert_case4step2(n);
    
}
void insert_case4step2(n)
{
    Node *p=parent(n);
    Node *g=grandparent(n);
    if(n==p->left)
        right_rotate(g);
    else 
        left_rotate(g);
        p->color=BLACK;
        g->color=RED;
}

void delete_one_child(Node *n)
{
    Node *child= is_leaf(n->right)?n->left:n->right;
    replace_node(n,child);
    if(n->color==BLACK)
    {
        if(child->color==RED)
            child->color=BLACK;
        else 
            delete_case1(child);
    }
free(n);

}

void delete_case1(n)
{
    if(n->parent!=NULL)
    delete_case2(n);
}

void delete_case2(Node *n)
{
    Node *s=sibling(n);
    if(s->color==RED)
        {
            n->parent->color=BLACK;
            s->color=RED;
            if(n==n->parent->left)
                rotate_left(n->parent);
            else
                rotate_right(n->parent);
        }
        delete_case3(n);
}
void delete_case3(Node *n)
{
    Node * s=sibling(n);
    if((n->parent->color== BLACK)&&(s->color==BLACK) && (s->left->color==BLACK) &&(s->right->color==BLACK)){
        s->color=RED;
    delete_case1(n->parent);}
    else    
        delete_case4(n);

}

void delete_case4(Node *n)
{
    Node *s=sibling(n);
    if((n->parent->color==RED)&& (s->color==BLACK)&&(s->left->color==BLACK)&&(s->right->color==BLACK))
    {
        s->color=RED;
        n->parent->color=BLACK;
    }
    else
        delete_case5(n);
}



void delete_case5(Node *n)
{
    Node *s=sibling(n);
    if(s->color==BLACK)
    {
        if((n==n->parent->left)&& (s->right->color==BLACK)&& (s->left->color==RED))
        {
            s->color=RED;
            s->left->color=BLACK;
            rotate_right(s);
        }
        else if((n==n->parent->right)&&(s->left->color==BLACK)&&(s->right->color==RED))
        {
            s->color=RED;
            s->right->color=BLACK;
            rotate_left(s);
        }
    }
    delete_case6(n);
}


void delete_case6(Node *n)
{
    Node *s=sibling(n);
    s->color=n->parent->color;
    n->parent->color=BLACK;

    if(n==n->parent->left)
    {
        s->right->color=BLACK;
        rotate_left(n->parent);
    }
    else
    {
        s->left->color=BLACK;
        rotate_right(n->parent);
    }
}