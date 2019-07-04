//규칙찾는문제
//도형을보면 규칙이 보이므로 그냥 보고풀면된다

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
int n;
int d[111];
int main() {
	scanf(" %d", &n);
	d[1] = (ll)1;
	for (int i = 2; i <= 100; i++) {
		d[i] =d[i-1]+ (i * 2) + ((i - 2) * 2);
	}
	printf("%d\n", d[n]);
}