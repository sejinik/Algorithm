//자료구조 deque에 관한 문제이다
//앞에 수를 AB라 할 때 큰수는 남고 작은수는 맨 뒤로 보낸다
//그 때 쿼리가 날라오고 쿼리가 n일때 n번째 순서에서 AB를 출력하면 된다
//쿼리가 10^18 까지 들어오니까 규칙을 찾으면 된다
//가장 큰수가 맨앞에오면 그 다음부터는 그냥 순서대로 일정하게 뒤의 수가 차례대로 나온다
//가장 큰수가 앞에올 경우까지 시물레이션을 돌리자
//그 값을 d에 저장하고
//가장 큰수를 제외한 나머지수를 차례대로 dp 에 저장하자
//쿼리 q가 들어왔을때 가장큰수를 찾을 때 까지 index보다 작으면 d에서
//크면 q-=index , q%=(n-1)을 해서 dp에서 값을 찾아주자
//계속 순환하므로 답이 나온다!

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
int n, q,maxN=-1;
int pos;
vector<int> vt;
pair<int, int> d[100010];
int dp[100010];
deque<int> dq;
int main() {
	scanf(" %d %d", &n, &q);
	vt.resize(n);
	for (int i = 0; i < n; i++) {
		scanf(" %d", &vt[i]);
		maxN = max(maxN, vt[i]);
		dq.push_back(vt[i]);
	}
	int cnt = 0;
	while (!dq.empty()) {
		int a = dq.front();
		dq.pop_front();
		int b = dq.front();
		dq.pop_front();
		d[cnt].first = a;
		d[cnt++].second = b;
		int f = max(a, b);
		int s = min(a, b);
		dq.push_front(f);
		dq.push_back(s);
		if (f == maxN) break;
	}
	int A = dq.front();
	dq.pop_front();
	int qcnt = 0;
	while (!dq.empty()) {
		int pos = dq.front();
		dq.pop_front();
		dp[qcnt++] = pos;
	}
	for (int i = 0; i < q; i++) {
		ll x; scanf(" %lld", &x);
		x--;
		if (x < cnt) printf("%d %d\n", d[x].first, d[x].second);
		else {
			x -= (ll)cnt;
			x %= (ll)(n - 1);
			printf("%d %d\n", maxN, dp[x]);
		}
	}
}