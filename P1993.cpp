#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int MAX = 5005;

struct Edge
{
    int target, weight;
};

int n, m;
vector<Edge> graph[MAX];
int cnt[MAX];
long long dist[MAX];
bool instack[MAX];

bool spfa()
{
    stack<int> s;
    for (int i = 1; i <= n; i++)
    {
        s.push(i);
        cnt[i] = 1;
        instack[i] = true;
    }
    while (!s.empty())
    {
        int u = s.top();
        s.pop();
        instack[u] = false;
        for (auto edge : graph[u])
        {
            int next = edge.target;

            if (dist[next] < (dist[u] + edge.weight))
            {
                dist[next] = dist[u] + edge.weight;
                cnt[next] = cnt[u] + 1;
                if (cnt[next] > n)
                    return false;
                if (instack[next] == false)
                {
                    s.push(next);
                    instack[next] = true;
                }
            }
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    int k, a, b, c;
    for (int i = 1; i <= m; i++)
    {
        cin >> k;
        if (k == 1)
        {
            cin >> a >> b >> c;
            graph[b].push_back({a, c});
        }
        else if (k == 2)
        {
            cin >> a >> b >> c;
            graph[a].push_back({b, -c});
        }
        else if (k == 3)
        {
            cin >> a >> b;
            graph[a].push_back({b, 0});
            graph[b].push_back({a, 0});
        }
    }

    cout << (spfa() ? "Yes" : "No");

    return 0;
}