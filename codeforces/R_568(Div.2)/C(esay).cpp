// 부분합을 미리 구해둔다
// 부분합이 M보다 크다면 앞의 수들 중에서 큰 수부터 빼준다

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m;
int vt[111],psum[111],arr[111];
int main(){
    //freopen("input.txt","r",stdin);
    scanf(" %d %d",&n, &m);
    for(int i=1;i<=n;i++){
        scanf(" %d",&vt[i]);
        arr[i-1]=vt[i];
        psum[i] = psum[i-1] + vt[i];
    } 
    
    for(int i=1;i<=n;i++){
        if(psum[i] <=m) printf("0 ");
        else{
            int c = psum[i]-m;
            int cnt=0,sum=0;
            sort(arr,arr+i-1);
            for(int j=i-2;j>=0;j--){
                cnt++; sum+=arr[j];
                if(c<=sum) break;
            }
            printf("%d ",cnt);
        }
    }
}