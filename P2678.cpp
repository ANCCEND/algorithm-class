#include <iostream>
#include <vector>

using namespace std;

bool count(int maxlength);

int L, M, N;
vector<int> stones;

int main()
{
    cin >> L >> N >> M;
    stones.resize(N);
    int ans;
    for (int i = 0; i < N; i++)
    {
        cin >> stones[i];
    }
    int maxlength, left = 0, right = L;
    while (left <= right)
    {
        maxlength = (left + right) / 2;
        if (count(maxlength) == false)
        {
            right = maxlength - 1;
        }
        else
        {
            ans = maxlength;
            left = maxlength + 1;
        }
    }

    cout << ans;

    return 0;
}

bool count(int maxlength)
{
    int remove = 0, position = 0, index = 0;
    while (index < N)
    {
        if (stones[index] - position < maxlength)
        {
            remove++;
        }
        else
        {
            position = stones[index];
        }
        if (remove > M)
        {
            return false;
        }

        index++;
    }
    if (L - position < maxlength) // && remove >= M)
        remove++;

    return remove<=M;
}