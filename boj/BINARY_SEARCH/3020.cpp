//lower_bound를 이용한 문제이다
//배열에 저장하고 각 높이별로 몇개를 부수는지 바로 찾으면 된다
//이 때 배열에 정렬해서 저장한 뒤 lower_bound를 이용한다면 
//현재 지나가는 높이를 포함하는 구간을 쉽게 찾을 수 있다
//홀수 일때는 거꾸로 저장되므로 유의해서 풀면 된다!

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,h;
int ans[200020];
vector<int> odd,even;

int main(){
    //freopen("input.txt","r",stdin);
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