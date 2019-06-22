//그리디 문제
//우선수위큐를 이용하면 쉽게 풀 수 있다
//최소값2개를 계속 더해가면 된다
//pq는 최대힙이기 때문에 -를 붙여서 저장해 최소값을 계속 찾아준다

#include <iostream>
#include <queue>
using namespace std;
#define ll long long
int n,m;
priority_queue<ll> pq;

int main(){
    //freopen("input.txt","r",stdin);
    scanf(" %d %d",&n,&m);
    for(int i=0;i<n;i++){
        ll x; scanf(" %lld",&x);
        pq.push(-x);
    }
    while(m--){
        ll a = -pq.top();
        pq.pop();
        ll b = -pq.top();
        pq.pop();
        pq.push(-(a+b));
        pq.push(-(a+b));
    }
    ll ans=0;
    while(!pq.empty()){
        ans+=-pq.top();pq.pop();
    }
    printf("%lld\n",ans);
}