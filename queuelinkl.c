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
Node insert(Node rear,int item,int *c,Node front)
{
  Node q;
  if(*c>=max)
  {
    printf("Queue overflow\n");
    return rear;
  }
  q=getnode();
  if(front==NULL)
  {
    front=q;
    rear=q;
    q->next==NULL;
    q->data=item;
    return rear;
  }
  q->data=item;
  rear->next=q;
  q->next=NULL;
  rear=q;
  return rear;
}
Node delete(Node front,Node rear)
{
  Node p;
  int x;
  if(rear==NULL || front>rear)
  {
    printf("Queue is empty\n");
    return front;
  }
  p=front;
  x=p->data;
  printf("%d is popped",x);
  front=front->next;
  free(p);
  return front;
}
void display(Node front,Node rear)
{
  Node p;
  if(front>rear || rear==NULL)
  {
    printf("Queue is empty\n");
    return;
  }
  p=front;
  while(p!=rear->next)
  {
    printf("%d\n",p->data);
    p=p->next;
  }
}
void main()
{
  Node front=NULL;
  Node rear=NULL;
  int n,c=0,x;
  printf("Enter 1 to insert\n 2 to delete \n 3 to display \n 4 to exit\n");
  scanf("%d",&n);
  while(1)
  {
    switch(n)
    {
      case 1: 
        printf("enter the element to be pushed");
        scanf("%d",&x);
        rear=insert(rear,x,&c,front);
        break;
      case 2:
        front=delete(front,rear);
        break;
      case 3:
        display(front,rear);
        break;
      case 4:
        exit(0);
        break;
    }
    printf("Enter 1 to insert\n 2 to delete \n 3 to display \n 4 to exit\n");
  scanf("%d",&n);
  }
}
