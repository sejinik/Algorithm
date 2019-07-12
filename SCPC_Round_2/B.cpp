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
ll psum[5050];
ll d[5050][5050];
int A[5050], B[5050];
int n, t;

int main() {
	scanf(" %d", &t);
	int c = 1;
	while (t--) {
		scanf(" %d", &n);
		memset(d, 0, sizeof(d));
		memset(psum, 0, sizeof(psum));
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		for (int i = 1; i <= n; i++) scanf(" %d", &A[i]);
		for (int i = 1; i <= n; i++) scanf(" %d", &B[i]);
		psum[1] = (ll)(A[1] == B[1]);
		for (int i = 2; i <= n; i++) psum[i] = psum[i - 1] + (ll)(A[i] == B[i]);		
		ll ans = psum[n];
		for (int i = 1; i < n; i++) {
			d[i][i] = psum[n];
			d[i][i+1] = psum[i - 1] + (psum[n - 1] - psum[i+1]) + (ll)(A[i] == B[i+1]) + (ll)(A[i+1] == B[i]);
			ans = max(ans, d[i][i + 1]);
		}
		d[n][n] = psum[n];
		
		for (int i = n - 1; i >= 1; i--) {
			for (int j = i + 1; j <= n; j++) {
				if (d[i][j] != 0) continue;
				d[i][j]=d[i+1][j-1] + (ll)(A[i] == B[j]) + (ll)(A[j] == B[i]) - (ll)(A[i] == B[i]) - (ll)(A[j] == B[j]);
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				ans = max(ans, d[i][j]);
			}
		}
		printf("Case #%d\n", c++);
		printf("%lld\n", ans);
	}
}