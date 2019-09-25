// 수식을 계산하면 y는 전체에서 남은 검들의 최대공약수이다
// 그래서 남은 검들 중 가장 작은수의 공약수를 다 구하고
// 그 수들을 이용해 최대공약수를 구해 답을 찾았다.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
ll n,cnt,sum,y=1;
vector<ll> fvt;
bool isPrime(ll x){
    if(x<=1) return false;
    if(x==2) return true;
    if(x%2==0) return false;
    for(ll i=3;i*i<=x;i+=2){
        if(x%i==0) return false;
    }
    return true;
}
 
void _find(ll x){
    if(isPrime(x)) {
        fvt.push_back(x); return;
    }
    if(x%2==0){
        fvt.push_back(2);
        _find(x/2); return;
    }
    for(int i=3;i*i<=x;i+=2){
        if(x%i==0){
            fvt.push_back(i);
            _find(x/i); return;
        }
    }
}
 
int main(){
    scanf(" %lld",&n);
    vector<ll> vt(n),num;
    for(int i=0;i<n;i++) {
        scanf(" %lld",&vt[i]);
        cnt = max(cnt,vt[i]);
    }
 
    for(int i=0;i<n;i++) {
        int temp = cnt-vt[i];
        if(!temp) continue;
        num.push_back(temp);
        sum+=temp;
    }
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    fvt.push_back(1);
    _find(num[0]);
    int fvtsize = fvt.size();
    int numsize = num.size();
    sort(fvt.begin(),fvt.end());
    for(int i=0;i<fvtsize;i++){
        bool check = true;
        for(int j=0;j<numsize;j++){
            if(num[j]%fvt[i] != 0) {
                check=false; break;
            }
        }
        if(check) {
            for(int k=0;k<numsize;k++) num[k]/=fvt[i];
            y*=fvt[i];
        }
    }
    printf("%lld %lld\n",sum/y,y);
}