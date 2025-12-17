#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

//IDA*
using namespace std;

int target[5][5] = {
    1, 1, 1, 1, 1,
    0, 1, 1, 1, 1,
    0, 0, 2, 1, 1,
    0, 0, 0, 0, 1,
    0, 0, 0, 0, 0};
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int board[5][5];
int max_depth;
bool success;

int get_h()
{
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (board[i][j] != target[i][j])
                count++;
        }
    }
    return count;
}

void dfs(int dep, int curr_x, int curr_y, int last_x, int last_y)
{
    if (success == true)
        return;
    int h = get_h();
    if (h == 0)
    {
        success = true;
        return;
    }
    if (dep + h - 1 > max_depth)
        return;
    for (int i = 0; i < 8; i++)
    {
        int x = curr_x + dx[i], y = curr_y + dy[i];
        if (x == last_x && y == last_y || x >= 5 || x < 0 || y >= 5 || y < 0)
            continue;
        swap(board[curr_x][curr_y], board[x][y]);
        dfs(dep + 1, x, y, curr_x, curr_y);
        if (success)
            return;
        swap(board[curr_x][curr_y], board[x][y]);
    }
}

void ida()
{
    int start_x, start_y;
    string s;
    for (int i = 0; i < 5; i++)
    {
        cin >> s;
        for (int j = 0; j < 5; j++)
        {
            if (s[j] == '*')
            {
                board[i][j] = 2;
                start_x = i;
                start_y = j;
            }
            else
                board[i][j] = s[j] - '0';
        }
    }
    success = false;
    for (max_depth = 0; max_depth <= 15; max_depth++)
    {
        dfs(0, start_x, start_y, -1, -1);
        if (success)
        {
            cout << max_depth << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ida();
    }

    return 0;
}