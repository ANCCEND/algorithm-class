#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(long long x, long long y, long long dx, long long dy, long long len)
{
    if (len == 1)
        return;

    long long half = len / 2;
    long long midX = x + half;
    long long midY = y + half;

    // 情况 1: 公主在左上角子区域
    if (dx < midX && dy < midY)
    {
        cout << midX << " " << midY << " 1" << endl;
        solve(x, y, dx, dy, half);
        solve(x, midY, midX - 1, midY, half);
        solve(midX, y, midX, midY - 1, half);
        solve(midX, midY, midX, midY, half);
    }
    // 情况 2: 公主在右上角子区域
    else if (dx < midX && dy >= midY)
    {
        cout << midX << " " << midY - 1 << " 2" << endl;
        solve(x, y, midX - 1, midY - 1, half);
        solve(x, midY, dx, dy, half);
        solve(midX, y, midX, midY - 1, half);
        solve(midX, midY, midX, midY, half);
    }
    // 情况 3: 公主在左下角子区域
    else if (dx >= midX && dy < midY)
    {
        cout << midX - 1 << " " << midY << " 3" << endl;
        solve(x, y, midX - 1, midY - 1, half);
        solve(x, midY, midX - 1, midY, half);
        solve(midX, y, dx, dy, half);
        solve(midX, midY, midX, midY, half);
    }
    // 情况 4: 公主在右下角子区域
    else
    {
        cout << midX - 1 << " " << midY - 1 << " 4" << endl;
        solve(x, y, midX - 1, midY - 1, half);
        solve(x, midY, midX - 1, midY, half);
        solve(midX, y, midX, midY - 1, half);
        solve(midX, midY, dx, dy, half);
    }
}

int main()
{
    int k;
    long long x, y;
    if (!(cin >> k >> x >> y))
        return 0;

    long long size = 1LL << k; // 2^k
    solve(1, 1, x, y, size);

    return 0;
}