#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define ll long long

int main(){
    int q; scanf(" %d",&q);
    while(q--){
        ll n; scanf(" %lld",&n); n--;
        ll pos=1,cnt=0,lastBlock=0;
        for(int i=1;;i++){
            if(i==pos){
                cnt++; pos*=10;
            }
            lastBlock+=cnt;
            if(n >=lastBlock) n-=lastBlock;
            else {
                ll jpos=1,jcnt=0;
                for(int j=1;j<=i;j++){
                    if(j==jpos){
                        jcnt++; jpos*=10;
                    }
                    if(n>=jcnt) n-=jcnt;
                    else {
                        cout<<to_string(j)[n]<<"\n";
                        break;
                    }
                }
                break;
            }
        }
    }
}