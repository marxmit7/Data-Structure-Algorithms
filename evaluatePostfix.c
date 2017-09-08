#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define size 100

int top=-1;
int stack[size];

void push(int item)
{
    if(top>=size-1)
        printf("stack is overflow\n");
    else
    {
        top=top+1;
        stack[top]=item;
    }
}
char pop()
{int ch;
    if(top<0)
        printf("stack is underflow\n");
    else
        {
            ch=stack[top];
            top=top-1;
            
        }
        return (ch);
}

int is_operator(char symbol)
{
    if(symbol=='^'||symbol=='*'||symbol=='-'||symbol=='+'||symbol=='/')
        return 1;//this is returning 1 if symbol is operator else 0
    else 
        return 0;
}
int  evalutePostfix(char postfix[])
{
    char item;
    int i=0;
    item=postfix[i];
    
    int a,b,val;
    strcat(postfix,")");
    
    while(item!=')')
    {
        if(isdigit(item))
        {
            push(item-'0');
        }
        else if(is_operator(item))
        {
            a=pop();
            b=pop();
            switch(item)
            {
                    case '-':
                    val=b-a;
                    break;

                    case '+':
                    val=b+a;
                    break;

                    case '*':
                    val=b*a;
                    break;

                    case '/':
                    val=b/a;
                    break;
                
            }
            push(val);
        }
        i++;
        item=postfix[i];
    }
    printf("evalutated value of the postfix is %d",pop());
}

int main()
{
    char postfix[30];
    gets(postfix);
    
    evalutePostfix(postfix);

return 0;
}
