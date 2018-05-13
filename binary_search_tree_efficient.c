#include<stdio.h>
#include<stdlib.h>
void insert(int data);
void inorder();
struct node
{
	int data;
	struct node *leftchild;
	struct node *rightchild;
	
};
struct node *root;
int  main()

{
	int A[100],N,i;
	
	printf("Please enter the number of element you want to enter :");
	scanf("%d",&N);
	printf("Now please enter the %d entries of the BINARY Search Tree\n",N);
	for(i=0;i<N;i++)
	{
		scanf("%d",&A[i]);insert(A[i]);
	}
	inorder();
	return 0;
	
}
void insert(int data)
{
	struct node *tempnode=(struct node *)malloc(sizeof(struct node));
	struct node *parent;
	struct node *current;
	
	tempnode->data=data;
	tempnode->leftchild=NULL;
	tempnode->rightchild=NULL;
	if(root==NULL)
	{
	root=tempnode;
	return;	
	}
	else
	{
		current=root;
		parent=NULL;
		
		while(1)
		{
			parent=current;
			if(data<parent->data)
			{
				//traverse to the left subtree
				current=current->leftchild;
				
				if(current==NULL)
				{
					parent->leftchild=tempnode;
					return;
				}
			}
			else
			{
				//traverse to the right sbtree
				current=current->rightchild;
				
				if(current==NULL)
				{
					parent->rightchild=tempnode;
					return;
				}
			}
		}
	}
}
void inorder()
{
	struct node *tempnode;
	struct node *stack[100];
	int top;
	stack[0]=NULL;
	top=0;
	tempnode=root;
X:	while(tempnode!=NULL)
	{
		top=top+1;
		stack[top]=tempnode;
		tempnode=tempnode->leftchild;
	}
	tempnode=stack[top];
	top=top-1;
	while(tempnode!=NULL)
	{
		printf("%d ,",tempnode->data);
		if(tempnode->rightchild!=NULL)
		{
			tempnode=tempnode->rightchild;
			goto X;
		}
		tempnode=stack[top];
		top=top-1;
		
	}
}
