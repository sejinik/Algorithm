//d[N*M] 디피로 풀 수 있다
//d[pos] = 계산값 + d[pos+|d|]로 칸에서의 최댓값을 저장해보자
//이 때 최대값이 음수값이 가능하므로 inf값을 잘 설정해야한다!

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long
const int SIZE = 200005;
ll inf = 1e12;
ll d[SIZE];
ll arr[SIZE];
int n,m,k;

bool inner(int x,int y){
    return (0<=x && x<n && 0<=y && y<m);
}
ll solve(int pos) {
    if(pos>=n*m) return -inf;
    int x = pos/m;
    int y = pos%m;
    if(x==n-1) return 0;
    ll&ret = d[pos];
    if(ret != -inf) return ret;
    for(int i=x;i<=x+k;i++){
        for(int j=y-k;j<=y+k;j++){
            if(inner(i,j) && x<i && (abs(i-x)+abs(j-y)<=k)){
                ret = max(ret,arr[pos]*arr[i*m+j]+solve(i*m+j));
            }
        }
    }
    return ret;
}

int main(){
    for(int i=0;i<SIZE+1;i++) d[i]= -inf;
    scanf(" %d %d %d",&n,&m,&k);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf(" %lld",&arr[i*m+j]);
        }
    }
    ll ans=-inf;
    for(int i=0;i<m;i++) ans = max(ans,solve(i));
    printf("%lld\n",ans);
}