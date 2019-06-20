//좌우로 무한으로 갈 수 있으므로
//간격을 변수에 넣고 하나씩 비교해보고 출력한다

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long 
ll a,b,c,d;
vector<ll> vt(3);
int main(){
    //freopen("input.txt","r",stdin);
    for(int i=0;i<3;i++) scanf(" %lld",&vt[i]);
    scanf(" %lld",&d);
    sort(vt.begin(),vt.end());
    ll r = vt[2]-vt[1];
    ll l =vt[1]-vt[0];
    if(r>=d && l>=d) puts("0");
    else if(r>=d && l<d) printf("%lld\n",abs(d-l));
    else if(r<d && l>=d) printf("%lld\n",abs(d-r));
    else printf("%lld\n",abs(r-d)+abs(l-d));
}