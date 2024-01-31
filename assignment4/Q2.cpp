// Test Case
// 3 3 25
// 1 2 10
// 2 3 20
// 3 1 30
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> parent;
vector<pair<int, pair<int, int>>> edges;

int find(int x)
{
    return x == parent[x] ? x : parent[x] = find(parent[x]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (rand() % 2)
        swap(a, b);
    parent[a] = b;
}

int main()
{
    int n, m, z;
    cin >> n >> m >> z;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }

    sort(edges.begin(), edges.end());

    parent.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    int ans = n - 1;

    if (z < n - 1)
    {
        ans = 1e9;
    }

    for (const auto &edge : edges)
    {
        int a = edge.second.first;
        int b = edge.second.second;
        int c = edge.first;

        if (find(a) == find(b))
        {
            continue;
        }

        merge(a, b);
        n--;
        z -= c;

        if (z >= n - 1)
        {
            ans = n - 1;
        }
    }

    if (n > 1 || ans > 1e7)
    {
        ans = -1;
    }

    cout << ans << endl;

    return 0;
}