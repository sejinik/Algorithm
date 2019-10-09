#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
 
int n,ans;
bool check[150010];
 
int main(){
    scanf(" %d",&n);
    vector<int> vt(n);
    for(int i=0;i<n;i++) scanf(" %d",&vt[i]);
    sort(vt.begin(),vt.end());
 
    for(int i=0;i<n;i++){
        int num = vt[i];
        int prev = num-1;
        int next = num+1;
        if(prev && !check[prev]) check[prev]=true;
        else if(!check[num]) check[num]=true;
        else if(!check[next]) check[next]=true;
    }
    int ans=0;
    for(int i=1;i<=150001;i++) 
        if(check[i]) ans++;
    printf("%d\n",ans);
}