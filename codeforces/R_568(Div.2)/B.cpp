//구현 문제
//더럽게 구현했지만 a 와 b의 알파벳을 순서대로 보면된다
//한번 본 알파벳은 같은게 안나올때까지 뒤로 쭉 삭제한다
//a와 b는 항상 같아야하고 a의 알파벳수보다 b의알파벳수가 같거나 커야한다
//그리고 항상 같은 알파벳이 나와야한다


#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n;
string a,b;
int main(){
    //freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        int sz = a.size();
        int k=0;
        bool check=true;
        for(int j=0;j<sz;j++,k++){
            if(a[j] != b[k]) {
                check=false; break;
            }
            int acnt=0,bcnt=0;
            while(a[j+1] && (a[j]==a[j+1])) j++,acnt++;
            while(b[k+1] && (b[k]==b[k+1])) k++,bcnt++;
            if(acnt>bcnt) {
                check=false; break;
            }
        }
        if(b[k]) check=false;
        if(check) puts("YES");
        else puts("NO");
    }
}