#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//if we use divide-and-conquer
/*
1.divide.split the array to two subarrays, simplely we can just split it to n/2 and n/2
2.conquer. i<j a[i]>a[j] NUM(N)=NUM(First(N/2))+NUM(Second(N/2))+NUM(passing by mid)
3.merge.NUM(passing by mid)=NUM({(i,j),p<=i<mid,mid<j<=r})
		if the left subarray and right subarray are all in ascending order
		then if a[i]>a[j], then the number is at least mid-i+1 cause a[i]<a[i+1]<...<a[mid]
		so we can let i increase until a[i]>a[j] than let j++ which means switch to another j
		and we should sort the array at the same time we count
*/
int Count_and_Sort(int *A,int *temp,int low, int mid, int high);
int Count(int *A, int *temp,int low, int high)
{
	int count = 0,mid=0;
	if (low < high)
	{
		mid = (low + high) / 2;
		count = Count(A,temp,low, mid);
		count += Count(A,temp, mid + 1, high);
		count += Count_and_Sort(A,temp, low, mid, high);
		count = count % 10000019;
	}
	return count;
}

int Count_and_Sort(int *A, int *temp, int low, int mid, int high)
{
	int i = 0, j = 0, k = 0;
	int count = 0;
	for (i = low, j = mid + 1,k = low; i <= mid && j <= high;)
	{
		if (A[i] <= A[j])
		{
			temp[k++] = A[i++];
		}
		else
		{
			temp[k++] = A[j++];
			count += mid - i + 1;
			count %= 10000019;
		}
	}
	while (i <= mid)
	{
		temp[k++] = A[i++];
	}
	while (j <= high)
	{
		temp[k++] = A[j++];
	}
	for (i = low; i <= high; i++)
	{
		A[i] = temp[i];
	}
	return count;
	
}
int main()
{
	int n,i;
	scanf("%d", &n);
	int *A = (int *)malloc(sizeof(int)*n);
	int *temp = (int *)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	printf("%d",Count(A, temp, 0, n - 1));
	free(A);
	free(temp);
	system("pause");
	return 0;

}
