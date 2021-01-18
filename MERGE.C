#include<stdio.h>
#include<conio.h>
void input(int [],int);
void merge(int [],int,int [],int,int[]);
void main()
{
int a[100],b[100],c[100];
int i,j,k,m,n;
clrscr();
printf("\nEnter no of elements in 1st array :");
scanf("%d",&m);
input(a,m);
printf("\nEnter no of elements in 2nd array :");
scanf("%d", &n);
input(b,n);
merge(a,m,b,n,c);
getch();
}
void input(int a[],int d)
{
int i;
for(i=0;i<d;i++)
{
scanf("%d",&a[i]);
}
}
void merge(int a[],int m,int b[],int n,int c[])
{
int i=0,j=0,k=0;
while(i<m && j<n)
{
if(a[i]<b[j])
{
c[k]=a[i];
i++;
}
else if(b[j]<a[i])
{
c[k]=b[j];
j++;
}
else
{
c[k]=a[i];
i++;
j++;
}
k++;
}
while(i<m)
{
c[k]=a[i];
i++;
k++;
}
while(j<n)
{
c[k]=b[j];
k++;
j++;
}
printf("\nMerged array is :");
for(i=0;i<k;i++)
printf("%d ",c[i]);
}