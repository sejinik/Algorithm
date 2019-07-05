//가장쉬운 문제였는데 왜 못풀었을까
//[a~b] 까지 %10을 하고 계속 더하므로 결국 다더하고 %10하는것과 같다
//그냥 부분합으로 구해두고 /10이 결국 답이된다
//문제를 크게봤어야했는데 너무 작은것만 생각했다

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
int n, m;
int arr[100010], psum[100010];
int main() {
	scanf(" %d", &n);
	for (int i = 1; i <= n; i++) {
		scanf(" %d", &arr[i]);
		psum[i] = psum[i - 1] + arr[i];
	}
	scanf(" %d", &m);
	for (int i = 0; i < m; i++) {
		int a, b; scanf(" %d %d", &a, &b);
		printf("%d\n", (psum[b] - psum[a-1]) / 10);
	}
}