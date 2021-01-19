#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void push();
void pop();
void display();
void search();
struct node
{
int data;
struct node *next;
};
struct node *head;

void main()
{
int c;
clrscr();
do
{
printf("\n\n1.Push\n2.Pop\n3.Display\n4.Search\n5.Exit\nOption:");
scanf("%d",&c);
switch(c)
{
case 1:push();
break;
case 2:pop();
break;
case 3:display();
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
void push()
{
struct node *newnode;
newnode=(struct node*)malloc(sizeof(struct node));
printf("Enter the data:");
scanf("%d",&newnode->data);
if(head==NULL)
{
head=newnode;
}
else
{
newnode->next=head;
head=newnode;
}
}

void pop()
{
struct node *newnode;
if(head==NULL)
{
printf("Stack is empty");
}
else
{
newnode=head;
head=head->next;
printf("%d poped",newnode->data);
free(newnode);
}
}
void display()
{
struct node *temp;
temp=head;
if(temp==NULL)
printf("stack is empty");
else
{
while(temp!=NULL)
{
printf("->%d",temp->data);
temp=temp->next;
}
}
return;
}
void search()
{
struct node *temp;
int s,i=1;
temp=head;
if(head==NULL)
printf("Stack is empty");
else
{
printf("Enter a data to search:");
scanf("%d",&s);
while(temp!=NULL)
{
if(temp->data==s)
printf("%d data found at %d position:",temp->data,i);
temp=temp->next;
i++;

}
}
return;
}