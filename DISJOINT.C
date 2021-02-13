#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
struct set *top;
int data;
struct node *next;
};
struct set
{
struct node *head;
struct node *tail;
};
struct node * list[20];
int n;
void display()
{
int i,j,count=0,f=0;
struct node *p1;
struct set *ptr,*p[20];
for(i=0;i<n;i++)
{
ptr=list[i]->top;
f=0;
for(j=0;j<count;j++)
{
if (p[j]==ptr)
{
f=1;
break;
}
}
if (f==0)
{
printf("{");
p1=ptr->head;
while(p1!=NULL)
{
printf("%d ",p1->data);
p1=p1->next;
}
printf("}\n");
p[count++]=ptr;
}
}
}
struct set * find(int x)
{
int i,f=0;
for(i=0;i<n;i++)
{
if (list[i]->data==x)
{
f=1;
break;
}
}
if (f==1)
return list[i]->top;
else
return NULL;
}
void unionn()
{
struct node *ptr;
struct set *ptrx,*ptry;
int x,y,i;
printf("Enter the elements to join:");
scanf("%d%d",&x,&y);
ptrx=find(x);
ptry=find(y);
if (ptrx!=ptry)
{
ptrx->tail->next=ptry->head;
ptrx->tail=ptry->tail;
ptr=ptry->head;
while(ptr!=NULL)
{
ptr->top=ptrx;
ptr=ptr->next;
}
free(ptry);
}
}
void main()
{
int i,c,x;
struct node *ne;
struct set *p;
clrscr();
printf("Enter limit:");
scanf("%d",&n);
printf("Enter %d elements:\n",n);
for(i=0;i<n;i++)
{
ne=(struct node *)malloc(sizeof(struct node));
scanf("%d",&ne->data);
ne->next=NULL;
list[i]=ne;
p=(struct set*)malloc(sizeof(struct set));
p->head=ne;
p->tail=ne;
ne->top=p;
}
do
{
printf("\n1.Union\n2.Find\n3.Display\n4.Exit\nEnter ur choice:");
scanf("%d",&c);
switch(c)
{
case 1:unionn();
break;
case 2:printf("Enter elemnt to find:");
scanf("%d",&x);
p=find(x);
if (p!=NULL)
printf("\nThe representative of the set is %d\n",p->head->data);
else
printf("\nElement not present\n");
break;
case 3:display();
break;
case 4:exit(0);
break;
default:printf("\nInvalid\n");
break;
}
}while(c!=4);
getch();
}
