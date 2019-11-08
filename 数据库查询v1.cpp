#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
	int id;
	int a_id;
}User;
int NUM = 0;
int NUM_LIMIT = 1000000000;
int BinarySearch(User *U, int p, int q, int a_id)
{
	int r;
	while (p <= q)
	{
		if (p == q)
		{
			if (U[p].a_id == a_id)
				return U[p].id;
			else
				return -1;
		}
		r = (p + q) / 2;
		if (U[r].a_id < a_id)
		{
			p = r + 1;
		}
		else if (U[r].a_id > a_id)
		{
			q = r - 1;
		}
		else
			return U[r].id;
	}
	return -1;

}
void swap(User *s1, User *s2)
{
	User temp;
	temp = *s2;
	*s2 = *s1;
	*s1 = temp;
}
int Partition(User * A, int p, int r)
{
	User x;
	int i = p - 1, j = 0;
	x = A[r];
	for (j = p; j < r; j++)
	{
		if (A[j].a_id <= x.a_id)
		{
			i = i + 1;
			swap(&A[i], &A[j]);
		}
	}
	swap(&A[i + 1], &A[r]);
	return i + 1;
}
void QuickSort(User * A, int p, int r)
{
	int q = 0;
	if (p < r)
	{
		q = Partition(A, p, r);
		QuickSort(A, p, q - 1);
		QuickSort(A, q + 1, r);
	}
}
int Find(User * U, int a_id)
{
	int p,r;
	p = 0;
	r = NUM - 1;
	return BinarySearch(U, p, r, a_id);
}

void InsertSort(User *U, int n,User u)// suppose A is sorted and n is the length of A(now), a is the element to insert
{
	int i=n-1;
	while (U[i].a_id > u.a_id&&i>=0)
	{
		U[i + 1] = U[i];
		i--;
	}
	U[i + 1] = u;
}

void ReadIn()
{
	//User * U = (User *)malloc(NUM_LIMIT * sizeof(User));
	int * U = (int *)malloc(NUM_LIMIT * sizeof(int));
	int id, a_id;
	char str[100];
	char *Seq = str, *pch;
	int search_time = 0;
	User temp;
	while (strcmp(Seq, "EXIT"))
	{
		fgets(str, 100, stdin);
		pch = strtok(str, "\n");
		Seq = strtok(pch, " ");
		if (!strcmp(Seq, "INSERT"))
		{
			pch = strtok(NULL, " ");
			id = atoi(pch);
			pch = strtok(NULL, " ");
			a_id = atoi(pch);
			temp.id = id;
			temp.a_id = a_id;
			//InsertSort(U, NUM, temp);
			U[a_id] = id;
			NUM++;
		}
		else if (!strcmp(Seq, "FIND"))
		{
			/*if (!search_time)
			{
				QuickSort(U, 0, NUM - 1);
				search_time ++;
			}*/
			pch = strtok(NULL, " ");
			a_id = atoi(pch);
			printf("%d\n", U[a_id]);
		}
	}
	free(U);
}
int main()
{
	ReadIn();
	system("pause");
	return 0;
}