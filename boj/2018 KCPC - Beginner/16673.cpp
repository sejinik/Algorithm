#include <iostream>
using namespace std;
#define ll long long
int c,k,p,ans;

int main(){
    //freopen("input.txt","r",stdin);
    scanf(" %d %d %d",&c,&k,&p);
    for(int i=1;i<=c;i++){
        ans+=(k*i+p*i*i);
    }
    printf("%d\n",ans);
}