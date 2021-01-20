#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void insert();
void insbeg();
void display();
void insend();
void inspos();
void delbeg();
void delend();
void delpos();
void search();
int count=0;
struct node
{
int data;
struct node *next;
struct node *prev;
};
struct node *head,*temp,*tail,*newnode;

void main()
{
int c;
clrscr();
do
{
printf("\n\n1.Insert\n2.Display\n3.Insert at begining\n4.Insert at end");
printf("\n5.Insert at position\n6.Delete at begening\n7.Delete at end");
printf("\n8.delete at position\n9.Search\n10.Exit\noption:");
scanf("%d",&c);
switch(c)
{
case 1:insert();
count++;
break;
case 2:display();
break;
case 3:insbeg();
count++;
break;
case 4:insend();
count++;
break;
case 5:inspos();
count++;
break;
case 6:delbeg();
break;
case 7:delend();
break;
case 8:delpos();
break;
case 9:search();
break;
case 10:exit(0);
break;
default:printf("Invalid");
break;
}
}while(c!=10);
getch();
}


void insert()
{
newnode=(struct node*)malloc(sizeof(struct node));
printf("Enter the data:");
scanf("%d",&newnode->data);
newnode->next=NULL;
if(head==NULL)
{
head=tail=newnode;
}
else
{
tail->next=newnode;
newnode->prev=tail;
tail=newnode;
}
return;
}


void insbeg()
{
newnode=(struct node*)malloc(sizeof(struct node));
printf("Enter the data:");
scanf("%d",&newnode->data);
if(head==NULL)
{
head=tail=newnode;
}
else
{
newnode->next=head;
head->prev=newnode;
head=newnode;
}
return;
}


void insend()
{
newnode=(struct node*)malloc(sizeof(struct node));
printf("Enter the data:");
scanf("%d",&newnode->data);
if(head==NULL)
{
head=tail=newnode;
}
else
{
tail->next=newnode;
newnode->prev=tail;
newnode->next=NULL;
tail=newnode;
}
}


void inspos()
{
int p,i=1;
printf("Enter the position:");
scanf("%d",&p);
if(p>count)
printf("Invalid position");
else if(p==1)
insbeg();
else
{
struct node *temp;
temp=head;
newnode=(struct node*)malloc(sizeof(struct node));
printf("Enter the data:");
scanf("%d",&newnode->data);
while(i<p-1)
{
temp=temp->next;
i++;
}
newnode->prev=temp;
newnode->next=temp->next;
temp->next=newnode;
}
}


void display()
{
temp=head;
while(temp!=NULL)
{
printf("->%d",temp->data);
temp=temp->next;
}
return;
}


void delbeg()
{
if(head==NULL)
printf("Empty");
else
{
newnode=head;
head=head->next;
printf("%d is deleted",newnode->data);
newnode=NULL;
free(newnode);
}
}
void delend()
{
if(head==NULL)
printf("Empty");
else
{
newnode=tail;
tail=tail->prev;
printf("%d is deleted",newnode->data);
tail->next=NULL;
free(newnode);
}
}


void delpos()
{
int p,i=1;
struct node *temp;
printf("Enter the position:");
scanf("%d",&p);
if(p>count)
printf("Invalid position");
else if(p==count)
delend();
else
{
temp=head;
while(i<p)
{
temp=temp->next;
i++;
}
temp->prev->next=temp->next;
temp->next->prev=temp->next;
printf("%d is deleted",temp->data);
free(temp);
}
}
void search()
{
int i=1,p;
struct node *temp;
temp=head;
if(head==NULL)
{
printf("Empty");
}
else
{
printf("Enter the data to search:");
scanf("%d",&p);
while(temp!=NULL)
{
if(temp->data==p)
printf("%d found at %dth position",temp->data,i);
temp=temp->next;
i++;
}
}
}
