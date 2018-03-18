#include<stdio.h>
#include<conio.h>
int main()
{
	//x is the 2-D array to store the terms of first polynomial...and y for the second...and ans for storing the result
	int a,b;
	int x[10][4],y[10][4],ans[20][4];
	int i,j,m,n,sums,sumf,counter=0;
	int k=0;
	printf("Enter the no of terms in first polynomial\n");
	scanf("%d",&a);
	printf("Enter the following :\n");
	printf("Co-eff\tx-power\ty-power\tz-power\n");
	for(i=0;i<a;i++)
	{
		for(j=0;j<4;j++)
		{
			scanf("%d",&x[i][j]);
		}
	}
	
	printf("Enter the no of terms in second polynomial\n");
	scanf("%d",&b);
	printf("Enter the following :\n");
	printf("Co-eff\tx-power\ty-power\tz-power\n");
	for(i=0;i<b;i++)
	{
		for(j=0;j<4;j++)
		{
			scanf("%d",&y[i][j]);
		}
	}
	
	for(i=0;i<a;i++)
	{
		//calculate the sum of power of terms in first polynomial...
	sumf=x[i][1]+x[i][2]+x[i][3];
	for(j=0;j<b;j++)
		{
			//calculate the sum of terms in second polynomial...
			sums=y[j][1]+y[j][2]+y[j][3];
			if(sumf==sums)//compares the both sums
			{
				if((x[i][1]==y[j][1])&&(x[i][2]==y[j][2])&&(x[i][3]==y[j][3]))
				{
				ans[k][0]=x[i][0]+y[j][0];
				ans[k][1]=x[i][1];
				ans[k][2]=x[i][2];
				ans[k][3]=x[i][2];
				k++;
				counter=1;
				//shifting algo...
					for(m=j;m<(b-1);m++)
					{
					for(n=0;n<4;n++)
						{
						y[m][n]=y[m+1][n];
					
						}
					}b=b-1;
		
				}	
		}	
		
	}
	if(counter!=1)
	{
	for(n=0;n<4;n++)
		{
		ans[k][n]=x[i][n];
		}
		k++;
	}
		
		
	}
	if(b>0)
	{
	for(m=0;m<b;m++)
		{
		for(n=0;n<4;n++)
			{
			ans[k][n]=y[m][n];
			}
			k++;
		}
	}
	printf("\aThe addition is \n");
	printf("Co-eff\tx-power\ty-power\tz-power\n");
	for(i=0;i<k;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d\t",ans[i][j]);
		}
		printf("\n");
	}

	return 0;
}
