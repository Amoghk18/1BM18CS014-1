#include<stdio.h>
int fact(int n);
void main()
{
  int m,factorial;
  printf("Enter the number whose factorial is needed\n");
  scanf("%d",&m);
  factorial=fact(m);
  printf("The factorial is %d",factorial);
}
int fact(int n)
{
  if(n==0)
  return 1;
  return (n*fact(n-1));
}
