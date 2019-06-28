#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string a,b;

int main(){
    freopen("input.txt","r",stdin);
    cin>>a>>b;
    int n = a.size();
    int m = b.size();
    int ans=0;
    int bcnt=0;
    for(int i=0;i<m;i++) bcnt+=(b[i]=='1');
    int last=0;
    int acnt=0;
    for(int i=0;i<n;i++){
        if(i-last+1==m) {
            if(a[i]=='1') acnt++;
            ans += (acnt%2==bcnt%2);
            if(a[last]=='1') acnt--;
            last++;
        } else{
            if(a[i]=='1') acnt++;
        }
    }
    printf("%d\n",ans);
}