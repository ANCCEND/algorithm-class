#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, t;
};

int parent[1005];

int find(int x)
{
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
        parent[b] = a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<Edge> edges(M);
    for (int i = 0; i < M; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].t;
    }

    sort(edges.begin(), edges.end(),
         [](const Edge &a, const Edge &b)
         {
             return a.t < b.t;
         });

    for (int i = 1; i <= N; i++)
        parent[i] = i;

    int components = N;

    for (auto &e : edges)
    {
        if (find(e.u) != find(e.v))
        {
            unite(e.u, e.v);
            components--;
            if (components == 1)
            {
                cout << e.t << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;
    return 0;
}
