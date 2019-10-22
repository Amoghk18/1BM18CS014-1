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
void sort(Node head)
{
  Node p=head,q=NULL;
  int temp;
  if(head==NULL)
  {
    printf("list is empty\n");
    return;
  }
  while(p->next!=NULL)
  {
    q=p->next;
    while(q!=NULL)
    {
      if(p->data>q->data)
      {
        temp=p->data;
        p->data=q->data;
        q->data=temp;
      }
      q=q->next;
    }
    p=p->next;
  }
}
Node reverse(Node head)
{
  Node prev=NULL,curr=head,nextn=NULL;
  if(head==NULL)
  {
    printf("List is empty\n");
    return head;
  }
  if(head->next==NULL)
  {
    printf("List is empty\n");
    return head;
  }
  while(curr!=NULL)
  {
    nextn=curr->next;
    curr->next=prev;
    prev=curr;
    curr=nextn;
  }
  head=prev;
  return head;
}
Node concat(Node h1)
{
  int y,item;
  Node h2=NULL,p;
  if(h1==NULL)
  {
    printf("list 1 is empty");
    return h1;
  }
  printf("Enter 1 to insert a node\n");
    scanf("%d",&y);
  while(y==1)
  {
    switch(y)
    {
      case 1:
        printf("Enter number");
        scanf("%d",&item);
        h2=insert_front(h2,item);
        break;
      case 2:
        break;
    }
    printf("Enter 1 to insert a node\n");
    scanf("%d",&y);
  }
  if(h2==NULL)
  return h1;
  p=h1;
  while(p->next!=NULL)
  {
    p=p->next;
  }
  p->next=h2;
  return h1;
}
void main()
{
  Node head=NULL;
  int c,item;
  printf("Enter the operation number to be performed\n1.insert\n2.Sort\n3.Reverse\n4.Concatenate\n5.Display\n6.exit\n----------------------------------------------------------\n");
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
        sort(head);
        break;
      case 3:
        head=reverse(head);
        break;
      case 4:
        concat(head);
        break;
      case 5:
        disp(head);
        break;
      case 6:
        exit(0);
    }
  printf("Enter the operation number to be performed\n1.insert\n2.Sort\n3.Reverse\n4.Concatenate\n5.Display\n6.exit\n----------------------------------------------------------\n");
  scanf("%d",&c);
  }
}













