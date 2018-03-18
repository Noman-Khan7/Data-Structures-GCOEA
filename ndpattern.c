/*Practical 2 :
This practical demonstratre the Pattern Matching Algorithm (by using Finite Automata).*/

//#include<stdio.h>
#include<conio.h>
#include<string.h>
int fun1(char m);
int fun2(char n);
int main()
{

char A[3][2]={{'x','w'},{'y','w'},{'y','z'}};
	
	char T[100],S[100];
	S[0]='w';
	char t1[2],t2[2];
	int i,j;
	int INDEX[25];
	int m=0;
	int N,K=0;
	printf("Enter the string\n");
	scanf("%s",T);
	N=strlen(T);
	printf("The length of string is %d & Length of pattern is 3\n",N);
//	printf(" occurence of pattern aab is :\n");
	
	while(K<=N)
	{
		
		i=fun1(S[K]);
		if(S[K]=='w')
		{printf("F(Q0 ,");		}
		else if(S[K]=='x')
		{printf("F(Q1 ,");		}
		else if(S[K]=='y')
		{printf("F(Q2 ,");		}
		else if(S[K]=='z')
		{printf("F(Q3 ,");		}
		j=fun2(T[K]);
		if(T[K]=='a')
		{printf(" a)=");		}
		else if(T[K]=='b')
		{printf(" b)=");		}
		
		
		S[K+1]=A[i][j];
		K++;
		printf("%c \n",S[K]);
//L	printf("\n");
	
	if(S[K]=='z')
	{
		INDEX[m]=K-3;
		m++;
	//printf("\n INDEX : %d",INDEX+1);
	}

	return 0;
	

}
}
int fun1(char m)
{
int i;
if(m=='w')
i=0;
else if(m=='x')
i=1;
else if(m=='y')
i=2;

return i;
}

int fun2(char n)
{
int j;

if(n=='a')
j=0;
if(n=='b')
j=1;

return j;
}
	
