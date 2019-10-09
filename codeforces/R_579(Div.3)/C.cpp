#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
int n;
vector<ll> vt,num;
 
void solve(ll x){
    for(ll i=1; i*i<=x;i++){
        if(x%i==0){
            num.push_back(i);
            num.push_back(x/i);
        }
    }
}
 
int main(){
    scanf(" %d",&n);
    for(int i=0;i<n;i++){
        ll x; scanf(" %lld",&x);
        vt.push_back(x);
    }
    sort(vt.begin(),vt.end());
    vt.erase(unique(vt.begin(),vt.end()),vt.end());
    solve(vt[0]);
 
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
 
    int vsz = vt.size();
    int nsz = num.size();
    int ans=0;
    for(int i=0;i<nsz;i++){
        bool check=true;
        for(int j=0;j<vsz;j++){
            if(vt[j] % num[i] != 0){
                check=false; break;
            }
        }
        if(check) ans++;
    }
    printf("%d\n",ans);
}