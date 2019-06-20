#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m,ans,p;
vector<int> vt;
int main(){
    //freopen("input.txt","r",stdin);
    scanf(" %d %d",&n,&m);
    vt.resize(m);
    for(int i=0;i<m;i++) {
        int x; scanf(" %d",&x);
        vt[i]=x;
    }
    ans = max(vt[0],n-vt[m-1]);
    for(int i=1;i<m-1;i++){
        int r =vt[i+1]-vt[i];
        int a = (r+1)/2;
        ans = max(ans,a);
    }
    printf("%d\n",ans);
}