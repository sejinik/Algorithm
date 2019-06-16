//그리디 + 구현 문제였다
//숫자를 2개의 부분으로 나눠서 더한값의 최소값을 찾는다
//그럼 중간부터 중간 왼쪽 오른쪽 이렇게 3개의 경우로 자른걸 비교하면 된다
//숫자가 커서 문자열로 구현했는데 실수때문에 계속 틀렸다
//문자열을 볼때는 문자가 존재하는지 확인하는 습관을 들여야겠다

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n, r, l, m;
string s;

string solve(int pos) {
	if (pos == -1) return "";
	string ret = "";
	string a = s.substr(0, pos);
	string b = s.substr(pos, n - a.size());
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int sz = max(a.size(), b.size());
	int un = 0;
	for (int i = 0; i < sz; i++) {
		int an = ((i<a.size() && '0' <= a[i] && a[i] <= '9') ? a[i] - '0' : 0);
		int bn = ((i<b.size() && '0' <= b[i] && b[i] <= '9') ? b[i] - '0' : 0);
		int cn = an + bn + un;
		un = cn / 10;
		cn %= 10;
		ret += (char)(cn + '0');
	}
	if (un) ret += (char)(un + '0');
	reverse(ret.begin(), ret.end());
	return ret;
}

string smalls(string a, string b) {
	if (a == "" || (a.size() > b.size())) return b;
	if (b == "" || a.size() < b.size()) return a;
	int as = a.size();
	for (int i = 0; i < as; i++) {
		if (a[i] > b[i]) return b;
		else if (a[i] < b[i]) return a;
	}
}
int main() {
	scanf(" %d", &n);
	cin >> s;
	m = n / 2;

	for (int i = m - 1; i >= 0; i--) {
		if (s[i] != '0') {
			r = i; break;
		}
	}

	for (int i = m + 1; i < n; i++) {
		if (s[i] != '0') {
			l = i; break;
		}
	}
	if (s[m] == '0') m = -1;
	if (s[r] == '0' && r == 0) r = -1;
	if (s[l] == '0' && l == 0) l = -1;
	string ms = solve(m);
	string rs = solve(r);
	string ls = solve(l);
	string ans = smalls(ms, rs);
	ans = smalls(ans, ls);
	cout << ans;
}