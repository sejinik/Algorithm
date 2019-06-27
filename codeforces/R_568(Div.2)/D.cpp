//생각하고 구현하는 문제
//논리적으로 따지면서 하나하나 구현하면 괜찮은데 
//그렇게 안하고 무턱대고 구현하다가 망한문제
//등차수열이므로 첫번째,두번째,마지막을 뺴고 등차수열인지 미리 확인하고
//이것들이 등차수열이 아니라면 두번째-첫번째값을 d값으로 정해서 등차수열인지 처음부터 본다
//만약 등차수열을 방해하는 요소가 하나만 나오면 그게 답이고
//1개 이상이면 -1이 답이다

#include <iostream>
#include <algorithm>
using namespace std;
int n,cnt,pos;
pair<int,int> arr[200200],a,b;
bool ok (int x,int y,int d){
    for(int i=x;i<y;i++){
        if(arr[i+1].first-arr[i].first != d) return false;
    }
    return true;
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf(" %d",&n);
    if(n<=3) puts("1");
    else{
        for(int i=0;i<n;i++){
            scanf(" %d",&arr[i].first);
            arr[i].second=i+1;
        }
        sort(arr,arr+n);
        bool check=false;
        if(ok(1,n-1,arr[2].first-arr[1].first)) printf("%d\n",arr[0].second);
        else if(ok(2,n-1,arr[2].first-arr[0].first)) printf("%d\n",arr[1].second);
        else if(ok(0,n-2,arr[1].first-arr[0].first)) printf("%d\n",arr[n-1].second);
        else{
            int d = arr[1].first-arr[0].first;
            for(int i=0;i<n-2;i++){
                int next = arr[i].first + d;
                if(arr[i+1].first == next) continue;
                if(arr[i+1].first != next && arr[i+2].first == next){
                    pos = arr[i+1].second; cnt++; i++;
                } else {
                    puts("-1"); return 0;
                }
            }
            if(cnt==1) printf("%d\n",pos);
            else puts("-1");
        }
    }
}