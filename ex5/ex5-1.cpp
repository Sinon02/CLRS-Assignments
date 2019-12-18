#include <iostream>
#include <vector>
#include <queue>
#include <set>
#define INF 100000000
class vertex
{
public:
	int index;
	int key;
	int pi;
	bool operator <(const vertex &b)const
	{
		return (key < b.key);
	}
	vertex()
	{
		index = 0;
		key = 0;
		pi = 0;
	}
	vertex(const vertex& v)
	{
		index = v.index;
		key = v.key;
		pi = v.pi;
	}
};
int FindMin(std::vector<int>&key, std::vector<bool>&visited,int N)
{
	int min = INF;
	int min_index = 0;
	for (int i = 0; i < N; i++)
	{
		if (visited[i]&&key[i]<min)
		{
			min_index = i;
			min = key[i];
		}
	}
	return min_index;
}
int Prim(std::vector<std::vector<int>> &Adj,int **& W,int N)
{
	std::vector<int> key(N);
	std::vector<int> pi(N);
	std::vector<bool> visited(N);
	for (int i = 0; i < N; i++)
	{
		key[i] = INF;
		pi[i] = 0;
		visited[i] = true;
	}
	int min_index = FindMin(key, visited, N);
	key[min_index] = 0;
	for (int i = 0; i < N; i++)
	{
		int u= FindMin(key, visited, N);
		visited[u] = false;
		for (std::vector<int>::iterator it = Adj[u].begin(); it != Adj[u].end(); it++)
		{
			int v = *it;
			if (visited[v] && W[u][v] < key[v])
			{
				pi[v] = u;
				key[v] = W[u][v];
			}
		}
	}
	int result=0;
	for (int i = 0; i < N; i++)
	{
		result += W[i][pi[i]];
	}
	return result;
}
int main()
{
	int N, M;
	std::cin >> N >> M;
	int** W = new int* [N];
	std::vector<std::vector<int>>Adj(N);
	for (int i = 0; i < N; i++)
	{
		W[i] = new int[N]();
	}
	int w,u,v;
	for (int i = 0; i < M; i++)
	{
		std::cin >> u >> v >> w;
		u--;
		v--;
		if (W[u][v] == 0 || W[u][v] != 0 && w < W[u][v])
		{
			if (W[u][v] == 0) //new edge
			{
				Adj[u].push_back(v);
				Adj[v].push_back(u);
			}
			W[u][v] = w;
			W[v][u] = w;
		}
	}
	std::cout << Prim(Adj, W, N);
	return 0;
}