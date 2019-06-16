//10^18 이면 long long으로 받을 수 있다
//z로 나눴을 때의 나머지 값을 확인하면 답을 구할 수 있다
//만약 더 살수 있다면 더사고
//최소한의 스위치 수는 z에서 나머지값들을 뺀 것의 최소값이다

#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
ll x,y,z;

int main(){
    scanf(" %lld %lld %lld",&x,&y,&z);
    ll c= ((x%z)+(y%z))/z;
    ll ans = (x/z)+(y/z);
    if(c==0){
        printf("%lld %lld\n",ans,(ll)0);
    } else {
        ans +=c;
        ll q =min(z-(x%z),z-(y%z));
        printf("%lld %lld\n",ans,q);
    }
}