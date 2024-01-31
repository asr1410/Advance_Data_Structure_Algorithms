// Test Case
// 5 4
// 0 1
// 2 3
// 3 4
// 4 5
#include <iostream>
#include <vector>
using namespace std;

bool isCyclicUtil(int v, vector<pair<int, int>> &edges, vector<bool> &visited, vector<bool> &recStack)
{
    if (!visited[v])
    {
        visited[v] = true;
        recStack[v] = true;

        for (auto &edge : edges)
        {
            int u = edge.first;
            if (u == v)
            {
                int w = edge.second;
                if (!visited[w] && isCyclicUtil(w, edges, visited, recStack))
                    return true;
                else if (recStack[w])
                    return true;
            }
        }
    }
    recStack[v] = false;
    return false;
}

bool isCyclic(vector<pair<int, int>> &edges, int V)
{
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    for (int i = 0; i < V; i++)
        if (!visited[i] && isCyclicUtil(i, edges, visited, recStack))
            return true;
    return false;
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> edges;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }

    if (isCyclic(edges, N))
        cout << -1;
    else
        cout << 1;

    return 0;
}