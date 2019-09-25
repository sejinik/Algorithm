// [0~짝수] 개의 prefix의 a,b 수가 같아야만 한다
// 따라서 2개씩 계속 a,b가 1개씩 있는지 보고 바꿔주면 된다

#include <iostream>
#include <string>
using namespace std;
int n,ans;
string s;
 
int main(){
    cin>>n>>s;
    for(int i=0;i<n;i+=2){
        if(s[i]=='a' && s[i+1]=='b') continue;
        if(s[i]=='b' && s[i+1]=='a') continue;
        if(s[i]=='a') s[i+1]='b';
        else s[i+1]='a';
        ans++;
    }
    printf("%d\n",ans);
    cout<<s;
}