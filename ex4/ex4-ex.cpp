#include <iostream>
#include <vector>
#include <set>
#include <algorithm> 
#include <map>
#define INF 1000000000
int Judge_OK(int value,int M, std::vector<int> A)
{
	std::vector<int>::iterator pre = A.begin();
	int num = 0;
	for (std::vector<int>::iterator it = A.begin() + 1; it != A.end(); it++)
	{
		if (*it - *pre < value)//delete it
		{
			num++;
		}
		else
		{
			pre = it;
		}
		if (num > M)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int N, M;
	std::cin >> N >> M;
	std::vector<int> A(N, 0);
	for (int i = 0; i < N; i++)
	{
		std::cin >> A[i];
	}
	std::sort(A.begin(), A.end());
	int min = INF;
	for (int i = 0; i < N - 1; i++)
	{
		if (A[i + 1] - A[i] < min)
		{
			min = A[i + 1] - A[i];
		}
	}
	int left = min;
	int right = *(A.end() - 1)  -*(A.begin());
	int result = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (Judge_OK(mid, M, A))
		{
			result = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	std::cout << result;
	return 0;

}
