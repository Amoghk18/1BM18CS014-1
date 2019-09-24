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
Node delfront(Node head)
{
  Node p=head;
  if(head==NULL)
  {
    printf("list is empty\n");
    return head;
  }
  printf("deleted element is %d\n",p->data);
  head=p->next;
  free(p);
  return head;
}
void delend(Node head)
{
  Node p=head,prev=NULL;
  if(head==NULL)
  {
    printf("Listis empty\n");
    return;
  }
  while(p->next!=NULL)
  {
    prev=p;
    p=p->next;
  }
  printf("Deleted elementis %d\n",p->data);
  free(p);
  prev->next=NULL;
}
Node delvalue(Node head)
{
  int value;
  Node p=head,prev=NULL;
  printf("Enter the value to be deleted\n");
  scanf("%d",&value);
  if(head==NULL)
  {
    printf("List is empty\n");
    return head;
  }
  if(p->data==value)
  {
    printf("Element has been deleted\n");
    head=p->next;
    free(p);
    return head;
  }
  while(p->next!=NULL && p->data!=value) 
  {
    prev=p;
    p=p->next;
  }
  if(p->data==value)
  {
    printf("The element has been deleted\n");
    prev->next=p->next;
    free(p);
    return head;
  }
  else
  {
    printf("The value doesnt exist in the list\n");
    return head;
  }  
}
void main()
{
  Node head=NULL;
  int c,pos,item;
  printf("Enter the operation number to be performed\n1.insert at 1st pos\n2.insert at given pos\n3.insert at last\n4.Delete from front \n5.Delete from end\n6.Delete a specified value\n7.Display\n8.exit----------------------------------------------------------\n");
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
        head=delfront(head);
        break;
      case 5:
         delend(head);
         break;
      case 6:
        head=delvalue(head); 
        break;
      case 7:
        disp(head);
        break;
      case 8:
        exit(0);
    }
    printf("Enter the operation number to be performed\n1.insert at 1st pos\n2.insert at given pos\n3.insert at last\n4.Delete from front \n5.Delete from end\n6.Delete a specified value\n7.Display\n8.exit----------------------------------------------------------\n");
  scanf("%d",&c);
  }
}

















