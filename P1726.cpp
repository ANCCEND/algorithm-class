#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define MAXN 5005

//tarjan

using namespace std;

int N, M;
vector<int> node[MAXN];
vector<vector<int>> sccs;
int dfn[MAXN], low[MAXN];

stack<int> stk;

bool inStack[MAXN];

int num_scc;
int node_scc[MAXN];
int timer;

void tarjan(int u)
{
    low[u] = dfn[u] = ++timer;
    stk.push(u);
    inStack[u] = true;

    for (auto v : node[u])
    {
        if (inStack[v] == true)
        {
            low[u] = min(dfn[v], low[u]);
        }
        else
        {
            tarjan(v);
            low[u] = min(low[v], low[u]);
        }
    }

    if (dfn[u] == low[u])
    {
        num_scc++;
        sccs.emplace_back();
        int v;
        do
        {
            v = stk.top();
            stk.pop();
            inStack[v] = false;

            node_scc[v] = num_scc;
            sccs.back().push_back(v);
        } while (v != u);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    int a, b, t;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> t;
        if (t == 1)
        {
            node[a].push_back(b);
        }
        else
        {
            node[a].push_back(b);
            node[b].push_back(a);
        }
    }
    for (int i = 1; i <= N; ++i)
    {
        if (dfn[i] == 0)
        {
            tarjan(i);
        }
    }

    int max = 0;
    vector<int> result;
    for (auto i : sccs)
    {
        if (i.size() > max)
        {
            max = i.size();
            sort(i.begin(), i.end());
            result = i;
        }
        else if (i.size() == max)
        {
            sort(i.begin(), i.end());
            if (i[0] < result[0])
            {
                result = i;
            }
        }
    }
    cout << max << endl;
    for (int i = 0; i < max; i++)
    {
        cout << result[i] << ' ';
    }

    return 0;
}