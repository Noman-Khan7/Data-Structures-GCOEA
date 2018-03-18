/*Practical No-3
3.	Design and implement Binary search algorithm which works as search and insertion algorithm and display the total no of comparison required 
for searching a element is available or not(Read an unsorted array ,sort it using any sorting technique and display pass wise array and the no of comparisons)*/
#include<stdio.h>
#include<conio.h>
int main()
{
	int aa[100];
	int i,j,N,m,J;
	int ub,lb,mid,item,loc,beg,end;
	int temp,c=1;
	printf("Enter the no. of elements :");
	scanf("%d",&N);
	printf("enter array elements:\n");
	for(i=0;i<N;i++)
	{
		scanf("%d",&aa[i]);
	}
	//Bubble Sort...
	printf("The pass wise array are \n");
	for(i=0;i<N-1;i++)
	{

		for(j=0;j<(N-i-1);j++)
		{
			if(aa[j]>aa[j+1])
			{
				temp=aa[j];
				aa[j]=aa[j+1];
				aa[j+1]=temp;
				
			}
		}
		
			for(m=0;m<N;m++)
			{
				printf("%d ",aa[m]);
			}
			printf("\n");
	}
	printf("sorted array is : \n");
	for(i=0;i<N;i++)
	{
		printf("%d ",aa[i]);
	}
	printf("\n\nEnter an item to search in sorted array :\n");
	scanf("%d",&item);
	//Binary Search Algorithm...
	lb=0;
	ub=N-1;
	beg=lb;
	end=ub;
	mid=(beg+end)/2;
	while(beg<=end&&aa[mid]!=item)
{
	c++;
	if(item<aa[mid])
	{
		end=mid-1;
	}
	else
	{
		beg=mid+1;
	}
	mid=(beg+end)/2;
}	

if(aa[mid]>item)
{
	loc=mid;
}
else
{
	loc=mid+1;
}
if(item==aa[mid])
{
	printf("the index of item is %d \n",loc);
}
else
{
J=N;
while(J>=loc)
{
	aa[J+1]=aa[J];
	J--;
}
aa[loc]=item;
N=N+1;
}
printf("final Array after instersion is ");

for(i=0;i<N;i++)
	{
		printf("%d ",aa[i]);
	}
printf("\nThe no of comparision is %d",c);
return 0;
}
