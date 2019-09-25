// 막혀서 해설을 보고 해결했다
// 1,12,123,1234~ 로 진행될 때 하나의 구간을 한 개의 블럭으로 보자
// 첫 for문 에서는 몇번째 블럭에 속하는지를 계속 합을 더해가며 구한다 upper_bound라고 생각하면 된다
// 속하는 블록을 구한 뒤에는 몇번째 수 인지 찾아보자
// 그건 합이 아닌 숫자의 길이를 빼가면서 보면 된다
// 속하는 수를 찾으면 to_string을 통해 j의 n번째 인덱스를 쉽게 출력할 수 있다

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