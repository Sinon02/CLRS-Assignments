#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
/*
18
3
123 456 87 451 5648 4531 548 53156 45461 56456 74 564 78 546 8 564484 654 3
*/
/*version 1*/
/*void SWAP(int *A, int a, int b)
{
	int temp;
	if (A[a] > A[b])
	{
		temp = A[a];
		A[a] = A[b];
		A[b] = temp;
	}
}

int sort5_and_find_median(int *A)
{
	SWAP(A, 0, 1);
	SWAP(A, 3, 4);
	SWAP(A, 2, 4);
	SWAP(A, 2, 3);
	SWAP(A, 0, 3);
	SWAP(A, 0, 2);
	SWAP(A, 1, 4);
	SWAP(A, 1, 3);
	SWAP(A, 1, 2);
	return A[2];
}
int sort_and_find_median(int *A, int n)
{
	if (n == 5)
		return sort5_and_find_median(A);
	int i = 0,j=0,x;
	for (i = 1; i < n; i++)
	{
		x = A[i];
		for (j = i-1; j >= 0 && x < A[j]; j--)
		{
			A[j + 1] = A[j];
		}
		A[j + 1] = x;
	}
	return A[n/2];
}
int Partition(int * A, int p, int r,int x);
int Find_kth(int *A, int p,int r,int k)// A[p,r] find the kth
{
	if (k > 0 && k<= r-p+1)
	{
		int n = r - p + 1;
		int i = 0;
		int median_len = (n % 5 == 0) ? n / 5 : n / 5 + 1;
		int * median_list = (int *)malloc(sizeof(int)*median_len);
		for (i = 0; i < median_len; i++)
		{
			if (i != median_len - 1)
			{
				median_list[i]=sort5_and_find_median(A + i * 5 + p);
			}
			else
			{
				median_list[i] = sort_and_find_median(A + i * 5 + p, n - i * 5);
			}
		}
		int pivot = (median_len == 1) ? median_list[0] : Find_kth(median_list, 0, median_len - 1, median_len / 2);
		int pos = Partition(A, p, r, pivot);
		free(median_list);
		if (pos - p + 1== k)
			return pivot;
		else if (pos - p + 1 > k)
			return Find_kth(A, p, pos - 1, k);
		else
			return Find_kth(A, pos + 1, r, k-(pos-p+1));
	}
	return -1;
}

void swap(int *A, int i, int j)
{
	int temp;
	temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

int Partition(int * A, int p, int r,int x)
{
	int i, j;
	for (i = p; i < r; i++)
	{
		if (A[i] == x)
			break;
	}
	swap(A, i, r);
	i = p;
	for (j = p; j < r; j++)
	{
		if (A[j] <= x)
		{
			swap(A, i, j);
			i = i + 1;
		}
	}
	swap(A, i, r);
	return i;
}*/
/*void swap(int *A, int i, int j)
{
	int temp;
	temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

int Partition(int * A, int p, int r)
{
	int x, i, j;
	i = p;
	x = A[r];
	for (j = p; j < r; j++)
	{
		if (A[j] <= x)
		{
			swap(A, i, j);
			i = i + 1;
		}
	}
	swap(A, i, r);
	return i;
}
int RandomPartition(int * A, int p, int r)
{
	int n = r - p + 1;
	int rdm = rand() % n;
	swap(A, p + rdm, r);
	return Partition(A, p, r);
	
}
int RandomSelect(int *A, int p, int r, int i)
{
	int q, k;
	if (p == r)
		return A[p];
	q = RandomPartition(A, p, r);
	k = q - p + 1;
	if (i == k)
		return A[q];
	else if (i < k)
		return RandomSelect(A, p, q - 1, i);
	else
		return RandomSelect(A, q + 1, r, i - k);
}

int main()
{
	int k, n, i;
	scanf("%d %d", &n, &k);
	getchar();
	int * A = (int *)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &(A[i]));
	}
	int num = RandomSelect(A, 0, n - 1, k);
	printf("%d", num);
	free(A);
	system("pause");
	return 0;
}
*/

void CountingSort(int *A, int *B, int n,int width)// n means the length of A, k means the 2^width-1
{
	int k = width;
	int *C = (int *)malloc(sizeof(int)*k);
	int i = 0;
	for (i = 0; i < k; i++)
	{
		C[i] = 0;
	}
	for (i = 0; i < n; i++)
	{
		C[A[i]] += 1;
	}
	for (i = 1; i < k; i++)
	{
		C[i] = C[i] + C[i - 1];
	}
	for (i = n - 1; i >= 0; i--)
	{
		B[C[A[i]] - 1] = A[i];
		C[A[i]] --;
	}
	free(C);
}

int main()
{
	int n, i, k;
	scanf("%d %d", &n, &k);
	int *A = (int *)malloc(sizeof(int)*n);
	int *B = (int *)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	CountingSort(A, B, n, 10000);
	printf("%d", B[k-1]);
	system("pause");
	free(A);
	free(B);
	return 0;
}
