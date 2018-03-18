#include<stdio.h>
#include<conio.h>
int main()
{
	int a[100][100],b[100][3];
	int m,n,c,i,j;
	int min;
	int k=1;
	c=0;
	printf("Enter the no of rows");
	scanf("%d",&m);
	printf("Enter the no of columns");
	scanf("%d",&n);
	printf("Enter the elements of %d X %d Matrix\n",m,n);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{	
		scanf("%d",&a[i][j]);
		}
	}
	
	for(i=0;i<m;i++)
	{	for(j=0;j<n;j++)
		{
			if(a[i][j]==0)
			{
			c++;
			}
		}
	}
//c indicates total no. of zero elements
min=m*n*0.75;

if(c>=min)
{
	b[0][0]=m;
	b[0][1]=n;
	b[0][2]=m*n-c;
printf("The given matrix is a sparse matrix\n");
for(i=0;i<m;i++)
	{	for(j=0;j<n;j++)
		{
			if(a[i][j]!=0)
			{
			b[k][0]=i;
			b[k][1]=j;
			b[k][2]=a[i][j];
			k++;
			}
		}
	}
}
for(i=0;i<=(m*n-c);i++)
{
	for(j=0;j<3;j++)
	{
		printf("%d ",b[i][j]);
	}
	printf("\n");
}
return 0;
}