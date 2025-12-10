#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int MAX = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string target;
    cin >> target;
    int n = target.length();

    vector<vector<int>> dp(n, vector<int>(n, MAX));

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
    }

    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = len - 1 + i;
            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
            if (target[i] == target[j])
            {
                dp[i][j] = min(dp[i][j], dp[i+1][j]);
            }
        }
    }
    cout<<dp[0][n-1];

    return 0;
}