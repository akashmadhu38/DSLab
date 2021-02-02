#include<stdio.h>
#include<conio.h>
#define n 5
int Q[n],front=-1,rear=-1;
void enqueue();
void dequeue();
void display();
void search();
void main()
{
int c;
clrscr();
do
{
printf("\n1.Enqueue\n2.Display\n3.Dequeue\n4.Search\nOption:");
scanf("%d",&c);
switch(c)
{
case 1:enqueue();
break;
case 2:display();
break;
case 3:dequeue();
break;
case 4:search();
break;
case 5:exit(0);
break;
default:printf("Invalid");
break;
}
}while(c!=5);
getch();
}
void enqueue()
{
int x;
printf("Enter the data to insert:");
scanf("%d",&x);
if(rear==n)
{
printf("Queue overflow");
}
else if(front==-1 && rear==-1)
{
front=rear=0;
Q[rear]=x;
}
else
{
rear=rear+1;
Q[rear]=x;
}
}
void display()
{
int i;
if(rear==-1)
printf("Queue is underflow");
else
{
for(i=front;i<=rear;i++)
printf("%d",Q[i]);
}
}
void search()
{
int s,p=0,i;
printf("Search:");
scanf("%d",&s);
for(i=front;i<=rear;i++)
{
if(Q[i]==s)
{
p=1;
printf("%d found at %d position",Q[i],i);
break;
}
}
if(p==0)
printf("%d not found");
}
void dequeue()
{
if(front==-1 && rear==-1)
printf("Underflow");
else if(front==rear)
front=rear=-1;
else
{
printf("\n%d deleted\n",Q[front]);
front++;
}
}
