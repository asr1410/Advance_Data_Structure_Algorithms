// Test Case
// 7 8
// 0 1 -7
// 0 2 -1
// 1 3 5
// 2 3 3
// 2 4 5
// 3 5 3
// 4 5 3
// 5 6 2

// Harry claim is right because if edges from the sources were negative it will be included in the shortest path
// as minimum of negative number is the most negative number and it will be included in the shortest path.
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<pair<pair<int, int>, int>> edges;

    for (int i = 0; i < M; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({{u, v}, wt});
    }

    int src = 0;
    int inf = 10000000;
    vector<int> dist(N, inf);
    dist[src] = 0;

    for (int i = 1; i <= N - 1; i++)
    {
        for (const auto &edge : edges)
        {
            int u = edge.first.first;
            int v = edge.first.second;
            int wt = edge.second;

            if (dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    int fl = 0;
    for (const auto &edge : edges)
    {
        int u = edge.first.first;
        int v = edge.first.second;
        int wt = edge.second;

        if (dist[u] + wt < dist[v])
        {
            cout << -1;
            fl = 1;
            break;
        }
    }

    if (!fl)
    {
        for (int i = 0; i < N; i++)
        {
            cout << dist[i] << " ";
        }
    }

    return 0;
}