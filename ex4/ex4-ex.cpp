#include <iostream>
#include <vector>
#include <set>
#include <algorithm> 

int FIND_MAX(std::vector<int> E, int M)
{
	std::vector<int>::iterator min_it = std::min_element(E.begin(), E.end());
	if (M == 0)
	{
		return *min_it;
	}
	if (min_it == E.begin())
	{
		*(min_it + 1) += *(min_it);
		E.erase(min_it);
		return FIND_MAX(E, M - 1);
	}
	else if (min_it == E.end()-1)
	{
		*(min_it - 1) += *(min_it);
		E.erase(min_it);
		return FIND_MAX(E, M - 1);
	}
	else
	{
		int max1, max2;
		std::vector<int> E1(E);
		int index = min_it - E.begin();
		*(min_it + 1) += *(min_it);
		E.erase(min_it);
		max1 = FIND_MAX(E, M - 1);
		min_it = E1.begin() + index;
		*(min_it - 1) += *(min_it);
		E1.erase(min_it);
		max2 = FIND_MAX(E1, M - 1);
		return std::max(max1, max2);
	}
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
	std::vector<int> E;
	for (int i = 0; i < N - 1; i++)
	{
		E.push_back(A[i + 1] - A[i]);
	}
	std::cout<<FIND_MAX(E, M);
}
