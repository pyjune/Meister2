#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// 배열의 내용 000, 001, 010, ..., 111 
int arrA[10]; 

void f(int n, int k);

int main(int argc, char *argv[]) {
	
	
	f( 0, 3);
	
	
	return 0;
}

void f(int n, int k)
{
	int i;
	if(n==k)
	{
		for(i=0;i<k;i++)
		{
			printf("%d", arrA[i]);
		}
		printf("\n");
	} 
	else
	{
		arrA[n] = 0;
		f(n+1, k);
		arrA[n] = 1;
		f(n+1, k);
		/*
		for(i = 0; i<2;i++)
		{
			arrA[n] = i;
			f(n+1, k);
		}
		*/
	}
}









