// ? 가있다면 나와 대칭되는 곳의 문자를 보자
// 둘다 ?라면 무조건 'a'로 정하자!!

#include <iostream>
#include <string>
using namespace std;
int n;
string s;

int main() {
    cin>>n>>s;
    for(int i=0;i<n;i++){
        int next = n-i-1;
        if(s[i]=='?'){
            if(s[next]=='?') cout<<"a";
            else cout<<s[next];
        }
        else cout<<s[i];
    }
}
