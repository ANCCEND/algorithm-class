#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

//tarjan + dag拓扑

const int MAX = 100005;

struct Edge
{
    int target, weight;
};

vector<Edge> graph[MAX], dag[MAX];

int dfn[MAX], low[MAX], timer, num_scc, node_scc[MAX];
bool inStack[MAX];
int size_scc[MAX], in_degree[MAX];
long long dist_scc[MAX];
stack<int> stk;

int n, k;

void tarjan(int u)
{
    low[u] = dfn[u] = ++timer;
    stk.push(u);
    inStack[u] = true;

    for (auto &it : graph[u])
    {
        int next = it.target;
        if (inStack[next])
        {
            low[u] = min(low[u], dfn[next]);
        }
        else if (dfn[next] == 0)
        {
            tarjan(next);
            low[u] = min(low[u], low[next]);
        }
    }
    if (dfn[u] == low[u])
    {
        num_scc++;
        int v;
        do
        {
            v = stk.top();
            stk.pop();
            inStack[v] = false;
            size_scc[num_scc]++;
            node_scc[v] = num_scc;
        } while (v != u);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    int x, a, b;
    for (int i = 1; i <= k; i++)
    {
        cin >> x >> a >> b;

        if (x == 1)
        {
            graph[a].push_back({b, 0});
            graph[b].push_back({a, 0});
        }
        else if (x == 2)
        {
            if (a == b)
            {
                cout << -1 << endl;
                return 0;
            }
            graph[a].push_back({b, 1});
        }
        else if (x == 3)
        {
            graph[b].push_back({a, 0});
        }
        else if (x == 4)
        {
            if (a == b)
            {
                cout << -1 << endl;
                return 0;
            }
            graph[b].push_back({a, 1});
        }
        else if (x == 5)
        {
            graph[a].push_back({b, 0});
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (dfn[i] == 0)
        {
            tarjan(i);
        }
    }

    for (int u = 1; u <= n; u++)
    {
        for (auto &edge : graph[u])
        {
            if (node_scc[u] == node_scc[edge.target])
            {
                if (edge.weight > 0)
                {
                    cout << -1 << endl;
                    return 0;
                }
            }
            else
            {
                dag[node_scc[u]].push_back({node_scc[edge.target], edge.weight});
                in_degree[node_scc[edge.target]]++;
            }
        }
    }

    vector<int> queue;
    for (int i = 1; i <= num_scc; i++)
    {
        dist_scc[i] = 1;
        if (in_degree[i] == 0)
            queue.push_back(i);
    }

    int head = 0;
    while (head < queue.size())
    {
        int u = queue[head++];
        for (auto &edge : dag[u])
        {
            dist_scc[edge.target] = max(dist_scc[edge.target], dist_scc[u] + edge.weight);
            if (--in_degree[edge.target] == 0)
                queue.push_back(edge.target);
        }
    }

    long long ans = 0;

    for (int i = 1; i <= num_scc; i++)
    {
        ans += dist_scc[i] * size_scc[i];
    }

    cout << ans << endl;

    return 0;
}