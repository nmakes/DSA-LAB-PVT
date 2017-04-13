#include <stdio.h>
#include "bucketsort.h"
int t=0,i1,i2,lo1,hi1;
void readdata(int points[][2],int M,int xlo,int xhi,int ylo, int yhi,FILE* fptr)
{
	int i=0;
	if((xhi-xlo)>=(yhi-ylo))
	{	
		i1=0; 
		lo1=xlo; 
		hi1=xhi;
		i2=1;
		t=(xhi-xlo)+1;
	}
	else
		{	i1=0;lo1=xlo;hi1=yhi;
			i2=1;
		t=(yhi-ylo)+1;
	}
	for(;i<M;i++)
	{
		fscanf(fptr,"%d",&points[i][0]);
		fscanf(fptr,"%d",&points[i][1]);
	}
	
}

void SortSparseLists(int points[][2],int M)
{   
int i=0,j; Bucket B[t];
	for(i=0;i<=t;i++)
	{
		B[i]=(Bucket)malloc(sizeof(struct linkedList));
	}
	
	for(;i<M;i++)
		{
		j=(points[i][i1]-lo1);
		insert(B[j],points[i][i1],points[i][i2]);
		}
		getpoint(B,points);
		for(i=0;i<M;i++)
		{
			
			printf("%d %d\n",points[i][i1],points[i][i2]);
		}
	
}
void getpoint(Bucket b[],int pt[][2])
{	point p=(point)malloc(sizeof(struct node));
	int j=0,i;

	for(i=0;i<t;i++)
	{
	if(b[i]->first!=NULL)
		{
			p=b[i]->first;
		while(b[i]->first!=NULL)
		{
			pt[j][i1]=(b[i]->first)->x;
			pt[j][i2]=(b[i]->first)->y;
			p=p->next;
			b[i]->first=p;
			j++;
		}

	}
}
}

void insert(Bucket head,int x,int y)
{

{
struct node *ptr=(struct node*)malloc (sizeof(struct node));
struct node *tem=(struct node*)malloc (sizeof(struct node));
ptr=head->first;
if(ptr!=NULL)
{
while(ptr->next!=NULL && (ptr->next)->y <y)
ptr=ptr->next;

tem->x=x;
tem->y=y;
tem->next=ptr->next;
ptr->next=tem;
}
else
{
tem->x=x;
tem->y=y;
tem->next=head->first;

head->first=tem;

}
}
}
