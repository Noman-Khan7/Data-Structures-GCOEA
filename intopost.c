#include<stdio.h>
#include<string.h>
//void Dispaly(char,int,char*);
int main()
{
	char Q[200],P[200];
	char Stack[100];
	int STCK[100];
	char *ret;
	char A,a,B,b;
	char x[3],y[4];
	int X,Y; 
	char op[]="+-*/^";
	int ptr=-1,i,j,TOP=-1;
	static int temp=1;
	printf("Please enter an infix expression (Balanced parentised)\n");
	gets(Q);
	Stack[TOP]='(';
	TOP=TOP+1;
	strcat(Q,")");
	//we have got the exp.
	i=0;
	while(Q[i]!='\0')
	{
		//printf("Exicuting While loop\n");
		//check if the operand is encountered...
		if((Q[i]<=57)&&(Q[i]>48))
		{	
			//then add it to P...
			ptr=ptr+1;
			P[ptr]=Q[i];
		
		
	if((Q[i+1]<=57)&&(Q[i+1]>48))
			{
				ptr=ptr+1;
				P[ptr]=Q[i+1];
				i++;
		
			}	
			
			ptr=ptr+1;
			P[ptr]=' ';
		}
		//check if the ( is encountered...
		else if(Q[i]=='(')
		{
			//push it onto the stack...
		
			TOP=TOP+1;
			Stack[TOP]=Q[i];
		}	
		//check if the operator is encountered
		else if(strchr(op,Q[i])!=NULL)
		{
		
			ret=strchr(op,Q[i]);
			//check the precedence...
			while(*(ret+temp)!='\0')
			{
				if(Stack[TOP]==*(ret+temp))
				{
				ptr=ptr+1;
				P[ptr]=Stack[TOP];
				ptr=ptr+1;
			P[ptr]=' ';
				TOP=TOP-1;		
				}
				temp++;
			}
		temp=0;
			//push the operator onto the stack...
			TOP=TOP+1;
			Stack[TOP]=Q[i];
		}
		//check if the ) is encountered...
		else if(Q[i]==')')
		{
		
			while(Stack[TOP]!='(')
			{
				ptr=ptr+1;
				P[ptr]=Stack[TOP];
				ptr=ptr+1;
			P[ptr]=' ';
				TOP=TOP-1;
			}
		
			TOP = TOP-1;
			if (Stack[TOP]=='(')
			{
				TOP=TOP-1;
			}
		}	
		i++;

	}
	printf("\n P : ");
	puts(P);
	strcat(P,")");
	
	///Evaluation of infix expression.....
	//now P contains the infix expression...
	//start traversing the string P
	i=0;
	TOP=-1;
	while(P[i]!=')')
	{
	//check if the operand is encountered...
		if((P[i]<=57)&&(P[i]>48))
		{	
			//then add it to STCK...
			TOP=TOP+1;
			STCK[TOP]=(P[i]-'0');
		
		
	if((P[i+1]<=57)&&(P[i+1]>48))
			{
			STCK[TOP]=(STCK[TOP]*10)+(P[i+1]-'0');
			i++;
		
			}	
		}
	//check if the operator is encountered
		else if(strchr(op,P[i])!=NULL)
		{
			//Pop the top 2 elements from the stack;
			X=STCK[TOP];
			TOP=TOP-1;
			Y=STCK[TOP];
			TOP=TOP-1;
			temp=0;
			if(P[i]=='+')
			{
				TOP=TOP+1;
				STCK[TOP]=Y+X;
			}
			else if(P[i]=='-')
			{
				TOP=TOP+1;
				STCK[TOP]=Y-X;
			}
			else if(P[i]=='*')
			{
				TOP=TOP+1;
				STCK[TOP]=X*Y;
			}
			else if(P[i]=='/')
			{
				TOP=TOP+1;
				STCK[TOP]=Y/X;
			}
			else if(P[i]=='^')
			{
				TOP=TOP+1;
				while(temp!=X)
				{
					STCK[TOP]*=Y;
				}
				
			}
		}
		i++;
}
printf("The answer is : %d",STCK[TOP]);
	return 0;
}
