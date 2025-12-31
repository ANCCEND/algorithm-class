#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main()
{
    int x, n;
    cin >> x >> n;
    vector<int> coin(n);

    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }
    sort(coin.begin(), coin.end());
    if (coin[0] != 1)
    {
        cout << -1;
        return 0;
    }

    int curr_max = 1;
    int num = 1;

    while (curr_max < x)
    {
        auto add = upper_bound(coin.begin(), coin.end(), curr_max + 1);
        if (add == coin.begin())
        {
            cout << -1 << endl;
            return 0;
        }
        curr_max += *(add - 1);
        num++;
    }
    cout << num << endl;

    return 0;
}