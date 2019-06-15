//부분합을 이용해서 풀 수 있는 문제이다
//그냥 찾으면 시간초과이므로
//미리 1 ~ X까지의 합을 psum[X]에 담아준다
//입력을 받으며 더해가면 된다
//여기서 index를 1부터 시작하면 psum[0]을 넣고 편하게 구할 수 있다
//그리고 X~Y의 합은 psum[Y]-psum[X-1]로 구하면 된다

#include <iostream>
using namespace std;
#define ll long long
int n,m;
ll psum[100010],arr[100010];

int main(){
    //freopen("input.txt","r",stdin);
    scanf(" %d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf(" %lld",&arr[i]);
        psum[i]+=(psum[i-1]+arr[i]);
    }
    for(int i=0;i<m;i++){
        int a,b; scanf(" %d %d",&a,&b);
        printf("%lld\n",psum[b]-psum[a-1]);
    }
}