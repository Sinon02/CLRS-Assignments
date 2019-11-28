#include <iostream>
#include <vector>
#include <queue>
#include <set>
#define INF 10001
int main()
{
	int N;
	unsigned int K;
	std::cin >> N >> K;
	std::vector<std::queue<int>> V(INF);
	std::vector<int> Address(N);
	std::set<int,std::greater<int>> Cache;
	int result = 0;
	for (int i = 0; i < N; i++)
	{
		std::cin >> Address[i];
		V[Address[i]].push(i);
	}
	for (int i = 0; i < N; i++)
	{
		V[Address[i]].pop();
		if (Cache.count(Address[i]))
		{
			continue;
		}
		result++;
		if (Cache.size() < K)
		{
			Cache.insert(Address[i]);
		}
		else
		{
			std::set<int>::iterator it;
			int max = 0;
			std::set<int>::iterator max_it;
			for (it = Cache.begin(); it != Cache.end(); it++)
			{
				int value;
				if (V[*it].empty())
				{
					value = INF;
				}
				else
				{
					value = V[*it].front();
				}
				if (value > max)
				{
					max = value;
					max_it = it;
				}
			}
			Cache.erase(max_it);
			Cache.insert(Address[i]);
		}
	}
	std::cout << result << std::endl;
}
