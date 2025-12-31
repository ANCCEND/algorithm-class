#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

//记忆化搜索

const int MAX = 105;

int r, c;
int a[105][105], s[105][105];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

int dfs(int x, int y)
{
    if (s[x][y] != -1)
    {
        return s[x][y];
    }
    s[x][y] = 1;
    int temp[4] = {0};
    for (int i = 0; i < 4; i++)
    {
        int next_x = x + dx[i], next_y = y + dy[i];
        if (next_x<1 | next_y<1 | next_x> r | next_y> c)
            continue;
        if (a[x][y] > a[next_x][next_y])
        {
            s[x][y] = max(dfs(next_x, next_y) + 1, s[x][y]);
        }
    }
    return s[x][y];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> a[i][j];
        }
    }

    memset(s, -1, sizeof(s));

    int ans = 0;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            ans = max(ans, dfs(i, j));
        }
    }

    cout << ans;

    return 0;
}