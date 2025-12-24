#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
using ll = long long;
using Map = unordered_map<ll, unordered_set<int>>;

Map left_map, right_map;

vector<int> cows(21);

int n;

void dfs(int start, int end, ll curr_sum, Map &target, int mask)
{
    if (start > end)
    {
        target[curr_sum].insert(mask);
        return;
    }
    dfs(start + 1, end, curr_sum + cows[start], target, mask | (1 << start));
    dfs(start + 1, end, curr_sum - cows[start], target, mask | (1 << start));
    dfs(start + 1, end, curr_sum, target, mask);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> cows[i];
    }

    int mid = n / 2;

    dfs(0, mid, 0, left_map, 0);
    dfs(mid + 1, n - 1, 0, right_map, 0);

    unordered_set<int> result;

    for (auto const &[left_sum, left_mask_set] : left_map)
    {
        auto it = right_map.find(-left_sum);
        if (it != right_map.end())
        {
            for (int l_mask : left_mask_set)
            {
                for (int r_mask : it->second)
                {
                    int full_mask = l_mask | r_mask;
                    if (full_mask > 0)
                        result.insert(full_mask);
                }
            }
        }
    }

    cout << result.size();

    return 0;
}