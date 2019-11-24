#include<iostream> 
#include<vector>
#include<algorithm>
int BS(int begin, int end, int value, std::vector<int> v)
{
	while (end >begin+1 )
	{
		int mid = begin + (end - begin) / 2;
		if (v[mid] >= value)
			end = mid;
		else
			begin = mid;
	}
return end;
}
int LIS(std::vector<int>& Y)
{
	if (Y.size() == 0)
		return 0;
	std::vector<int> E(Y.size(),0);
	int length = 1; 
	E[0] = Y[0];
	std::vector<int>::iterator it_Y;
	for (it_Y = Y.begin(); it_Y != Y.end(); it_Y++) {
		if (*it_Y < E[0])
		{
			E[0] = *it_Y;
		}
		else if (*it_Y> E[length-1])
			E[length++] = *it_Y;
		else
		{
			int index = BS(0, length - 1, *it_Y, E);
			E[index] = *it_Y;
		}
	}
	return length;
}

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> Y;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		std::cin >> x >> y;
		Y.push_back(y);
	}
	int result=LIS(Y);
	printf("%d", result);
	return 0;
}