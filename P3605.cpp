#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100005;

//树状数组+dfs

int bit[MAX]; //记录子树中出现的次数
int n;

inline int bitlow(int index)
{
    return index & -index;
}

void update(int index)
{
    for (; index <= n; index += bitlow(index))
    {
        bit[index]++;
    }
}

int query(int index)
{
    int sum = 0;
    for (; index > 0; index -= bitlow(index))
    {
        sum += bit[index];
    }
    return sum;
}

vector<int> tree[MAX];
int p[MAX];
int rankP[MAX];
int ans[MAX];

void dfs(int index)
{
    int before = query(n) - query(rankP[index]);

    for (int it : tree[index])
    {
        dfs(it);
    }

    int after = query(n) - query(rankP[index]);
    ans[index] = after - before;
    update(rankP[index]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<int> rawP(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        rawP[i - 1] = p[i];
    }
    sort(rawP.begin(), rawP.end());

    for (int i = 1; i <= n; i++)
    {
        rankP[i] = lower_bound(rawP.begin(), rawP.end(), p[i]) - rawP.begin() + 1;
    }

    int parent;
    for (int i = 2; i <= n; i++)
    {
        cin >> parent;
        tree[parent].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}