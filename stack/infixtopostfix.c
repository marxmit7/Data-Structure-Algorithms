/* This program converts infix expression to postfix expression.
* This program assume that there are Five operators: (*, /, +, -,^) 
	in infix expression and operands can be of single-digit only.
* This program will not work for fractional numbers.
* Further this program does not check whether infix expression is 
valid or not in terms of number of operators and operands.*/

/*             -:*:- ALGORITHM TO CONVERT INFIX EXPRESSION TO POSTFIX EXPRESSION -:*:-

>>----->1: begin scanning of infix expression from left to right.
>>----->2: if the scanned character is an operand output it.
>>----->3: if the scanned character is an operator,
            |---->3.1: if the precedence of the scanned operator is greator than the precedence of the 
                        operator in the stack (or the stack is empty) push it.
            |---->3.2: else ,pop the operator from the stack until the precedence of the scanned operator 
                        is less or equal  to the precedence of the operator residing on the top of the 
                        stack ,push the scanned operator to the stack
>>----->4: if the scanned character  is an '(' ,push it to the stack.
>>----->5: if the scanned character is an ')' pop and output from the stack until an '(' is encountered.
>>----->6: repeat steps 2-6 until infix expression is scanned.
>>----->7: pop and output from the  stack until it is not empty.
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define size 100

/*
    declared here as global variable because stack[] is used by more than one functioin
*/
char stack[size];
int top=-1;

//defining push function
void push(char item)
{
    if(top>=size-1)
        printf("stack is overflow\n");
    else
    {
        top=top+1;
        stack[top]=item;
    }
}

//defining the pop function
char pop()
{char ch;
    if(top<0)
        printf("stack is underflow\n");
    else
        {
            ch=stack[top];
            top=top-1;
            return (ch);
        }
}
// defining this below function to check whether the character is operator or operand

int is_operator(char symbol)
{
    if(symbol=='^'||symbol=='*'||symbol=='-'||symbol=='+'||symbol=='/')
        return 1;//this is returning 1 if symbol is operator else 0
    else 
        return 0;
}

//defining function that is used to assign precedence  to the operator
// and also here ^ it denotes the exponent operator
// here we are making an assumption that higher integer value means higher precedence
int precedence(char symbol)
{
    if(symbol=='^')// exponent operator ,highest precedence
        return (3);
    else if(symbol=='*' || symbol=='-')
        return (2);
    else if(symbol=='-'|| symbol=='+')
        return (1);
    else return (0);
}
// now we are defining the function which is the core of this program
void infixToPostfix(char infixExp[],char postfixExp[])
{
    int i=0,j=0;
    char x;
    push('(');// adding '(' the stack initially
    strcat(infixExp,")");//adding ')' to the last of the infix expression
    char item=infixExp[i]; //initializing before loop

    while(item !='\0') /* run loop till end of infix expression */
    {
        if(item=='(')
        {
            push(item);
        }
        else if(isdigit(item) || isalpha(item))
        {
            postfixExp[j]=item; /* add operand symbol to postfix expr */
            j++;
        }
        else if(is_operator(item)==1)/* means symbol is operator */
        {
            x=pop();
            while(is_operator(x)==1&& precedence(x)>=precedence(item))
            {
                postfixExp[j]=x;//so pop all higher percendence and then add to the postfix expression
                j++;
                x=pop();
            }
            push(x);/* because just above while loop will terminate we have
			popped one extra item
            for which condition fails and loop terminates, so that one*/
            push(item);//pushing current operator symbol onto stack

        }
        else if(item==')')// if ')' is found then
        {
            x=pop();
            while(x!='(')//just pop and keep poping until '(' is encountered
            {
                postfixExp[j]=x;
                j++;
                x=pop();
            }
        }
        else
        {
            //if the current symbol is neither operand not '(' nor ')' and not any operator

            printf("\n invalid infix expression \n");
            exit(1);
        }
        i++;
        item=infixExp[i];//go to the next symbol of infix expression
    }//while loop is ending here

    if(top>0)
    {
        printf("invalid infix expression \n");
        getchar();
        exit(1);
    }
    postfixExp[j]='\0';

}

int main()
{
    char infix[size],postfix[size];
    printf("enter the infix expression\n");
    gets(infix);
    infixToPostfix(infix,postfix);
    printf("post expression\n");
    puts(postfix);
return 0;
}
