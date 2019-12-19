#include <iostream>
#include <vector>
#include <stack>
#include <set>
#define INF 10000000
void GetOrder(std::vector<std::vector<int>> &Graph,int v, std::stack<int> &Order,bool visited[])
{
    visited[v] = true;
    for (std::vector<int>::iterator it = Graph[v].begin(); it != Graph[v].end(); it++)
    {
        if (!visited[*it])
        {
            GetOrder(Graph, *it, Order, visited);
        }
    }
    Order.push(v);
}
void DFS(std::vector<std::vector<int>>& Graph, int v, std::stack<int>& Order, bool visited[],int parent[],int p,int &scc_n)
{
    visited[v] = true;
    scc_n++;
    parent[v] = p;
    for (std::vector<int>::iterator it = Graph[v].begin(); it != Graph[v].end(); it++)
    {
        if (!visited[*it])
        {
            DFS(Graph, *it, Order, visited,parent,p,scc_n);
        }
    }
}

int main()
{
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> Graph(N);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        std::cin >> u >> v;
        Graph[u-1].push_back(v-1);
    }
    bool* visited = new bool[N];
    for (int i = 0; i < N; i++)
    {
        visited[i] = false;
    }
    std::stack<int> temp_Order;
    std::stack<int> Order;
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            GetOrder(Graph, i, temp_Order, visited);
        }
    }
    while (!temp_Order.empty())
    {
        int top = temp_Order.top();
        temp_Order.pop();
        Order.push(top);
    }
    for (int i = 0; i < N; i++)
    {
        visited[i] = false;
    }
    std::vector<int> SCC;
    int* parent = new int[N];
    int count = 0;
    while (!Order.empty())
    {
        int v = Order.top();
        Order.pop();
        if (!visited[v])
        {
            int scc_n=0;
            DFS(Graph, v, Order, visited,parent,count++,scc_n);
            SCC.push_back(scc_n);
        }
    }
    int new_N = SCC.size();
    std::vector<std::vector<int>> new_Graph(new_N);
    for (int i = 0; i < N; i++)
    {
        for (std::vector<int>::iterator it = Graph[i].begin(); it != Graph[i].end(); it++)
        {
            if (parent[*it] != parent[i])
            {
                new_Graph[parent[i]].push_back(parent[*it]);
            }
        }
    }
    for (int i = 0; i <new_N; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < new_N; i++)
    {
        if (!visited[i])
        {
            GetOrder(new_Graph, i, Order, visited);
        }
    }
    int* dist = new int[new_N];
    for (int i = 0; i < new_N; i++)
    {
        dist[i] = SCC[i];
    }
    int max = dist[Order.top()];
    while (!Order.empty())
    {
        int u = Order.top();
        Order.pop();
        for (std::vector<int>::iterator it = new_Graph[u].begin(); it != new_Graph[u].end(); it++)
            {
                if (dist[*it] < dist[u] + SCC[*it])
                {
                    dist[*it] = dist[u] + SCC[*it];
                    if (dist[*it] > max)
                    {
                        max = dist[*it];
                    }
                }
            }
    }
    std::cout << max;



}


