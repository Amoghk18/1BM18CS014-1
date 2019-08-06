#include<stdio.h>
#include<conio.h>
int grade(int m)
{
if(m<=100 && m>=90)
return 10;
else if(m>=80 && m<90)
return 9;
else if(m>=70 && m<80)
return 8;
else if(m>=60 && m<70)
return 7;
else if(m>=50 && m<60)
return 6;
else
return 0;
}
void main()
{
int s1,s2,s3,s4,s5,sgpa;
printf("enter the marks of the student");
scanf("%d%d%d%d%d",&s1,&s2,&s3,&s4,&s5);
printf(" grade is %d\n",grade(s1));
printf(" grade is %d\n",grade(s2));
printf(" grade is %d\n",grade(s3));
printf(" grade is %d\n",grade(s4));
printf(" grade is %d\n",grade(s5));
sgpa=(5*grade(s1)+5*grade(s2)+4*grade(s3)+3*grade(s4)+3*grade(s5))/20;
printf("sgpa is %d",sgpa);
getch();
}