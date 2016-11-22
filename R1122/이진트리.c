#include <stdio.h>
#include <stdlib.h>
/*
노드개수 간선개수 
5 4
1 2 1 3 3 4 3 5 부모 자식 순.. 
*/
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int ch1[10];
int ch2[10];
int A[10];
int V, E;
void DLR(int n);
void LDR(int n);
void LRD(int n);
void DLR2(int n);
int main(int argc, char *argv[]) {
	int i;
	int n1, n2;
	int root;
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &V, &E);
	for(i = 0 ; i< E; i++)
	{
		scanf("%d %d", &n1, &n2); // n1 부모, n2 자식 
		// 부모를 인덱스로 자식을 저장..
		if(ch1[n1]==0)
			ch1[n1] = n2;
		else
			ch2[n1] = n2;
		// 자식을 인덱스로 부모를 저장..
		A[n2] = n1; 
	}
	// root 찾기..자식-부모 배열에서 부모가 없는 노드.. 
	root = 1;
	while(A[root]!=0)
	{
		root++;
	}
	// root부터 순회..
	DLR(root); 
	//LDR(root); 
	//LRD(root);
	//DLR2(root);
	//DLR(3); // 3번노드부터 아래로 순회... 
	printf("\n");
	return 0;
}
// pre-order, 전위순회.. 
void DLR(int n)
{
	// visit(); // 방문한 노드번호 출력
	printf("%d ", n);
	if(ch1[n]!=0) // 왼쪽 자식(ch1)이 있으면 
		DLR(ch1[n]);  // 왼쪽 자식으로 이동 
	if(ch2[n]!=0)	// 오른쪽 자식이 있으면 
		DLR(ch2[n]);  // 오른쪽 자식으로 이동 
}
void DLR2(int n)
{
	// 유효한 노드인지 검사 
	if(n!=0)
	{
		printf("%d ", n);
		DLR2(ch1[n]);  // 왼쪽 자식으로 이동 
		DLR2(ch2[n]);  // 오른쪽 자식으로 이동 
	}
}
// in-order, 중위순회.. 
void LDR(int n)
{
	
	if(ch1[n]!=0) // 왼쪽 자식(ch1)이 있으면 
		LDR(ch1[n]);  // 왼쪽 자식으로 이동 
	// visit(); // 방문한 노드번호 출력
	printf("%d ", n);
	if(ch2[n]!=0)	// 오른쪽 자식이 있으면 
		LDR(ch2[n]);  // 오른쪽 자식으로 이동 
}

// post-order, 후위순회.. 
void LRD(int n)
{
	
	if(ch1[n]!=0) // 왼쪽 자식(ch1)이 있으면 
		LRD(ch1[n]);  // 왼쪽 자식으로 이동 
	if(ch2[n]!=0)	// 오른쪽 자식이 있으면 
		LRD(ch2[n]);  // 오른쪽 자식으로 이동
	// visit(); // 방문한 노드번호 출력
	printf("%d ", n);
 
}

