#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define MAXN 1000000001

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, MIN = MAXN;
    long long cost = 0;
    cin >> N;
    vector<long long> array(N);
    vector<long long> sorted(N);
    for (int i = 0; i < N; i++)
    {
        cin >> array[i];
        sorted[i] = array[i];
        MIN = min(MIN, sorted[i]);
    }

    sort(sorted.begin(), sorted.end());

    map<int, int> position;

    for (int i = 0; i < N; i++)
    {
        position[sorted[i]] = i;
    }

    vector<bool> visited(N, false);

    for (int i = 0; i < N; i++)
    {
        if (visited[i])
            continue;
        if (position[array[i]] == i)
        {
            visited[i] = true;
            continue;
        }
        long long sum = 0;
        long long cmin = MAXN, circle_len = 0;
        long long current_pos = i;

        while (!visited[current_pos])
        {
            visited[current_pos] = true;
            long long val = array[current_pos];
            sum += val;
            cmin = min(val, cmin);
            circle_len++;

            current_pos = position[val];
        }

        long long cost1 = sum + (circle_len - 2) * cmin;
        long long cost2 = sum + cmin + (circle_len + 1) * MIN;
        cost += min(cost1, cost2);
    }

    cout << cost;

    return 0;
}

/*
小 C 有一个 N 个数的整数序列，这个序列的中的数两两不同。

小 C 每次可以交换序列中的任意两个数，代价为这两个数之和。

小 C 希望将整个序列升序排序，问小 C 需要的最小代价是多少？

*/