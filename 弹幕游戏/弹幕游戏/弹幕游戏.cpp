#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int Partition(int * A, int p, int r)
{
	int x, temp;
	int i = p - 1, j = 0;
	x = A[r];
	for (j = p; j < r; j++)
	{
		if (A[j] < x)
		{
			i = i + 1;
			temp = A[j];
			A[j] = A[i];
			A[i] = temp;
		}
	}
	temp = A[r];
	A[r] = A[i + 1];
	A[i + 1] = temp;
	return i + 1;
}

void QuickSort(int * A, int p, int r)
{
	int q = 0;
	if (p < r)
	{
		q = Partition(A, p, r);
		QuickSort(A, p, q - 1);
		QuickSort(A, q + 1, r);
	}
}


int main()
{
	int n,i;
	int max = 0;
	scanf("%d", &n);
	int * A = (int *)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	QuickSort(A, 0, n - 1);
	for (i = 0; i < n-1; i++)
	{
		if (A[i] + max < A[i + 1])
		{
			max = A[i + 1] - A[i];
		}
	}
	printf("%d", max);
	free(A);
	system("pause");
}