#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 1000005;

int n;
string s;
int sa[MAXN];
int rk[MAXN];
int oldrk[MAXN];
int id[MAXN];
int cnt[MAXN];

void buildSA()
{
    int m = 127;

    for (int i = 1; i <= n; i++)
        cnt[rk[i] = s[i - 1]]++;
    for (int i = 1; i <= m; i++)
        cnt[i] += cnt[i - 1];
    for (int i = n; i >= 1; i--)
        sa[cnt[rk[i]]--] = i;

    for (int w = 1;; w <<= 1)
    {
        int p = 0;

        for (int i = n - w + 1; i <= n; i++)
            id[++p] = i;
        for (int i = 1; i <= n; i++)
        {
            if (sa[i] > w)
                id[++p] = sa[i] - w;
        }

        memset(cnt, 0, sizeof(int) * (m + 1));
        for (int i = 1; i <= n; i++)
            cnt[rk[i]]++;
        for (int i = 1; i <= m; i++)
            cnt[i] += cnt[i - 1];

        for (int i = n; i >= 1; i--)
            sa[cnt[rk[id[i]]]--] = id[i];

        memcpy(oldrk, rk, sizeof(int) * (n + 1));
        p = 0;

        auto is_same = [&](int i, int j)
        {
            return oldrk[i] == oldrk[j] &&
                   (i + w <= n ? oldrk[i + w] : -1) == (j + w <= n ? oldrk[j + w] : -1);
        };

        for (int i = 1; i <= n; i++)
        {
            rk[sa[i]] = is_same(sa[i], sa[i - 1]) ? p : ++p;
        }

        if (p == n)
            break;
        m = p;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> s))
        return 0;
    n = s.length();

    buildSA();

    for (int i = 1; i <= n; i++)
    {
        cout << sa[i] << (i == n ? "" : " ");
    }

    return 0;
}