#include <iostream>
#include <vector>
#include <queue>
#define INF 10000000
void BFS(int** G,int s,int t,std::vector<int>&P,int N)
{
    std::vector<bool> visited(N);
    for (int i = 0; i < N; i++)
    {
        visited[i] = false;
    }
    std::queue<int> q;
    int* path = new int[N]();
    visited[s] = true;
    q.push(s);
    bool find_or_not = false;
    while (!q.empty())
    {
        int top = q.front();
        if (top == t)
        {
            find_or_not = true;
            break;
        }
        q.pop();
        for (int i = 0; i < N; i++)
        {
            if (!visited[i] && G[top][i] != 0)
            {
                visited[i] = true;
                q.push(i);
                path[i]=top;
            }
        }
    }
    if (find_or_not)
    {
        for (int i = t; i != s; i = path[i])
        {
            P.insert(P.begin(),i);
        }
        P.insert(P.begin(), s);
    }
    delete[] path;
}
void GetRes(int** F, int** C, int** R,int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (C[i][j] != 0)
            {
                R[i][j] = C[i][j] - F[i][j];
            }
            else if (C[j][i] != 0)
            {
                R[i][j] = F[j][i];
            }
            else
            {
                R[i][j] = 0;
            }
        }
    }
}
int FORD_FULKERSON(int** F, int** C,int** R, int S, int T,int N)
{
    int max_flow = 0;
    while (1)
    {
        GetRes(F, C, R, N);
        std::vector<int>Path;
        BFS(R, S, T, Path, N);
        if (Path.empty())
        {
            return max_flow;
        }
        int cf = INF;
        std::vector<int> P;
        for (std::vector<int>::iterator it = Path.begin(); it != Path.end()-1; it++)
        {
            if (R[*(it)][*(it+1)] < cf)
            {
                cf = R[*(it)][*(it+1)];
            }
        }
        for (std::vector<int>::iterator it = Path.begin(); it != Path.end() - 1; it++)
        {
            int u = *it;
            int v = *(it + 1);
            if (C[u][v] != 0)
                {
                    F[u][v] += cf;
                }
                else
                {
                    F[v][u] -= cf;
                }
        }
        max_flow += cf;
    }
}
int main()
{
    int N, M, S, T;
    std::cin >> N >> M >> S >> T;
    int** F = new int*[N];
    int** C = new int* [N];
    int** R = new int* [N]; //residual network
    for (int i = 0; i < N; i++)
    {
        F[i] = new int[N]();
        C[i] = new int[N]();
        R[i] = new int[N]();
    }
    for (int i = 0; i < M; i++)
    {
        int u, v, c;
        std::cin >> u>>v>> c;
        C[u - 1][v - 1] += c;
    }
    std::cout << FORD_FULKERSON(F, C, R, S - 1, T - 1, N);
    for (int i = 0; i < N; i++)
    {
        delete [] F[i];
        delete [] C[i];
        delete [] R[i];
    }
    delete [] F;
    delete [] C;
    delete [] R;
    return 0;
}

