//BFS를 이용한 문제이다
//층의 개념을 가져온다고 생각하자 dist[x][y][층]
//벽을 부실때마다 한층 씩 올라간다고 가정한다
//목적지에서 min(dist[x][y][0~1층])이 답이된다
//갈 수 없는 경우는 구해서 처리해주자!

//다익스트라로 된다고 착각하고 열심히 틀렸다
//0은 가중치1 , 1은 가중치 백만을 주고 마지막에 백만으로 나누고 나머지 구했다 굿
//다익스트라로 풀면 한개 부수고 최단거리인 경우를 못찾는다
//(1개부수고 최단거리) 대신에 (안부수고 더 긴거리)를 택한다

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, m, map[1010][1010],dist[1010][1010][2];
bool check[1010][1010][2];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int main() {
	scanf(" %d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %1d", &map[i][j]);
		}
	}
	queue<pair<pair<int, int>, int>> q;
	q.push({ {0,0},0 });
	check[0][0][0] = true;
	dist[0][0][0] = 1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (cnt == 0) {
					if (!check[nx][ny][map[nx][ny]]) {
						check[nx][ny][map[nx][ny]] = true;
						dist[nx][ny][map[nx][ny]] = dist[x][y][0] + 1;
						q.push({ {nx,ny},map[nx][ny] });
					}
				}
				else {
					if (!map[nx][ny] && !check[nx][ny][1]) {
						check[nx][ny][1] = true;
						dist[nx][ny][1] = dist[x][y][1] + 1;
						q.push({ {nx,ny},1 });
					}
				}
			}
		}
	}
	int a = dist[n - 1][m - 1][0];
	int b = dist[n - 1][m - 1][1];
	if (a == 0 && b == 0) puts("-1");
	else if (a == 0 && b != 0) printf("%d\n", b);
	else if (a != 0 && b == 0) printf("%d\n", a);
	else printf("%d\n", min(a, b));
}