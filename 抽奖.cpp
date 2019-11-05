#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int RandomPartition(int * A, int p,int r)
{
	int x,i,j,temp;
	i = p;
	x = A[r];
	for(j=0;j<r;i++)
	{
		if(A[j]<= x)
		{
			temp = A[j];
			A[j] = A[i];
			A[i] = temp;
			i=i+1;
		}

	}
	temp = A[i+1];
	A[i+1] = A[r];
	A[r] = temp;
	return i+1;
}
int RandomSelect(int *A,int p,int r,int i)
{
	int q,k;
	if(p==r)
		return A[p];
	q = RandomPartition(A,p,r);
	k = q - p + 1;
	if (i == k)
		return A[q];
	else if(i < k)
		return RandomSelect(A,p,q-1,i);
	else
		return RandomSelect(A,q+1,r,i-k);
}


int main()
{
	int k,n,i;
	scanf("%d%d",&n,&k);
	int * A = (int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&(A[i]));
	}
	int num=RandomSelect(A,0,n-1,k);
	printf("%d",num);
	free(A);
	return 0;
} 
