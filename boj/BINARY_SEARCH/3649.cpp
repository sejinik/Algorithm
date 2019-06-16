//이분탐색으로 풀리는 문제이다
//그냥 mid 값을 찾는 값으로 두고 정말 찾으면 된다
//근데 set으로는 왜 시간초과가 날까
//잘 모르겠다
//set으로 풀려고 발버둥치다가 결국 풀지못하고
//이분탐색으로 정석대로 풀었다!

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int t,n;
vector<int> vt;

bool bs(int pos,int val){
    int l = pos+1;
    int r = vt.size()-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(vt[mid]==val) return true;
        if(vt[mid]>val) r = mid-1;
        else l = mid+1;
    }
    return false;
}
int main(){
    //freopen("input.txt","r",stdin);
    while(scanf("%d",&t) != -1){
        bool check = false;
        t*=10000000; vt.clear();
        scanf(" %d",&n);
        for(int i=0;i<n;i++){
            int a; scanf(" %d",&a);
            vt.push_back(a);
        }
        sort(vt.begin(),vt.end());
        for(int i=0;i<n;i++){
            int c = t-vt[i];
            if(bs(i,c)){
                printf("yes %d %d\n",vt[i],c); 
                check=true; break;
            }
        }
        if(!check) puts("danger");
    }
}