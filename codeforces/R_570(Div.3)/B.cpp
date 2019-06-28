//배열과 수 k를 줬을 때
//[1~n]까지의 값과 차이가 k이하인 최대값b를 구하는게 문제이다
//n이 100 개이고 배열의 값은 천만 까지 들어온다
// 배열 n 개와 각 배열값에 k만큼 더한 수 n 개 =>2n개
// 2n개에 대해 조건을 만족하는지 봐주면 구할 수 있다!

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

int t;
int n,k;
int arr[111];

int main(){
    //freopen("input.txt","r",stdin);
    scanf(" %d",&t);
    while(t--){
        scanf(" %d %d",&n,&k);
        int ans=-1;
        int minn =1e9;
        int maxn = 0;
        vector<int> vt;
        for(int i=0;i<n;i++){
            scanf(" %d",&arr[i]);
            vt.push_back(arr[i]);
            vt.push_back(arr[i]+k);
        } 
        int s= vt.size();
        for(int i=0;i<s;i++){
            bool check=true;
            for(int j=0;j<n;j++){
                if(abs(arr[j]-vt[i])>k) check=false;
            }
            if(check) ans = max(ans,vt[i]);
        }
        printf("%d\n",ans);
    }
}