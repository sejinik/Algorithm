//많이 헤메다가 푼 문제다
//코드포스 문제는 항상 복잡하게 생각할수록 더 어려운거같다
//최적화를 항상 생각해야하는데 잘 안떠오른다
//처음이 양수 음수 나눴는데
//잘 생각해보니 다 음수로 만들어서 넣고 전체수가 짝수/홀수 만 구별하면 된다
//어차피 여러번 바꿀 수 있으므로 음수로 다 넣고 풀면 된다

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
int n,minX=1e9;
vector<pair<int, int>> vt, M;
int main() {
    //freopen("input.txt","r",stdin);
	scanf(" %d", &n);
	for (int i = 0; i < n; i++) {
		int x; scanf(" %d", &x);
		if (x == 0) x = -1;
		if (x > 0) x = (-x - 1);
		vt.push_back({ x,i });
        minX=min(minX,x);
	}
    if(!(n&1)){
        for(int i=0;i<n;i++) printf("%d ",vt[i]);
    } else {
        bool check= false;
        for(int i=0;i<n;i++){
            if(!check && (vt[i].first==minX)){
                printf("%d ",-minX-1);
                check=true;
            }
            else printf("%d ",vt[i]);
        }
    }
}