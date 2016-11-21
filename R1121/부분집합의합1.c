#include <stdio.h>
#include <stdlib.h>
/* 입력.. 
2
10 7
10 53
*/

int A[100];
int L[100]; // 1, 0으로 부분집합 표시.. 
int N, S;
int cnt;
void subset(int n, int k);
void subset1(int n, int k);

int main(int argc, char *argv[]) {

	int tc, T;
	int i;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	
	for(i=0;i<100;i++)
	{
		A[i] = i+1;
	}
	for(tc = 1; tc<=T;tc++)
	{
		scanf("%d %d", &N, &S);
		cnt = 0;
		for(i=0;i<N;i++)
		{
			L[i] = 0;
		}
		//subset(0, N);
		subset1(0, N);
		printf("#%d %d\n", tc, cnt);	
	}
	return 0;
}
// 모든 부분집합의 합 계산.. 
void subset1(int n, int k)
{
	int i;
	int sum = 0; 
	if(n==k)
	{
		for(i=0;i<k;i++)
		{
			if(L[i]==1)
				sum += A[i];
		}
		if(sum==S)
			cnt++;
		
	}
	else
	{
		L[n] = 0;
		subset1(n+1, k);
		L[n] = 1;
		subset1(n+1, k);
	}
}


void subset(int n, int k)
{
	int i;
	if(n==k)
	{
		for(i=0;i<k;i++)
		{
			if(L[i]==1)
				printf("%d ", A[i]);
		}
		printf("\n");
	}
	else
	{
		L[n] = 0;
		subset(n+1, k);
		L[n] = 1;
		subset(n+1, k);
	}
}







