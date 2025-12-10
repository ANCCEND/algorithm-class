#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
int brick[51][51];
int sumValue[51][51]; // 第i列前n个元素之和
int dp[51][1276];     // 当前列取p个元素，总元素数为k的分数
int oldDp[51][1276];  // 前一列取q个元素，总元素为k-p的分数

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cin >> brick[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            sumValue[i][j] = sumValue[i][j - 1] + brick[j][i];
        }
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;

    for (int j = n, i = 1; j > 0; j--, i++)
    {
        memcpy(oldDp, dp, sizeof(oldDp));
        memset(dp, -1, sizeof(dp));

        for (int p = 0; p <= i; p++)
        {
            for (int k = p; k <= m && k <= (i * (i + 1) / 2); k++)
            {
                int q_min = max(0, p - 1);
                for (int q = q_min; q <= i - 1; q++)
                {
                    if (oldDp[q][k - p] != -1)
                    {
                        int value = oldDp[q][k - p] + sumValue[j][p];
                        if (value > dp[p][k])
                            dp[p][k] = value;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int p = 0; p <= n; p++)
    {
        for (int k = 0; k <= m; k++)
        {
            ans = dp[p][k] > ans ? dp[p][k] : ans;
        }
    }
    cout << ans;

    return 0;
}