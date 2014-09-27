#include <stdio.h>
#include <stdlib.h>
#define MAX 20

void push(char);
int pop();
int top=-1;
char stk[100];

int main()
{
    char postfix[MAX],ch;
    int a,b,i,r=0;

    printf("\n\tEnter the postfix expression:");
    scanf("%s",&postfix);

    for(i=0;i<strlen(postfix);i++)
    {
        ch=postfix[i];

        if(isalnum(ch))
            push(ch-'0');

        else
        {
            a=pop();
            b=pop();
            switch(ch)
            {
                case '+':   r=b+a;  break;
                case '-':    r=b-a; break;
                case '*':   r=b*a;  break;
                case '/':    r=b/a;  break;
                default:    printf("Invalid operator!");
            }
            push(r);
        }
    }

    printf("\n\tThe result of evaluation of postfix is %d\n",r);

    return 0;
}
void push(char ch)
{
    stk[++top]=ch;
}
int pop()
{
    return stk[top--];
}

