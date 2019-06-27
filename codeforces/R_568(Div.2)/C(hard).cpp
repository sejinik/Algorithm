//easy버전에서 N과M이 늘어나고 ti는 100까지 들어온다
//N과 M이 커져서 pq,세그트리를 생각하고 ti가 100인건 신경을 안썼다
//하지만 ti가 100이므로 이전 학생의 시간이 얼마인지 알고있으면 완전탐색으로 쉽게 구할 수 있다
//각각의 값들이 들어오는 범위를 잘 확인하자! 작게들어오면 작게들어오는 이유를 생각해보자!

#include <iostream>
#include <algorithm>
using namespace std;
int cnt[111],psum[200020];
int n,m,t;

int main(){
    //freopen("input.txt","r",stdin);
    scanf(" %d %d",&n,&m);
    for(int i=1;i<=n;i++){
        int x; scanf(" %d",&x);
        psum[i] = x+t;
        t=psum[i];
    }
    for(int i=1;i<=n;i++){
        if(psum[i]<=m) printf("0 ");
        else{
            int c = psum[i]-m;
            int ans=0;
            for(int j=100;j>=1;j--){
                if(!cnt[j]) continue;
                if(c<=cnt[j]*j){
                    ans+=(c/j);
                    if(c%j!=0) ans++; break;
                } else {
                    ans+=cnt[j];
                    c-=cnt[j]*j;
                }
            }
            printf("%d ",ans);
        }
        cnt[psum[i]-psum[i-1]]++;
    }
}