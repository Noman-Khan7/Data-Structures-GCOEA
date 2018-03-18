#include<stdio.h>
#include<conio.h>
int main()
{
	int a[100][100],b[100][3],ct[100][3];
	int m,n,c,i,j,t,var;
	float min;
	int k=1;
	c=0;
	var=1;
	printf("Enter the no of rows ");
	scanf("%d",&m);
	printf("Enter the no of columns ");
	scanf("%d",&n);
	printf("Enter the elements of %d X %d Matrix \n",m,n);
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
printf("The entered matrix is a sparse matrix\n");
for(i=0;i<m;i++)
	{	for(j=0;j<n;j++)
		{
			if(a[i][j]!=0)
			{
			b[k][0]=i+1;
			b[k][1]=j+1;
			b[k][2]=a[i][j];
			k++;
			}
		}
	}
}
else
printf("The entered matrix is not a sparse matrix");

if(c>=min)
{
printf("The sparse matrix Representation is :\n");

for(i=0;i<=(m*n-c);i++)
{
	for(j=0;j<3;j++)
	{
		printf(" %d",b[i][j]);
	}
	printf("\n");
}
}
//logic for transpose
t=m*n-c;
k=1;

	ct[0][0]=m;
	ct[0][1]=n;
	ct[0][2]=m*n-c;
for(i=1;i<=n;i++)
{
	for(j=1;j<=t;j++)
	{
		if(b[j][1]==var)
		{
			ct[k][0]=b[j][1];
			ct[k][1]=b[j][0];
			ct[k][2]=b[j][2];
			k++;
			
		}
		
		 
	}
	var++;
}
if(c>=min)
{
printf("The Transpose of sparse matrix is :\n");

for(i=0;i<=t;i++)
{
	for(j=0;j<3;j++)
	{
		printf(" %d",ct[i][j]);
	}
	printf("\n");
}
}

return 0;
}
