#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//12
//3
//12 544 1 12 5615 15 12 02 12 3 455 21 3 11 231

void CountMax(int *A, int n, int k)
{
	int i = 0,j=0;
	int max = 0, k_1_max = 0,k_1_max_index=0;
	for (i = 1; i < k; i++)
	{
		if (A[i] > k_1_max)
		{
			k_1_max = A[i];
			k_1_max_index = i;
		}
	}
	max = (A[0] > k_1_max) ? A[0] : k_1_max;
	printf("%d ", max);
	for (i = k; i < n; i++)
	{
		max = (A[i] > k_1_max) ? A[i] : k_1_max;
		if (k_1_max_index == i -k+1)
		{
			k_1_max = 0;
			for (j = i - k+2; j <= i; j++)
			{
				if (A[j] > k_1_max)
				{
					k_1_max = A[j];
					k_1_max_index = j;
				}
			}
		}
		else
		{
			k_1_max = max;
			k_1_max_index = (A[i] > k_1_max) ? i : k_1_max_index;
		}
		printf("%d ", max);
	}

}

int main()
{
	int n, k,i;
	scanf("%d %d", &n, &k);
	int *A = (int *)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}

	CountMax(A, n, k);
	system("pause");


}