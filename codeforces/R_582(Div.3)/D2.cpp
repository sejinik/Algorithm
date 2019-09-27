#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,k,arr[200020],ans=1e9;
vector<vector<int>> vt(200010);
int main(){
    scanf(" %d %d",&n,&k);
    for(int i=0;i<n;i++) scanf(" %d",&arr[i]);
    for(int i=0;i<n;i++){
        int x = arr[i];
        int pos=0;
        while(x>0){
            vt[x].push_back(pos);
            x/=2; pos++;
        }
    }
    for(int i=0;i<=200000;i++){
        if(vt[i].size()<k) continue;
        sort(vt[i].begin(),vt[i].end());
        int sum=0;
        for(int j=0;j<k;j++) sum+=vt[i][j];
        ans = min(ans,sum);
    }
    printf("%d\n",ans);
}