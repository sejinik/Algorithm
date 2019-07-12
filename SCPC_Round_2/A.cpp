#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;
#define ll long long
int t,pcnt,n,m;
bool check[30030];
int prime[4000];
int point[30030];
bool bcheck[4040];
int Index[30030];
vector<vector<int>> Graph;

void p() {
	check[0] = true;
	check[1] = true;
	for (int i = 2; i < 30000; i++) {
		if (!check[i]) {
			Index[i] = pcnt;
			prime[pcnt++] = i;
			for (int j = i * 2; j < 30000; j += i) check[j] = true;
		}
	}
}


bool numCheck(int x) {
	vector<int> c;
	int _x = prime[x];
	while (_x) {
		c.push_back(_x % 10);
		_x /= 10;
	}	
	reverse(c.begin(), c.end());
	int sz = c.size();
	for (int i = 0; i < sz; i++) {
		int temp = 0;
		for (int j = 0; j < sz; j++) {
			if (i == j) continue;
			temp *= 10;
			temp += c[j];
		}
		if (!check[temp]) {
			Graph[x].push_back(Index[temp]);
		}
	}
	return false;
}
int bfs(int x) {
	memset(bcheck, 0, sizeof(bcheck));
	int ret = 0;
	queue<int> q;
	q.push(x);
	bcheck[x] = true;
	while (int a = q.size()) {
		while (a--) {
			int pos = q.front();
			q.pop();
			for (int i = 0; i < Graph[pos].size(); i++) {
				int next = Graph[pos][i];
				if (!bcheck[next]) {
					bcheck[next] = true;
					q.push(next);
				}
			}
		}
		ret++;
	}
	return ret;
}
bool zcheck(int x) {
	vector<int> a;
	int _x = x;
	while (_x) {
		a.push_back(_x % 10);
		_x /= 10;
	}
	int as = a.size();
	for (int i = 0; i < as; i++) {
		if (a[i] == 0) return false;
	}
	return true;
}
void makeGraph() {
	p();
	Graph.resize(pcnt);
	for (int i = 0; i < pcnt; i++) numCheck(i);
	for (int i = 0; i < pcnt; i++) {
		if(zcheck(prime[i])) point[prime[i]] = bfs(i);
	}
}
int main() {
	makeGraph();
	scanf(" %d", &t);
	int c = 1;
	while (t--) {
		scanf(" %d %d", &n, &m);
		printf("Case #%d\n", c++);
		if (point[n] > point[m]) puts("1");
		else if (point[n] == point[m]) puts("3");
		else puts("2");
	}
}