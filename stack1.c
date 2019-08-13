#include<stdio.h>
void push(int stack[100], int *max,int a);
int pop(int stack[100], int *max);
void display(int stack[100], int *max);
void main()
{
    int arr[100],top=-1,x,ch,m;
    printf("enter you choice,enter -1 to exit\n1.push\n2.pop\n3.display");
    scanf("%d",&ch);
    while(ch!=-1)
    {
      switch(ch)
      { 
        case 1:
        printf("element you want to push");
        scanf("%d",&x);
        push(arr,&top,x);
        break;
        case 2:
        m=pop(arr,&top);
        if(m!=-9999)
        printf("the popped element is %d",m);
        break;
        case 3:
        display(arr,&top);
        break;
        default:
        printf("the choice is not allowed");
       }
       printf("enter your choice");
       scanf("%d",&ch);
    }
        
}
void push(int stack[100],int *max, int a)
{
    if(*max==99)
    {
      printf("stack overflow\n");
      return;
    }
    stack[++*max]=a;
}
int pop(int stack[100], int *max)
{
    if(*max==-1)
    {
      printf("stack underflow\n");
      return -9999;
    }
    *max=*max-1;
    return stack[*max+1];
}
void display(int stack[100], int *max)
{
    int i;
    if(*max==-1)
    {
      printf("the stack is empty\n");
      return;
    }
    for(i=*max;i>-1;i--)
    printf("%d\n",stack[i]);
}
