#include<stdio.h>
int fib(int n);
void main()
{
  int m,value;
  printf("enter the nth fibonacci number you want\n");
  scanf("%d",&m);
  value=fib(m);
  printf("the nth fibonacci number is %d",value); 
}
int fib(int n)
{
  if(n==1)
  return 0;
  else if(n==2)
  return 1;
  else
  return (fib(n-1)+fib(n-2));
}
