#include <stdio.h>
#include <stdlib.h>

int A[]={1,2,3,4,5,6};
int C[10];
int cnt;

void nck(int n, int k);
void nck2(int n, int k, int m); 

int main(int argc, char *argv[]) {
	
	//nck(3,2);
	nck2(6,3,3);
	printf("cnt : %d\n", cnt);
	return 0;
}
void nck2(int n, int k, int m)
{
	int i;
	if(k==0) // 조합 완성.. 
	{
		cnt++;
		for(i=0; i<m;i++)
			printf("%d ", C[i]);
		printf("\n");
	}
	else if(n<k)
		return;
	else
	{
		C[k-1] = A[n-1];
		nck2(n-1, k-1, m); // n번째 원소를 포함하는 경우.. 
		nck2(n-1, k, m); // n번째 원소를 포함하지 않는 경우.. 
	}
	
}
void nck(int n, int k)
{
	int i;
	if(k==0) // 조합 완성.. 
	{
		for(i=0; i<2;i++)
			printf("%d ", C[i]);
		printf("\n");
	}
	else if(n<k)
		return;
	else
	{
		C[k-1] = A[n-1];
		nck(n-1, k-1); // n번째 원소를 포함하는 경우.. 
		nck(n-1, k); // n번째 원소를 포함하지 않는 경우.. 
	}
	
}
