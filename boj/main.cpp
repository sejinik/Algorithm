#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
int P,n,m;
int A[1010],B[1010],PA[3010],PB[3010];
vector<int> a,b;
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d %d %d",&P,&n,&m);
    for(int i=1;i<=n;i++) scanf(" %d",&A[i]);
    for(int i=1;i<=m;i++) scanf(" %d",&B[i]);
    for(int i=1;i<=n;i++) PA[i]=PA[i-1]+A[i]; for(int i=n+1;i<=n*2;i++) PA[i]=PA[i-n]+PA[n];
    for(int i=1;i<=m;i++) PB[i]=PB[i-1]+B[i]; for(int i=m+1;i<=m*2;i++) PB[i]=PB[i-m]+PB[m];
    for(int i=1;i<=n;i++){
        for(int j=i;j<i+n-1;j++){
            a.push_back(PA[j]-PA[i-1]);
        }
    } 
    for(int i=1;i<=m;i++){
        for(int j=i;j<i+m-1;j++){   
            b.push_back(PB[j]-PB[i-1]);
        }
    }
    a.push_back(PA[n]); b.push_back(PB[m]);
    a.push_back(0); b.push_back(0);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int ans=0;
    for(int i=0;i<=P;i++){
        int c = upper_bound(a.begin(),a.end(),i) - lower_bound(a.begin(),a.end(),i);
        int w = upper_bound(b.begin(),b.end(),P-i) - lower_bound(b.begin(),b.end(),P-i);         
        if(c&&w) ans+=(c*w);
    }
    printf("%d\n",ans);
}