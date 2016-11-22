#include <stdio.h>
#include <stdlib.h>
// 부분집합의 합이 S인 경우가 존재하면 1
// 존재하지 않으면 0을 출력하시오... 

/*
3
10 7
10 56
100 5050
*/

int A[100];
int L[100]; // 1, 0으로 부분집합 표시.. 
int N, S;
int cnt;
int cnt2; 

int subset3(int n, int k, int ssum,int tsum);
int main(int argc, char *argv[]) {

	int tc, T;
	int i;
	int r;
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
		cnt2 = 0;
		for(i=0;i<N;i++)
		{
			L[i] = 0;
		}
		r = subset3(0, N, 0, (1+N)*N/2);
		printf("#%d %d\n", tc, r);	
	}
	return 0;
}

int subset3(int n, int k, int ssum, int tsum)
{
	int i;
	 
	if(n==k)
	{
		cnt2++; // 부분집합의 완성 횟수 기록.. 
		
		if(ssum==S)
			return 1;
		
	}
	else if(ssum ==S)
		return 1;
	else if(ssum > S)
	{
		return 0;
	}
	else if((ssum+tsum)<S)
	{
		return 0;
	}
	else
	{
		for(i=0; i<=1; i++)
		{
			if(subset3(n+1, k, ssum + A[n]*i, tsum-A[n])==1)
				return 1;
		}
		return 0;
		/*
		L[n] = 0;
		subset3(n+1, k, ssum, tsum-A[n]);
		L[n] = 1;
		subset3(n+1, k, ssum+A[n], tsum-A[n]);
		*/
	}
}
