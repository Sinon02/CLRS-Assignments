#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define INF 1000001
class vertex
{
public:
	int d;
	int index;
	vertex(int d, int index) :d(d), index(index) {}
};
typedef struct Entry {
	int node;
	double weight;

	bool operator == (const int e) const
	{
		return (node == e);
	}
	Entry(int n, int w) :node(n), weight(w) {}
} Entry;


class myoperator
{
public:
	bool operator()(vertex const& a, vertex const& b)
	{
		return (a.d > b.d);
	}
};

int Dij(std::vector<std::vector<Entry>>& G, int N,int S,int T)
{
	std::priority_queue < vertex, std::vector<vertex>, myoperator> Q;
	std::vector<int> key(N);
	std::vector<bool> visited(N);
	for (int i = 0; i < N; i++)
	{
		key[i] = INF;
		visited[i] = true;
	}
	Q.push(vertex(0, S));
	key[S] = 0;
	for (int i = 0; i < N; i++)
	{
		vertex ver = Q.top();
		Q.pop();
		int u = ver.index;
		visited[u] = false;
		for (std::vector<Entry>::iterator it = G[u].begin(); it != G[u].end(); it++)
		{
			int v = (*it).node;
			if (visited[v] &&((*it).weight +key[u]) < key[v])
			{
				key[v] = ((*it).weight + key[u]);
				Q.push(vertex(key[v], v));
			}
		}
	}
	int result = 0;
	if (key[T] == INF)
	{
		result = -1;
	}
	else
	{
		result = key[T];
	}
	return result;
}
int main()
{
	int N, M,S,T;
	std::cin >> N >> M>>S>>T;
	std::vector<std::vector<Entry>> Graph(N);
	int w, u, v;
	std::vector<Entry>::iterator it;
	for (int i = 0; i < M; i++)
	{
		std::cin >> u >> v >> w;
		u--;
		v--;
		it = std::find(Graph[u].begin(), Graph[u].end(), v);
		if (it==Graph[u].end() || w < (*it).weight)
		{
			if (it == Graph[u].end()) //new edge
			{
				Graph[u].push_back(Entry(v,w));
			}
			else
			(*it).weight = w;
		}
	}
	std::cout << Dij(Graph, N,S-1,T-1);
	return 0;
}