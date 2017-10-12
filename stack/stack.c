#include<stdio.h>
#include<stdlib.h>
int top=-1;
#define max 10
void push(int stack[])
{   
    if (top==max-1)
    {
        printf("stack is full mr.perfect\n");
    }
    else{
        int x;
        printf("enter the data \n");
        scanf("%d",&x);
        top=top+1;
        stack[top]=x;
    }
}
int pop(int stack[])
{int val;
    if(top==-1)
    {
        printf("stack is underflow my lord\n");
    }
    else 
    {
        val=stack[top];
        top=top-1;
        return val;
    }
}
void display(int stack[])
{   printf("displaying the stack\n");
    if (top==-1)
    {
        printf("stack is empty\n");

    }
    else
    for (int i=top;i>=0;i--)
    {
        printf("%d ",stack[i]);
    }
}

int main()
{   
    int n;
    printf("\n\t\tenter the no of elements in the stack\n");
    scanf("%d",&n);
    int stack[n];
    int choice;
    while(1)
    {
        printf("\n\t\t\t choose from the given menu\n");
        printf("\n\t\t\t 1: to push element into the stack\n");
        printf("\n\t\t\t 2: to pop element from the stack\n");
        printf("\n\t\t\t 3: to display the elements in the stack\n");
        printf("\n\t\t\t 0: to exit the from the application\n")
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push( stack);
                break;
            }
            case 2:
            {int y;
                y=pop(stack);
                printf("%d has been popped\n",y);
                break;

            }
            case 3:
            {
                display(stack);
                break;
            }
            
            case 0:
                {   
                    printf(" thanks for being nice to me :)\n");
                    exit(0);
                }
            default:
            printf("please try again\n");
                
        }
    }

return 0;    
}
