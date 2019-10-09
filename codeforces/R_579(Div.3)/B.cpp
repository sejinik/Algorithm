#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int n,q;
int arr[10010];
 
int main(){
    scanf(" %d",&q);
    while(q--){
        bool check=false;
        memset(arr,0,sizeof(arr));
        scanf(" %d",&n);
        vector<int> vt;
        for(int i=0;i<n*4;i++){
            int x; scanf(" %d",&x);
            arr[x]++;
            if(arr[x]==2) {
                vt.push_back(x); arr[x]=0;
            }
        }
        if(vt.size()&1) check=true;
        for(int i=1;i<=10000;i++){
            if(arr[i]) check=true;
        }
        if(check) {
            puts("NO"); continue;
        }
 
        sort(vt.begin(),vt.end());
        int sz=vt.size();
        int area = vt[0]*vt[sz-1];
        for(int i=1;i<sz/2;i++){
            int temp = vt[i]*vt[sz-1-i];
            if(temp != area) check=true;
        }
        if(check) puts("NO");
        else puts("YES");
    }
}