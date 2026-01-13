#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

//状压dp

double Distance[20][20], dp[1 << 15][20];
double x[20], y[20];
int n;

inline double getDist(double x1, double x2, double y1, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf %lf", &x[i], &y[i]);
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            Distance[i][j] = getDist(x[i], x[j], y[i], y[j]);
        }
    }

    memset(dp, 127, sizeof(dp));
    double INF=dp[0][0];

    for (int i = 1; i <= n; i++)
    {
        dp[1 << (i - 1)][i] = Distance[0][i];
    }

    for (int k = 1; k < (1 << n); k++)
    {
        for (int i = 1; i <= n; i++)
        {
            if ((k & (1 << (i - 1))) == 0)
                continue;
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    continue;
                if ((k & (1 << (j - 1))) == 0)
                {
                    int next_k = k | (1 << (j - 1));
                    dp[next_k][j] = min(dp[next_k][j], dp[k][i] + Distance[i][j]);
                }
            }
        }
    }

    double ans = INF;
    int final_k = (1 << n) - 1;
    for (int i = 1; i <= n; i++)
    {
        ans = min(dp[final_k][i], ans);
    }

    printf("%.2lf\n", ans);

    return 0;
}