#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int arr[1111][11];
bool check[1111][11];
int ans[1111];

bool solve(int pos,int prev){
    if(pos==n-1){
        for(int i=1;i<10;i++){
            if(i==prev) continue;
            if(arr[pos][i]){
                ans[pos]=i;
                return true;
            }
        }
    }
    for(int i=1;i<10;i++){
        if(i==prev) continue;
        if(arr[pos][i] && !check[pos+1][i]){
            check[pos+1][i]=true;
            ans[pos]=i;
            if(solve(pos+1,i)) return true;
        }
    }
    return false;
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf(" %d",&n);
    for(int i=0;i<n;i++){
        int k; scanf(" %d",&k);
        for(int j=0;j<k;j++){
            int a; scanf(" %d",&a);
            arr[i][a]=1;
        }
    }
    if(solve(0,0)){
        for(int i=0;i<n;i++) printf("%d\n",ans[i]);
    } else puts("-1");
}