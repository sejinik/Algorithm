#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define ll long long
int main(){
    //freopen("input.txt","r",stdin);
    ll n; scanf(" %lld",&n);
    priority_queue<ll> pq;
    for(int i=0;i<n;i++){
        ll x; scanf(" %lld",&x);
        pq.push(-x); 
    }
    ll ans=0;
    ll last=1;
    for(ll i=1;i<=n;i++){
        ll t = -pq.top(); pq.pop();
        if(last <=t){
            ans+=(t-last); last++;
        }
    }
    printf("%lld\n",ans);
}