#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 1005;

int n;
vector<int> tree[MAX];
int dp[MAX][MAX];

int dfs(int start, int pre)
{
    if (dp[start][pre] != -1)
        return dp[start][pre];
    int i = 0, cost[MAX] = {0};
    for (int next : tree[start])
    {
        if (next == pre)
            continue;
        cost[++i] = dfs(next, start);
    }
    if (i)
    {
        sort(cost + 1, cost + 1 + i);
        for (int j = 1; j <= i; j++)
        {
            dp[start][pre] = max(dp[start][pre], cost[j] + i - j + 1);
        }
    }
    else
    {
        dp[start][pre] = 1;
    }
    return dp[start][pre];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int parent;
    for (int i = 2; i <= n; i++)
    {
        cin >> parent;
        tree[parent].push_back(i);
        tree[i].push_back(parent);
    }
    memset(dp, -1, sizeof(dp));

    long long ans = INT32_MAX;
    for (int i = 1; i <= n; i++)
    {
        ans = min((long long)dfs(i, 0), ans);
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
    {
        if (dp[i][0] == ans)
            cout << i << ' ';
    }

    return 0;
}