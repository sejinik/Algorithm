// 분모 분자가 계속 바뀌기 때문에
// 덧셈을 해주고 swap으로 계속 바꿔보자


#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
ll n;
ll arr[22];
int main(){
    scanf(" %lld",&n);
    for(int i=0;i<n;i++) scanf(" %lld",&arr[i]);
    ll a=1,b=arr[n-1];
    for(int i=n-2;i>=0;i--){
        a+=b*arr[i];
        swap(a,b);
    }
    printf("%lld %lld\n",b-a,b);
}