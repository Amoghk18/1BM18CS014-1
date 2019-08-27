#include<stdio.h>
#include<string.h>
void push(int ele,int stack[100],int *top);
int pop(int stack[100],int *top);
int operation(int ele1,int ele2,char c);
void main()
{
    char s[100];
    int stack[100],opnd1,opnd2,x,top=-1,value=0;
    printf("enter the expression to be evaluated");
    scanf("%s",s);
    s[strlen(s)]='\0';
    int i=0;
    while(s[i]!='\0')
    {
        if(s[i]>='0' && s[i]<='9')
        {
            x=s[i]-'0';
           push(x,stack,&top);
        }
        else
        {
            opnd2=pop(stack,&top);
            opnd1=pop(stack,&top);
            printf("%d %d",opnd1,opnd2);
            value=operation(opnd1,opnd2,s[i]);
            push(value,stack,&top);
        }
        i++;
    }
    printf("the value of expression is %d",pop(stack,&top));
}
void push(int ele,int stack[100],int *top)
{
    if(*top==99)
    {
        printf("stack overflow");
        return;
    }
    *top=*top+1;
    stack[*top]=ele;
}
int pop(int stack[100],int *top)
{
    if(*top==-1)
    {
        printf("stack underflow");
        return -99;
    }
    return stack[(*top)--];
}
int operation(int ele1,int ele2,char c)
{
    int x;
    switch(c)
    {
    case '+':
        return (ele1+ele2);
        break;
    case '-':
        return (ele1-ele2);
        break;
    case '*':
        return (ele1*ele2);
        break;
    case '/':
        return (ele1/ele2);
        break;
    }
}
