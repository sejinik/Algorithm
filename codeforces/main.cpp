#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int q,n;
int main(){   
    freopen("input.txt","r",stdin);
    scanf(" %d",&q);
    while(q--){
        scanf(" %d",&n);
        vector<int> vt(n+1);
        for(int i=0;i<n;i++){
            int x; scanf(" %d",&x);
            vt[x]++; 
        }
        sort(vt.begin(),vt.end());
        reverse(vt.begin(),vt.end());
        int ans= vt[0];
        int last = vt[0];
        for(int i=1;i<=n;i++){
            if(vt[i]>=last){
                ans+=last-1;
                last--;
            } else {
                ans += vt[i];
                last =vt[i];
            }
            if(last<=1) break;
        }
        printf("%d\n",ans);
    }
}