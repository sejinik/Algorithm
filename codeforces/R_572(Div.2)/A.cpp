// n이 100이라서 끝까지 다봤다
// 마지막자리를 보고 수가 같으면 마지막자리 앞까지 다시본다

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
string s;
vector<string> ans;
int main() {
	int n; scanf(" %d", &n);
	cin >> s;
 
	for (int i = 0; i < n; i++) {
		string temp = s.substr(0, n - i);
		int one = 0, zero = 0;
		for (int j = 0; j < temp.size(); j++) {
			if (s[j] == '0') one++;
			else zero++;
		}
		if (one != zero) {
			ans.push_back(temp);
			i = n - i;
		}
		else {
			temp = temp[temp.size() - 1];
			ans.push_back(temp);
		}
	}
	printf("%d\n", ans.size());
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";