#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int Partition(int * A, int p, int r)
{
	int x,temp;
	int i = p - 1, j = 0;
	x = A[r];
	for (j = p; j < r; j++)
	{
		if (A[j]<x)
		{
			i = i + 1;
			temp = A[j];
			A[j] = A[i];
			A[i] = temp;
		}
	}
	temp = A[r];
	A[r] = A[i+1];
	A[i+1] = temp;
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
void ShellPass(int * A,int n, int d)
{
	int i = 0,j=0,k=0;
	int key;
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

void ShellSort(int *A,int A_n, int* D,int D_n)
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
	int *A;
    int *D;
	scanf("%d", &n);
	getchar();
	A = (int *)malloc(n*sizeof(int));
	for (i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
		getchar();
	}
	/*count = (int)(log(n) / log(2));
	D = (int *)malloc(count * sizeof(int));
	for (i = 0; i < count; i++)
	{
		D[count-1-i] = (int)(pow(2, i));
	}*/
	/*ShellSort(A, n, D, count);
	for (i = 0; i < n; i++)
	{
		if(i != n-1)
			printf("%d ", A[i]);
		else
			printf("%d", A[i]);
	}*/
	QuickSort(A, 0, n - 1);
	for (i = 0; i < n; i++)
	{
		if (i != n - 1)
			printf("%d ", A[i]);
		else
			printf("%d", A[i]);
	}
	free(A);
	//free(D);
	system("pause");
	return 0;

}

/*if you want to use a quick sort
directly use it!!!!!

#include<stdio.h>
#include<stdlib.h>

int Partition(int * A, int p, int r)
{
	int x,temp;
	int i = p - 1, j = 0;
	x = A[r];
	for (j = p; j < r; j++)
	{
		if (A[j]<x)
		{
			i = i + 1;
			temp = A[j];
			A[j] = A[i];
			A[i] = temp;
		}
	}
	temp = A[r];
	A[r] = A[i+1];
	A[i+1] = temp;
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
	int n,i,count=0;
	int *A;
	int *D;
	scanf("%d", &n);
	getchar();
	A = (int *)malloc(n*sizeof(int));
	for (i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
		getchar();
	}
	QuickSort(A, 0, n - 1);
	for (i = 0; i < n; i++)
	{
		if (i != n - 1)
			printf("%d ", A[i]);
		else
			printf("%d", A[i]);
	}
	free(A);
	return 0;

}*/