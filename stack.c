#include<stdio.h>
void push(int stack[100], int *max,int a);
int pop(int stack[100], int *max);
void display(int stack[100], int *max);
void main()
{
    int arr[100],top=-1,x;
    push(arr,&top,1);
    push(arr,&top,2);
    push(arr,&top,3);
    display(arr,&top);
    x=pop(arr,&top);
    printf("the popped element is ");
    display(arr,&top);
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
    return stack[*max];
    *max=*max-1;
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
