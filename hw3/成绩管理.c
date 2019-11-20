#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	unsigned int id;
	unsigned int math;
	unsigned int english;
	unsigned int total;
}Student;

void swap(Student *s1, Student *s2)
{
	Student temp;
	temp = *s2;
	*s2 = *s1;
	*s1 = temp;
}

int swap_or_not(Student s1, Student s2)
{
	int total_l, total_e, math_l, math_e, english_l, english_e, id_l, id_e;
	total_l = (s1.total < s2.total);
	total_e = (s1.total == s2.total);
	math_l = (s1.math < s2.math);
	math_e = (s1.math == s2.math);
	english_l = (s1.english < s2.english);
	english_e = (s1.english == s2.english);
	id_l = (s1.id < s2.id);
	id_e = (s1.id == s2.id);
	return (total_l || (total_e&&math_l) || (total_e&&math_e&&english_l) || (total_e&&math_e&&english_e&&id_l));
}

int Partition(Student * A, int p, int r)
{
	Student x;
	int i = p - 1,j=0;
	x = A[r];
	for (j = p; j < r; j++)
	{
		if (swap_or_not(x, A[j]))
		{
			i = i + 1;
			swap(&A[i], &A[j]);
		}
	}
	swap(&A[i + 1], &A[r]);
	return i + 1;
}

void QuickSort(Student * A, int p, int r)
{
	int q = 0;
	if (p < r)
	{
		q = Partition(A, p, r);
		QuickSort(A, p, q - 1);
		QuickSort(A, q+1, r);
	}
}
int main()
{
	int n = 0, i = 0, j = 0;
	unsigned int id, math, english, total;
	Student * students;
	Student temp;
	scanf("%d", &n);
	getchar();
	students = (Student *)malloc(n * sizeof(Student));
	for (i = 0; i < n; i++)
	{
		scanf("%u %u %u", &id, &math, &english);
		students[i].id = id;
		students[i].math = math;
		students[i].english = english;
		students[i].total = math + english;
	}

	QuickSort(students, 0, n-1);
	for (i = 0; i < n; i++)
	{
		if (i != n - 1)
			printf("%u ", students[i].id);
		else
			printf("%u", students[i].id);
	}

	free(students);
	system("pause");
	return 0;
}