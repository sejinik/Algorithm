#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int arr[1111][1111];
int db[1111][1111];
int dd[1111][1111];
int br, bc, dr, dc, jr, jc;
bool check[1111][1111];
int bdx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int bdy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int ddx[4] = {0, 0, -1, 1};
int ddy[4] = {1, -1, 0, 0};

bool inner(int x, int y)
{
    return (1 <= x && x <= 1000 && 1 <= y && y <= 1000);
}

void bfs(int _x, int _y, char a)
{
    memset(check, 0, sizeof(check));
    queue<pair<int, int>> q;
    q.push({_x, _y});
    check[_x][_y] = 0;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (a == 'b')
        {
            for (int i = 0; i < 8; i++)
            {
                int nx = x + bdx[i];
                int ny = y + bdy[i];
                if (inner(nx, ny) && !check[nx][ny])
                {
                    check[nx][ny] = true;
                    db[nx][ny] = db[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        else
        {
            for (int i = 0; i < 4; i++)
            {
                int nx = x + ddx[i];
                int ny = y + ddy[i];
                if (inner(nx, ny) && !check[nx][ny])
                {
                    check[nx][ny] = true;
                    dd[nx][ny] = dd[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf(" %d %d %d %d %d %d", &br, &bc, &dr, &dc, &jr, &jc);
    bfs(br, bc, 'b');
    bfs(dr, dc, 'd');
    if (db[jr][jc] > dd[jr][jc])
        puts("daisy");
    else if (db[jr][jc] < dd[jr][jc])
        puts("bessie");
    else
        puts("tie");
}