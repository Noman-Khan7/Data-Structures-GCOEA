/*Practical 2 :
This practical demonstratre the Pattern Matching Algorithm (by using Finite Automata).*/

#include<stdio.h>
#include<conio.h>
#include<string.h>
int fun1(char m);
int fun2(char n);
int main()
{

char A[3][3]={{'x','w','w'},{'y','w','w'},{'y','z','w'}};
	
	char T[100],S[100];
	S[0]='w';     //this stores the initial state of FA.
	int i,j,counter=0;
	int INDEX=0;
	int N,K=0;
	printf("Enter the string\n");
	scanf("%s",T);
	N=strlen(T);
	printf("\nThe length of string is %d &\nLength of pattern aab is 3 ",N);
	printf("\n\nOccurence of pattern aab is at :\n");
	
	while(K<=N)
	{
		
		i=fun1(S[K]);
		j=fun2(T[K]);

		
		
		S[K+1]=A[i][j];
		K++;
		if(S[K]=='z')
	{
		counter++;
		INDEX=K-3;
		//printf("Index is %d\n",INDEX+1);
	printf(" INDEX : %d\n",INDEX+1);
	}}
printf("and the no. of occurence of pattern aab is %d\n",counter);
	return 0;
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
else if(n=='b')
j=1;
else 
j=2;

return j;
}
	
