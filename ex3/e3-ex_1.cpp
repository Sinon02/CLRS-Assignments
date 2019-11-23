#include <iostream>
#include <vector>
class Coord {
public:
	int x;
	int y;
	Coord(int x, int y);
};
Coord::Coord(int x_, int y_)
{
	x = x_;
	y = y_;
}
int main()
{
	int n, m;
	std::cin >> n >> m;
	int **M = new int* [n];
	int** N = new int* [n];
	std::vector<Coord>Square;
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
			N[i][j] = 0;
			std::cin >> M[i][j];
			if (M[i][j] == 0)
			{
				Square.push_back(Coord(i, j));
				N[i][j] = 1;
				result++;
			}
		}
	}
	int min = (n > m) ? m : n;
	
	std::vector<Coord>::iterator it;
	for (int i = 1; i <= min; i++)
	{
		int have_increase = 0;
		for (it = Square.begin(); it != Square.end();)
		{
			int x = (*it).x;
			int y = (*it).y;
			if (x+1<m&&y+1<n&&N[x+1][y]&&N[x][y+1]&&N[x+1][y+1])
			{
				it++;
				result++;
				have_increase = 1;
			}
			else
			{
				N[x][y] = 0;
				it=Square.erase(it++);
			}
		}
		if(have_increase==0)
		{
			break;
		}
	}
	printf("%d", result);
	return 0;
}
