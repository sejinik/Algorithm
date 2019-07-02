#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n,m;
vector<pair<int,int>> DOWN;
int arr[1010];

int main(){
    freopen("input.txt","r",stdin);
    memset(arr,-1,sizeof(arr));
    scanf(" %d  %d",&n,&m);

    for(int i=0;i<m;i++){
        int a,b,c; scanf(" %d %d %d",&a,&b,&c);
        if(!a) DOWN.push_back({b,c});
        else {
            for(int j=b+1;j<=c;j++) arr[j]=0;
        }
    }

    arr[1]=10000;
    for(int i=1;i<n;i++) arr[i+1]+=arr[i];

    for(int i=0;i<DOWN.size();i++){
        int l=DOWN[i].first;
        int r=DOWN[i].second;
        bool check= false;
        for(int j=l;j<=r;j++){
            if(arr[l]>arr[r]) check=true;
        }
        if(!check){
            puts("NO"); return 0;
        }
    }
    puts("YES");
    for(int i=1;i<=n;i++) printf("%d ",arr[i]);
}