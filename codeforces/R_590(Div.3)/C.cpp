//12,3456 경우를 나눠서 그래프를 그려보자
//그 후 그래프를 타고들어가며 목적지에 도착 가능한지 확인하자

#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int q,n;
string u,d;
bool check[400040];
int arr[400040];
void dfs(int x){
    check[x]=true;
    int next = arr[x];
    if(!check[next]) dfs(next);
}
int main(){
    scanf(" %d",&q);
    while(q--){
        memset(check,0,sizeof(check));
        memset(arr,0,sizeof(arr));
        scanf(" %d",&n);
        cin>>u>>d;
        for(int i=0;i<n;i++){
            int un = u[i]-'0';
            int dn = d[i]-'0';
            if(un<=2){
                arr[i] = i+1;
                if(dn<=2) arr[i+n+1]=(i+n+2);
            } else {
                if(dn<=2) arr[i+n+1]=(i+n+2);
                else {
                    arr[i]=(i+n+2);
                    arr[i+n+1]=(i+1);
                }
            }
        }
        dfs(0);
        if(check[2*n+1]) puts("YES");
        else puts("NO");
    }
}