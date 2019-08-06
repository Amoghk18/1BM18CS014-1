#include<stdio.h>
void main()
{
struct student
{
int s1,s2,s3,s4,s5;
};
struct student a1;
printf("enter the marks of the studemts in the subjects");
scanf("%d%d%d%d%d",&a1.s1,&a1.s2,&a1.s3,&a1.s4,&a1.s5);
printf("the marks of the studtents");
printf("%d\n%d\n%d\n%d\n%d",a1.s1,a1.s2,a1.s3,a1.s4,a1.s5);
}