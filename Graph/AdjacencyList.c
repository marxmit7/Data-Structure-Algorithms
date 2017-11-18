//implementation of graph theory adjacency list
#include<stdio.h>
#include<stdlib.h>

#define size 10

struct node
{   
    int data;
    struct node *next;
} ;
typedef struct node Node;


struct vertices
{
    Node * head;
};
typedef struct vertices Vertex;

struct graph
{
    int v;
    Vertex * array;
};
typedef struct graph Graph;


Node *newNode(int key)
{
    Node *tmp=(Node*)malloc(sizeof(Node));
    tmp->data=key;
    tmp->next=NULL;
    return tmp;
}

Graph *createGraph(int v)
{

    Graph *tmp=(Graph*)malloc(sizeof(Graph));
    tmp->v=v;
    tmp->array=(Vertex*)malloc(v*sizeof(Vertex));

    for(int i=0;i<v;++i)
        tmp->array[i].head=NULL; 
        
    return tmp;
}

//adding edge to undirected graph
void addEdge(Graph *graph,int src,int des)
{

    Node *tmp=newNode(des);
    tmp->next=graph->array[src].head;
    graph->array[src].head=tmp;
    //since the graph is undirects
    tmp=newNode(src);
    tmp->next=graph->array[des].head;
    graph->array[des].head=tmp;
}

void printGraph(Graph*gph)
{
    
    for(int j=0;j<gph->v;++j)
    {   
        Node*p=gph->array[j].head;
        printf("Head");
        while(p)
        {
            printf("-->| %d|",p->data);
            p=p->next;
        }
        printf("\n");
    }
}

int main()
{
    int v=9;
    Graph*graph=createGraph(v);
    addEdge(graph, 0, 1);
    addEdge(graph, 3, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 8, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 6, 3);
    addEdge(graph, 1, 6);
    addEdge(graph, 3, 3);
    addEdge(graph, 5, 8);

    printGraph(graph);
    return 0;
}