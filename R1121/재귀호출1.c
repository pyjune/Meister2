#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int arrA[] = { 4, 2, 5, 6};
int arrB[10];

// n : 복사할 인덱스 번호, k: 원소개수 
void arrCopy(int n, int k);
 
int main(int argc, char *argv[]) {
	int size = sizeof(arrA)/sizeof(arrA[0]);
	int i;
	//int size = sizeof(arrA)/sizeof(int);
	arrCopy( 0, size);
	for(i = 0; i<size;i++)
	{
		printf("%d ", arrB[i]);
	} 
	return 0;
}

void arrCopy(int n, int k)
{
	if(n==k)
	{
		return;
	}
	else
	{
		arrB[n] = arrA[n];
		arrCopy(n+1,k);
		return; 
	}
}










