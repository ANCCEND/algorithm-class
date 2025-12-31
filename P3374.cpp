#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 500005;

int n, m;
int Array[MAX];
int bit[MAX];

inline int lowbit(int x)
{
    return x & (-x);
}

void build()
{
    for (int i = 1; i <= n; i++)
    {
        bit[i] += Array[i];
        int j = i + lowbit(i);
        if (j <= n)
        {
            bit[j] += bit[i];
        }
    }
}

void update(int x, int k)
{
    for (; x <= n; x += lowbit(x))
    {
        bit[x] += k;
    }
}

inline long long query(int x)
{
    int ans = 0;
    for (; x > 0; x -= lowbit(x))
    {
        ans += bit[x];
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> Array[i];
    }
    build();
    int a, b, c;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b >> c;
        if (a == 1)
        {
            update(b, c);
        }
        else
        {
            cout << (query(c) - query(b - 1)) << endl;
        }
    }

    return 0;
}