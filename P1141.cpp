#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int n, m;
char g[MAXN][MAXN];
int id[MAXN][MAXN];   // 连通块编号
int siz[MAXN * MAXN]; // 每个连通块的大小
bool vis[MAXN][MAXN];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int cnt = 0;

void bfs(int sx, int sy)
{
    queue<pair<int, int>> q;
    q.push({sx, sy});
    vis[sx][sy] = true;
    id[sx][sy] = cnt;

    int tot = 1;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 1 || nx > n || ny < 1 || ny > n)
                continue;
            if (vis[nx][ny])
                continue;
            if (g[nx][ny] == g[x][y])
                continue;

            vis[nx][ny] = true;
            id[nx][ny] = cnt;
            q.push({nx, ny});
            tot++;
        }
    }
    siz[cnt] = tot;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> (g[i] + 1);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!vis[i][j])
            {
                cnt++;
                bfs(i, j);
            }
        }
    }

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        cout << siz[id[x][y]] << '\n';
    }
    return 0;
}
