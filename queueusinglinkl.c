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
}
Node insert(Node head,int item,int *c)
{
    if(*c>=max)
    {
       printf("Queue Overflow\n");
      return head;
    }
    else
    {
      *c=*c+1;
      Node p,q;
      q=getnode();
      q->data=item;
      p=head;
      if(p==NULL)
      return q;
      else
      {
        while(p->next!=NULL)
       {
         p=p->next;
       }
      p->next=q;
      q->next=NULL;
      return head;
     }
    }
}
Node delete(Node head)
{
    Node p=head;
    if(head==NULL)
    {
      printf("Queue Underflow \n");
      return head;
     }
    printf("Deleted element is = %d \n",p->data);
    head=head->next;
    free(p);
    return head;
}
void display(Node head)
{
    Node p=head;
    if(p==NULL)
    {
      printf("Queue is empty\n");
      return;
    }
      while(p!=NULL)
      {
        printf("%d\n",p->data);
        p=p->next;
      }
}
void main()
{
  Node head=NULL;
   int n,ch;
  int x;
  int c=0;
  do
  {
    printf("Enter 1 to insert\nEnter 2 to delete\nEnter 3 to show\n");
    scanf("%d",&n);
    if(n==1)
    {
      printf("Enter element\n");
      scanf("%d",&x);
      c++;
      head=insert(head,x,&c);
    }
    else if(ch==2)
    {
      head=delete(head);
    }
    else
    display(head);
    printf("Enter 1 to continue or 0 to exit\n");
    scanf("%d",&ch);
  }while(ch!=0);
}
