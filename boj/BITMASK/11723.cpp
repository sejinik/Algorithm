//비트마스크 연습문제
//string + cin 썼다가 시간초과 났다
//비트연산 &,|,^,~ 을 연습할 수 있는 문제

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n,ans;
char s[11];
int main(){
    //freopen("input.txt","r",stdin);
    scanf(" %d",&n);
    while(n--){
        scanf(" %s",&s);
        int x;
        if(s[0]=='a' && s[1]=='d'){
            scanf(" %d",&x);
            ans|=(1<<x);
        } else if(s[0]=='r'){
            scanf(" %d",&x);
            ans&=~(1<<x);
        } else if(s[0]=='c'){
            scanf(" %d",&x);
            printf("%d\n",ans&(1<<x) ? 1 : 0);
        } else if(s[0]=='t'){
            scanf(" %d",&x);
            ans^=(1<<x);
        } else if(s[0]=='a') {
            ans = (1<<21)-1;
        } else {
            ans=0;
        }
    }
}