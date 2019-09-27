#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int arr[150050];
int main(){
    int t; scanf(" %d",&t);
    while(t--){
        memset(arr,0,sizeof(arr));
        int n; scanf(" %d",&n);
        for(int i=0;i<n;i++) scanf(" %d",&arr[i]);
        int minn = arr[n-1],ans=0;
        for(int i=n-2;i>=0;i--){
            if(arr[i]>minn) ans++;
            else minn= arr[i];
        }
        printf("%d\n",ans);
    }
}