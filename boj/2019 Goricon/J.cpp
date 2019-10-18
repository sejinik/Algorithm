// 내가 i번 인덱스에 둔다는 것은 n-i개의 반전을 가질 수 있다는 말이다
// 물론 큰 수부터 둬야만 가능하다
// 시작점을 s 끝점을 e로 잡고
// 인덱스를 돌아가며 n-i개의 반전이 필요하면 e에있는 것을 놔주고
// 필요없다면 s에 있는것을 둔다
// 다 하고 k!=0 || s<=e라면 배열을 봤는데 만족못하거나
// 다 못본것이므로 -1

#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
ll n,k;
int ans[314166];

int main(){
    scanf(" %lld %lld",&n,&k);
    int s=1,e=n;
    for(ll i=1;i<=n;i++){
        if(k>=n-i){
            k-=(n-i);
            ans[i] = e--;
        } else ans[i]=s++;
    }
    if((k!=0) || (s<=e)) puts("-1");
    else for(int i=1;i<=n;i++) printf("%d ",ans[i]);
}