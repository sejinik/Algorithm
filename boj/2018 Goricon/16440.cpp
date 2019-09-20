#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
string s;

int main(){
    //freopen("input.txt","r",stdin);
    cin>>n>>s;
    int cnt=0;
    for(int i=0;i<n/2;i++)
        if(s[i]=='s') cnt++;
    if(cnt==n/4){
        puts("1"); printf("%d\n",n/2);
    }
    else {
        for(int i=n/2;i<n;i++){
            if(s[i]=='s') cnt++;
            if(s[i-n/2]=='s') cnt--;
            if(cnt==n/4){
                puts("2");
                printf("%d %d\n",i-n/2+1,i+1);
                break;
            }
        }
    }
}