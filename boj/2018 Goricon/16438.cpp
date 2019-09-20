#include <iostream>
#include <algorithm>
using namespace std;

char ans[7][111];
int n,cnt;

void solve(int l,int r,int dep){
    if(l >= r || dep==7) return;
    cnt=max(cnt,dep);
    int mid = (l+r)/2;
    for(int i=l;i<=r;i++){
        if(i<=mid) ans[dep][i]='A';
        else ans[dep][i]='B';
    }
    solve(l,mid,dep+1);
    solve(mid+1,r,dep+1);
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf(" %d",&n);
    solve(1,n,0);
    for(int i=0;i<=cnt;i++){
        for(int j=1;j<=n;j++){
            if(ans[i][j]=='\0') ans[i][j] = (j%2==0) ? 'A' : 'B';
            printf("%c",ans[i][j]);
        } puts("");
    }
    while(cnt != 6){
        for(int i=0;i<n;i++){
            if(i&1) printf("A");
            else printf("B");
        } puts(""); cnt++;
    }
}