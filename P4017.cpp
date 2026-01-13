#include <bits/stdc++.h>
using namespace std;

const int MOD = 80112002;

int n, m;
vector<int> G[5005];
int indeg[5005], outdeg[5005];
long long dp[5005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        indeg[b]++;
        outdeg[a]++;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) {
            dp[i] = 1;
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : G[u]) {
            dp[v] = (dp[v] + dp[u]) % MOD;
            indeg[v]--;
            if (indeg[v] == 0) {
                q.push(v);
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (outdeg[i] == 0) {
            ans = (ans + dp[i]) % MOD;
        }
    }

    cout << ans << "\n";
    return 0;
}
