#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int top=0;
int precd(char);
char pop();
void push(char);
char infix[MAX],pf[MAX],stk[MAX];

int main()
{
    char ch;
    int i=0,j=0;

    printf("\nConversion of infix to postfix expression");
    printf("\nEnter the infix expression to be converted:");
    gets(infix);

    push('#');

    for(i=0;i<strlen(infix);i++)
    {
        ch=infix[i];

        if(isalnum(ch))
                pf[j++]=ch;

        else if(ch=='(')
                push(ch);

        else if(ch==')')
        {
                while(stk[top]!='(')
                      pf[j++]=pop();
                pop();
        }

        else
        {
                while(precd((stk[top]))>=precd(ch))
                        pf[j++]=pop();
                push(ch);
        }
    }

    while(stk[top]!='#')
            pf[j++]=pop();

    pf[j]='\0';

    printf("\nThe postfix expression for %s is %s",infix,pf);

    return 0;
}
int precd(char e)
{
    switch(e)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/':return 2;
        case '#':return 0;
    }
}
void push(char ch)
{
    stk[++top]=ch;
}
char pop()
{
         return stk[top--];
}
