#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void CountingSort(int *A, int *B, int n,int index,int width)// n means the length of A, k means the 2^width-1
{
	int k = (1 << width);
	int *C = (int *)malloc(sizeof(int)*k);
	int *D = (int *)malloc(sizeof(int)*n);
	int i = 0;
	for (i = 0; i < k; i++)
	{
		C[i] = 0;
	}
	for (i = 0; i < n; i++)
	{
		D[i] =A[i] >> (index * width);
		D[i] &= 0xFFFF >> (16 - width);
	}
	for (i = 0; i < n; i++)
	{
		C[D[i]] += 1;
	}
	for (i = 1; i < k; i++)
	{
		C[i] = C[i] + C[i - 1];
	}
	for (i = n - 1; i >= 0; i--)
	{
		B[C[D[i]]-1] = A[i];
		C[D[i]] --;
	}
	free(C);
	free(D);
}

int * RadixSort(int *A, int n, int max_width, int width)
{
	int i = 0;
	int *B=NULL;
	int *result = (int *)malloc(sizeof(int)*n);
	for (i = 0; i < max_width / width + 1; i++)
	{
		if (i % 2 == 0)
		{
			CountingSort(A, result, n, i, width);
			B = result;
		}
		else
		{
			CountingSort(result, A, n, i, width);
			B = A;
		}
	}
	return B;

}
int main()
{
	int n,i;
	scanf("%d", &n);
	int *A = (int *)malloc(sizeof(int)*n);
	int *B;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	B=RadixSort(A, n, 30, 4);
	for (i = 0; i < n; i++)
	{
		printf("%d ", B[i]);
	}
	if(B==A)
	free(A);
	else
	{
		free(A);
		free(B);
	}
	
	system("pause");
	
}