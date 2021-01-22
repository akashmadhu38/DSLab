#include<stdlib.h>
#include<stdio.h>
int front=-1,rear=-1,CQ[5],max=3;
void insert();
int delet();
void display();
void main()
{
int w,no;
clrscr();
do
{
printf("\n1. Insert");
printf("\n2. Delete");
printf("\n3. Display");
printf("\n4. EXIT");
printf("\nEnter what you want :");
scanf("%d",&w);
switch(w)
{
case 1:insert();
break;
case 2:no=delet();
break;
case 3:display();
break;
case 4:exit(1);
default:printf("\nInvalid Choice\n");
}
}
while(w!=4);
getch();
}
void insert()
{
int no;
if(front == (rear+1) % max)
{
printf("\nQueue is full\n");
return;
}
printf("\nEnter a number to Insert :");
scanf("%d",&no);
if(front==-1)
front=front+1;
if(rear==max-1)
rear=0;
else
rear=rear+1;
CQ[rear]=no;
}
int delet()
{
int e;
if(front==-1)
{
printf("\nQueue is empty\n");
return 0;
}
e=CQ[front];
if(front==rear)
{
front=-1;
rear=-1;
}
else if(front==max-1)
front=0;
else front=front+1;
printf("\n%d is deleted \n",e);
return e;
}
void display()
{
int i;
if(front==-1)
{
printf("\n Queue is empty\n");
return;
}
i=front;
if(front<=rear)
{
printf("\n\n");
while(i<=rear)
printf("%d ",CQ[i++]);
printf("\n");
}
else
{
printf("\n\n");
while(i<=max-1)
printf("%d ",CQ[i++]) ;
i=0;
while(i<=rear)
printf("%d ",CQ[i++]);
printf("\n");
}
}
