#include<stdio.h>
#include<ctype.h>
int pre(char ch);
void push(char arr[100],int *top,char c);
char pop(char arr[100],int *top);
void display(char arr[100],int *top);
void main()
{
  char a[100],b[100],x;
  int i,j,k,n,top=-1;
  printf("enter the expression");
  scanf("%s",&b);
  b[strlen(b)]='\0';
  for(i=0;b[i]!='\0';i++)
  {
     if(isalpha(b[i]))
     printf("%c",b[i]);
     else if(b[i]=='(')
       push(a,&top,b[i]);
       else if(b[i]==')')
       {
        k=top;
        if(a[k]!='(' && top>-1)
        {
          x=pop(a,&top);
          printf("%c",x);
        }
        else
            break;
       }
     else if(pre(b[i])>pre(a[top]) || top==-1 || b[top]=='(')
       push(a,&top,b[i]);
       else if(pre(b[i])<pre(a[top]))
       {
         for(j=0;pre(a[top])>=pre(b[i]);j++)
         {
           x=pop(a,&top);
           printf("%c",x);
         }
         push(a,&top,b[i]);
       }
       else
       continue;
  }
  display(a,&top);
}
int pre(char ch)
{
  if(ch=='/' || ch=='*')
  return 2;
  else if(ch=='+' || ch=='-')
  return 1;
  else
  return 0;
}
void push(char arr[100],int *top,char c)
{
 if(*top==99)
 {
   printf("stack overflow");
   return;
 }
 *top=*top+1;
  arr[*top]=c;
}
char pop(char arr[100],int *top)
{
    char e;
  if(*top==-1)
  {
    printf("stack underflow");
    return '@';
  }
  e=arr[*top];
  *top=*top-1;
  return e;
}
void display(char arr[100],int *top)
{
  int i;
  if(*top==-1)
  {
    printf("stack is empty");
    return;
  }
else
{
  for(i=*top;i>-1;i--)
  {
    if(arr[i]!='(' && arr[i]!=')')
    printf("%c",arr[i]);
  }
}
}
