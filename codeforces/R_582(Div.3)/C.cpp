#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
int q;
vector<vector<int>> vt(11);
int main(){
    for(int i=0;i<=10;i++){
        vt[i].push_back(i%10);
        for(int j=2;;j++){
            if(vt[i][0] != (i*j)%10) vt[i].push_back((i*j%10));
            else break;
        }
    }
    scanf(" %d",&q);
    while(q--){
        ll n,m,sum=0;
        scanf(" %lld %lld",&n,&m); 
        ll cnt = n/m; m%=10;
        ll mul = cnt/vt[m].size();
        ll mod = cnt%vt[m].size();
        for(int i=0; i< vt[m].size();i++) sum+=vt[m][i];
        sum*=mul;
        for(int i=0;i<mod;i++) sum+=vt[m][i];
        printf("%lld\n",sum);
    }
}