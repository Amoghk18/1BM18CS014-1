#include<stdio.h>
#include<stdlib.h>
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
Node insert_front(Node head,int item)
{
  Node p;
  p=getnode();
  p->data=item;
  p->next=head;
  head=p;
  return head;
}
void insert_back(Node head,int item)
{
  Node p,q;
  q=getnode();
  q->data=item;
  p=head;
  while(p->next!=NULL)
  {
    p=p->next;
  }
  p->next=q;
  q->next=NULL;
}
Node anypos(Node head,int item,int pos)
{
  Node curr,newn,prev=NULL;
  int c=1;
  newn=getnode();
  newn->data=item;
  newn->next=NULL;
  if(head==NULL)
  {
    if(pos==1)
    return newn;
    else
    {
      printf("Invalid insertion\n");
      return head;
    } 
  }
  if(pos==1)
  {
    newn->next=head;
    head=newn;
    return head;
  }
  else
  {
    curr=head;
    while(curr!=NULL && c!=pos)
    {
      prev=curr;
      curr=curr->next;
      c++;
    }
    if(c==pos)
    {
      prev->next=newn;
      newn->next=curr;
      return head;
    }
    else
    {
      printf("Invalid insert position\n");
      return head; 
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
void main()
{
  Node head=NULL;
  int c,pos,item;
  printf("Enter the operation number to be performed\n1.insert at 1st pos\n2.insert at given pos\n3.insert at last\n4.display he list\n5.exit\n----------------------------------------------------------\n");
  scanf("%d",&c);
  while(1)
  {
    switch(c)
    {
      case 1:
         printf("Enter the number to be inserted\n");
  scanf("%d",&item);
        head=insert_front(head,item);
        break;
      case 2:
         printf("Enter the number to be inserted\n");
  scanf("%d",&item);
        printf("Enter the position\n");
        scanf("%d",&pos);
        head=anypos(head,item,pos);
        break;
      case 3:
         printf("Enter the number to be inserted\n");
  scanf("%d",&item);
        insert_back(head,item);
        break;
      case 4:
        disp(head);
        break;
      case 5:
        exit(0);
    }
     printf("Enter the operation number to be performed\n1.insert at 1st pos\n2.insert at given pos\n3.insert at last\n4.display he list\n5.exit\n----------------------------------------------------------");
  scanf("%d",&c);
  }
}















