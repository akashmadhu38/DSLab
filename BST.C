#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void insert();
void postorder();
void deletee();
void search();
struct node
{
int data;
struct node *left,*right;
};
struct node *root,*temp;
void preorder(struct node *root);
void inorder(struct node *root);
void main()
{
int c;
clrscr();
do
{
printf("\n\n1.Insert\n2.Delete\n3.Preorder\n4.Inorder\n5.Postorder\n6.Search\n7.Exit\nOption:");
scanf("%d",&c);
switch(c)
{
case 1:insert();
break;
case 2:deletee();
break;
case 3:preorder(root);
break;
case 4:inorder(root);
break;
case 5:postorder(root);
break;
case 6:search();
break;
case 7:exit(0);
break;
default:printf("Invalid");
break;
}
}while(c!=7);
getch();
}

void insert()
{
 int n;
 struct node *newnode,*temp1,*temp2;
 newnode=(struct node*)malloc(sizeof(struct node));
 printf("Enter the data:");
 scanf("%d",&newnode->data);

 newnode->left=newnode->right=NULL;
 temp1=root;

 if(root==NULL)
 {
  root=temp1=newnode;
 }
 else
 {
  temp1=root;

  while(temp1!=NULL && temp1!=NULL)
  {
   printf("*");
   if(newnode->data==temp1->data)
   {
    printf("Element already exits");
    return;
   }
   else if(newnode->data>temp1->data)
   {
    printf("==>%d",temp1->data);
    printf("--R");
    temp2=temp1;
    temp1=temp1->right;
   }
   else
   {
   printf("---L");
   temp2=temp1;
    temp1=temp1->left;
   }
  }
  if(temp2->data<newnode->data)
  {
  temp2->right=newnode;
  }
  else
  {
  temp2->left=newnode;
  }
 }
}

void preorder(struct node *root)
{
if(root==NULL)
{
return;
}

printf("->%d",root->data);
preorder(root->left);
preorder(root->right);
}
void inorder(struct node *root)
{
if(root!=NULL)
{
inorder(root->left);
printf("->%d",root->data);
inorder(root->right);
}
}
void postorder(struct node *root)
{
if(root!=NULL)
{
postorder(root->left);
postorder(root->right);
printf("->%d",root->data);
}
}
void search()
{
int s,p=0;
struct node *temp;
printf("Enter the data to search:");
scanf("%d",&s);
temp=root;
while(temp!=NULL)
{
p=1;
if(temp->data==s)
{
printf("%d is present",temp->data);
break;
}
else
{
p=0;
}
if(s>temp->data)
temp=temp->right;
else
temp=temp->left;
}
if(p!=1)
printf("Data is not present");
}
void deletee()
{
int n;
struct node *temp;
printf("Enter a data to delete:");
scanf("%d",&n);
temp=root;
while(temp!=NULL)
{
if(temp->data==n)
{
printf("%d data is deleted",temp->data);
temp->data=NULL;
free(temp);
break;
}
if(temp->data<n)
temp=temp->right;
else
temp=temp->left;
}
if(temp==NULL)
printf("Data not present");
}