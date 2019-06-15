//페르마의 소정리를 이용한 문제
//nCk % 1e9+7을 문제에서 구해야한다
//nCk = (n!)/(k!)*(n-k)! 인데 여기서 그냥 mod를 하면 나눗셈 때문에 답이 안나온다
//그래서 페르마의 소정리를 이용해 역원을 이용해야 한다
//페르마의 소정리에서 p가 소수일 떄 a^p=a(mod p) 이다
//그럼 양변을 a로 나누면 a^(p-1)=1 (mod p) 이다
//이걸 정리해서 a*(a^(p-2))=1 (mod p) 로 쓸 수 있으므로
//a의 역원은 a^(p-2)이다!!
//그럼 우리가 구하려는 n!/k!*(n-k)!에서 n!=a,k!*(n-k)!=b로 두자
//a/b => a/b*(b*b의역원) 이므로 a*b의 역원을 구하고 mod를 때리면 답이다!
//a는 n!, b는 (k!*(n-k)!) 이므로 구하면 된다!
//pow를 할 때는 시간초과를 피하기 위해 log만에 하는 함수를 만들었다!
// a^b에서 b가 홀수라면 a*a^(b-1)로 
// b가 짝수라면 (a*a)^(b/2)로 만들어서 게속 반씩 나눠가면 빠르게 구할 수 있다!
 

#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
ll mod = 1e9+7;
ll n,k,a=1,b=1;

ll mypow(ll x, ll y){
    if(!y) return 1;
    if(y&1) return (mypow(x,y-1)*x%mod)%mod;
    return mypow((x*x)%mod,y/2)%mod;
}

int main(){
    scanf(" %lld %lld",&n,&k);
    for(int i=1;i<=n;i++) {
        a*=(ll)i;
        a%=mod;
    }
    for(int i=1;i<=k;i++){
        b*=(ll)i;
        b%=mod;
    }
    for(int i=1;i<=(n-k);i++){
        b*=(ll)i;
        b%=mod;
    }
    ll c = mypow(b,mod-2);
    ll ans = a*c;
    ans%=mod;
    printf("%lld\n",ans);
}