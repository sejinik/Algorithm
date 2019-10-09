#include <iostream>
#include <cstring>
using namespace std;
int q,n;
int arr[222];
 
bool r(){
    for(int i=0;i<n;i++) {
        if(arr[i] == n) continue;
        if(arr[i]+1 != arr[i+1]) return false;
    }
    return true;
}
 
bool l(){
    for(int i=0;i<n;i++){
        if(arr[i]==1) continue;
        if(arr[i]-1 != arr[i+1]) return false;
    }
    return true;
}
int main(){
    scanf(" %d",&q);
    while(q--){
        memset(arr,0,sizeof(arr));
        scanf(" %d",&n);
        for(int i=0;i<n;i++) scanf(" %d",&arr[i]);
        arr[n]=arr[0];
        if(r() || l()) puts("YES");
        else puts("NO");
    }
}