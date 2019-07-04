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
            if(!check && (vt[i].first==maxN)){
                printf("%d ",-maxN-1);
                check=true;
            }
            else printf("%d ",vt[i]);
        }
    }
}