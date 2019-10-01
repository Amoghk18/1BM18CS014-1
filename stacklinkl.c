#include<stdio.h>
#include<stdlib.h>
#define max 5
struct node
{
  int data;
  struct node *next;
};
typedef struct node* Node;
Node getnode()
{
  Node p;
  p=(Node)malloc(sizeof(struct node));
  if(p!=NULL)
  return p;
  else
  {
    printf("Memory was not allocated\n");
    exit(0);
  } 
} 
Node push(Node top,int item, int *c)
{
  Node p;
  if(*c>=max)
  {
    printf("Stack overflow\n");
    return top;
  }
  p=getnode();
  p->data=item;
  p->next=top;
  top=p;
  *c=*c+1;
  return top;
}
Node pop(Node top)
{
  if(top==NULL)
  {
    printf("Stack is empty\n");
    return top;
  }
  Node p;
  int x;
  p=top;
  x=p->data;
  top=top->next;
  free(p);
  printf("Poped element is %d",x);
  return top;
}
void display(Node top)
{
  Node p;
  if(top==NULL)
  {
    printf("List is empty\n");
    return;
  }
  p=top;
  while(p!=NULL)
  {
    printf("%d\n",p->data);
    p=p->next;
  } 
}
void main()
{
  Node top=NULL;
  int n,x,c=0;
  printf("Enter 1 to push\n 2 to pop \n 3 to display \n 4 to exit\n");
  scanf("%d",&n);
  while(1)
  {
    switch(n)
    {
      case 1:
        printf("enter the element to be pushed\n");
        scanf("%d",&x);
        top=push(top,x,&c);
        break;
      case 2:
        top=pop(top);
        break;
      case 3:
        display(top);
        break;
      case 4:
        exit(0);
        break;
    }
    printf("Enter 1 to push\n 2 to pop \n 3 to display \n 4 to exit\n");
  scanf("%d",&n);
  } 
}
