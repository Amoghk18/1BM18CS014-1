#define SIZE 10
#include<stdio.h>
#include<stdlib.h>
void insert(int item, int *r,int q[SIZE])
{
    if(*r==SIZE-1)
      {
        printf("queue overflow");
        return;
      }
      *r=*r+1;
      q[*r]=item;
}
int delete(int *f,int *r,int q[SIZE])
{
    int item;
  if(*f>*r)
  {
      printf("queue underflow");
      return -9999;
  }
  item=q[*f];
  *f=*f-1;
  return item;
}
void display(int q[SIZE],int *f,int *r)
{
    int i;
    if(*f>*r)
    {
        printf("queue is empty");
        return;
    }
    for(i=(*f);i<=(*r);i++)
        printf("%d",q[i]);
}
void main()
{
    int f=0,r=-1,choice,ch,q[SIZE],x;
    while(1)
    {
        printf("Enter the operation to be performed on queue:\n1.Insert an element in the queue\n2.Delete an element from the queue\n3.Display the queue\nEnter 4 to exit\n");
    scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the element to be inserted\n");
            scanf("%d",&x);
            insert(x,&r,q);
            break;
        case 2:
            x=delete(&f,&r,q);
            if(x!=-9999)
                printf("%d is the element deleted from the queue\n",x);
            break;
        case 3:
            display(q,&f,&r);
            break;
        case 4:
            exit(1);
        default:
            printf("wrong choice\n");
            break;
        }

    }
}
