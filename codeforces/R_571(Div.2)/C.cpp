//두개의 문자열  a,b(0,1로 이루어진)이 주어진다
// 이 때 b의 문자열과 길이가같은 a의 substring과
// b를 비교해서 다른숫자의 개수가 짝수인것의 수를 찾는 문제다
// 도무지 안떠올라서 접근법을 보니 홀짝을 비교하는 문제였다
// 먼저 c를 a의 substring 이라 할 때 b,c의 1의 수를 세어본다
// 그리고 1의수가 서로 (짝,짝),(홀,홀) 이라면 다른 문자열이 짝수개이다
// 그림을 그려보니 1이 커버해주는 경우를 그려보면 된다
// 1이 어느위치에있든 a의 1의수 + b의 1의수 가 곧 홀,짝을 결정한다
// 따라서 두개의 합이 짝수가 나오려면 무조건 (짝,짝),(홀,홀) 이여야 한다
// 증명은 어떻게 하는지 모르겠다.. 해설에도 증명은 안나와있고 정말 쉽다고 나와있다
// 덕분에 더 어렵다..!
// 문제에서 0,1로 주는 이유를 잘 생각해보자 앞으로! 

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string a,b;

int main(){
    //freopen("input.txt","r",stdin);
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