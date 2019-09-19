#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, r, c;
int dx[4] = {-1, -1, 1, 1};
int dy[4] = {1, -1, 1, -1};
int arr[111][111];

bool inner(int x, int y)
{
    return (1 <= x && x <= n && 1 <= y && y <= n);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf(" %d %d %d", &n, &r, &c);
    arr[r][c] = 1;
    queue<pair<int, int>> q;
    q.push({r, c});
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (inner(nx, ny) && !arr[nx][ny])
            {
                arr[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (arr[i][j])
                printf("v");
            else
                printf(".");
        }
        puts("");
    }
}