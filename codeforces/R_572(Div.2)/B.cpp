//n+2 크기의 배열을 만들어주고 입력받은 배열을 정렬시켜준다
//그 후 배열을 앞 뒤 앞 뒤로 채워준다 => [0,2,4,5,3,1] 이런식으로
//맨앞에는 마지막수 마지막은 맨앞수를 넣고 체크해본다
//맞으면 YES 아니면 NO

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
 
int main() {
	int n; vector<int> vt;
	scanf(" %d", &n);
	vt.resize(n);
	for (int i = 0; i < n; i++) scanf(" %d", &vt[i]);
	sort(vt.begin(), vt.end());
	vector<int> ans(n + 2);
	ans[0] = vt[n - 1];
	ans[n + 1] = vt[0];
	deque<int> f, s;
	for (int i = 0; i < n; i++) {
		if (!(i & 1)) f.push_back(vt[i]);
		else s.push_front(vt[i]);
	}
	int index = 1;
 
	while (!f.empty()) {
		int pos = f.front(); ans[index++] = pos;
		f.pop_front();
	}
	while (!s.empty()) {
		int pos = s.front(); ans[index++] = pos;
		s.pop_front();
	}
	bool check = true;
	for (int i = 1; i <=n; i++) {
		int sum = ans[i - 1] + ans[i + 1];
		if (sum <= ans[i]) {
			check = false; break;
		}
	}
	if (!check) puts("NO");
	else {
		puts("YES");
		for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	}
}