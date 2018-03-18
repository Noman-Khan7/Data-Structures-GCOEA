#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	struct node
	{
		char name[25];
		int qty;
		struct node *link;
	};
	struct node *ptr1=NULL,*temp=NULL,*ptr2=NULL;
int i=1,veg,fru,m,n,tempqty;
char tempchar[30];
struct node *startveg=NULL,*startfru=NULL;
			startveg=malloc(sizeof(struct node));
			ptr1=startveg;
			startfru=malloc(sizeof(struct node));
			ptr2=startfru;
while(i!=0)
{
	
printf("===============================================================\n");
printf("               WELCOME TO FRUITS AND VEGETABLE MALL\n");
printf("===============================================================\n");
printf("                !!!!!!!!Enter your choice!!!!!!!    \n");
printf("\t\t1-> To enter data about Vegetables\n");
printf("\t\t2-> To enter data about Fruits\n");
printf("\t\t3-> To enter data about Display the Complete Data\n");
printf("\t\t0-> EXIT\t");
			
scanf("%d",&i);
switch (i)
{
	case 1:
		{
			
		printf("Enter No. Of Items For Vegetable U Want To Enter \t");
		scanf("%d",&veg);
		for(m=0;m<veg;m++)
		{
				scanf("%s",ptr1->name);
				scanf("%d",&ptr1->qty);
				temp=malloc(sizeof(struct node));
				ptr1->link=temp;
				ptr1=temp;	
		}
		break;
		}
	case 2:
		{
		printf("Enter No. Of Items For FRUITS U Want To Enter \t");
		scanf("%d",&fru);
		for(n=0;n<fru;n++)
			{
				scanf("%s",ptr2->name);
				scanf("%d",&ptr2->qty);
				temp=malloc(sizeof(struct node));
				ptr2->link=temp;
				ptr2=temp;
			}
			break;
		}
		case 3:
		{
		printf("===============================================================\n");
		printf("\tVEGETABLES\tQUANTITY\n");
		printf("===============================================================\n");
		
		ptr1=startveg;
		temp=ptr1->link;
		for(m=0;m<veg-1;m++)
		{
			for(n=i;n<veg-1;n++)
			{
				if(ptr1->qty<temp->qty)
				{
					strcpy(tempchar,ptr1->name);
					strcpy(ptr1->name,temp->name);
					strcpy(temp->name,tempchar);
					tempqty=ptr1->qty;
					ptr1->qty=temp->qty;
					temp->qty=tempqty;
					
					
				}
			}
		}
		
		for(m=0;m<veg;m++)
		{
			
				printf("\t%s",ptr1->name);
				printf("\t%d\n",ptr1->qty);
				ptr1=ptr1->link;
						
		}
		ptr2=startfru;
		printf("===============================================================\n");
		printf("\tFRUITS\tQUANTITY\n");
		printf("===============================================================\n");
		for(n=0;n<fru;n++)
		{
			if(ptr2!=NULL)
			{
					printf("\t%s",ptr2->name);
				printf("\t%d\n",ptr2->qty);
				ptr2=ptr2->link;
			}
		}
		break;
		}
		default:
			{
				printf("!!!!!!!!!!STORE CLOSED!!!!!!!!!!");
			}
}
}
free(ptr1);
free(ptr2);
free(startfru);
free(startveg);
return 0;
}
