#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void ShellPass(long * A,int n, int d)
{
	int i = 0,j=0,k=0;
	long key;
	for (i = d; i < n; i++)
	{
		if (A[i-d] > A[i])
		{
			key = A[i];
			j = i-d;
			while (key < A[j]&& j >=0)
			{
				A[j+d] = A[j];
				j -= d;
			}
			A[j + d] = key;
		}
	}

}

void ShellSort(long *A,int A_n, int* D,int D_n)
{
	int i = 0;
	for (i = 0; i < D_n; i++)
	{
		ShellPass(A, A_n, D[i]);
	}
}
int main()
{
	int n,i,count=0;
	long *A;
    int *D;
	scanf("%d", &n);
	A = (long *)malloc(n*sizeof(long));
	for (i = 0; i < n; i++)
	{
		scanf("%ld", &A[i]);
	}
	count = (int)(log(n) / log(2));
	D = (int *)malloc(count * sizeof(int));
	for (i = 0; i < count; i++)
	{
		D[count-1-i] = (int)(pow(2, i));
	}
	ShellSort(A, n, D, count);
	for (i = 0; i < n; i++)
	{
		if(i != n-1)
			printf("%ld ", A[i]);
		else
			printf("%ld", A[i]);
	}
	free(A);
	free(D);
	return 0;

}
