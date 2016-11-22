#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int A[] = {1,3,5};
int P[3];
void f(int n, int k);

int main(int argc, char *argv[]) {
	
	
	f(0, 3);
	
	return 0;
}

void f(int n, int k)
{
	int i;
	if(n==k)
	{
		for(i=0;i<k;i++)
			printf("%d", P[i]);
		printf("\n");
	}
	else
	{
		for(i=0;i<3;i++)
		{
			P[n] = A[i];
			f(n+1, k);
		}
	}
	
}












