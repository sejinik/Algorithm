//lower_bound && upper_bound를 이용해 풀었다
//피자가 원이라는것을 생각해야한다
//원이기때문에 배열의 끝과 시작을 이어서 생각해야한다!
//연속적인 수를 모두 더해서 배열에 넣고 정렬을 시킨다
//그리고 lower&&upper을 통해 만족하는 수를 찾는다!
//A에서는 i를 B에서는 값-i를 찾으면 된다!

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