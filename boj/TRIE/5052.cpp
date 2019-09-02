#include <iostream>
using namespace std;

const int N = 10010, M = 11;
int t, n, cnt = 1;

char s[N][M];
int trie[N * M][M];
bool fin[N * M], ans;

void insert(int idx, int pos)
{
    for (int i = 0; i < M; i++)
    {
        if (s[pos][i] == '\0')
        {
            fin[idx] = true;
            return;
        }
        int curr = s[pos][i] - '0';
        if (!trie[idx][curr])
            trie[idx][curr] = cnt++;
        idx = trie[idx][curr];
    }
}

void find(int idx, int pos)
{
    for (int i = 0; i < M; i++)
    {
        if (s[pos][i] == '\0')
            return;
        if (fin[idx])
        {
            ans = true;
            return;
        }
        int curr = s[pos][i] - '0';
        idx = trie[idx][curr];
    }
}

int main()
{
    scanf(" %d", &t);
    while (t--)
    {
        for (int i = 0; i <= cnt; i++)
        {
            fin[i] = false;
            for (int j = 0; j < 11; j++)
                trie[i][j] = 0;
        }
        cnt = 1;
        scanf(" %d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf(" %s", &s[i]);
            insert(0, i);
        }
        ans = false;
        for (int i = 0; i < n; i++)
            find(0, i);
        if (ans)
            puts("NO");
        else
            puts("YES");
    }
}