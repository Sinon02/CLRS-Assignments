#include <iostream>
int min_3(int a, int b, int c)
{
	int min = (a < b) ? a : b;
	min = (min < c) ? min : c;
	return min;
}
int main()
{
	int n, m;
	std::cin >> n >> m;
	int **M = new int* [n];
	int** N = new int* [n];
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		M[i] = new int[m];
		N[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cin >> M[i][j];
			if (i == 0||j==0)
			{
				N[i][j] = 1 - M[i][j];
				result += N[i][j];
			}
			else
			{
				N[i][j] = 0;
			}
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (M[i][j] == 0)
			{
				N[i][j] = min_3(N[i - 1][j], N[i][j - 1], N[i - 1][j - 1])+1;
				result += N[i][j];
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		delete[] M[i];
		delete[] N[i];
	}
	delete [] M;
	delete [] N;

	printf("%d", result);
	return 0;
}
