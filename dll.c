#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
  struct node *prev;
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
Node insfront(Node head,in item,Node n)
{
  Node newn;
  newn=getnode();
  newn->data=item;
  if(n->prev==NULL)
  {
    newn->prev=NULL;
    newn->next=n;
    n->prev=newn;
    head=newn;
    return head;
  }
  n->prev->next=newn;
  newn->prev=n->prev;
  newn->next=n;
  n->prev=newn;
  return head;
}
Node del(Node head,int value)
{
  Node p;
  int x=0;
  if(head==NULL)
  {
    printf("List is empty\n");
    return head;
  }
  if(head->next==NULL)
  {
    if(head->data==value)
    {
      printf("%d is deleted\n",head->data);
      free(head);
      return NULL;
    }
    else
    {
      printf("Value doesnt exist");
      return head;
    }
  }
  p=head;
  while(p!=NULL)
  {
    if(p->data==value)
    {
      if(p->prev!=NULL)
      {
        p->prev->next=p->next;
      }
      else
      head=p->next;
      if(p->next!=NULL)
      {
        p->next->prev=p->prev;
        free(p);
        return head;
      }
      p=p->next;
    }
    if(p==NULL)
    {
      printf("Not found\n");
      retur head;
    }
  }
}
void disp(Node head)
{
  Node p;
  if(head==NULL)
  {
    printf("list is empty\n");
    return;
  }
  p=head;
  while(p!=NULL)
  {
    printf("%d\n",p->data);
    p=p->next;
  }
}


