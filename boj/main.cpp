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