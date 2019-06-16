#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,h;
int ans[200020];
vector<int> odd,even;

int main(){
    freopen("input.txt","r",stdin);
    scanf(" %d %d",&n,&h);
    for(int i=0;i<n;i++){
        int x; scanf(" %d",&x); x--;
        if(i&1) odd.push_back(x);
        else even.push_back(x);
    }
    sort(odd.begin(),odd.end());
    sort(even.begin(),even.end());
    h--;
    int es = even.size();
    int os = odd.size();
    for(int i=0;i<=h;i++){
        int a = es-(lower_bound(even.begin(),even.end(),i)-even.begin());
        int b = os-(lower_bound(odd.begin(),odd.end(),h-i)-odd.begin());
        ans[a+b]++;
    }
    for(int i=0;i<=n;i++){
        if(ans[i]){
            printf("%d %d\n",i,ans[i]); return 0;
        }
    }
}