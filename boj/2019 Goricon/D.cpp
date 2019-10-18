//시프트가 전체가 되므로 그냥 시작점을 옮겨보면 된다
//시작점을 기준으로 k칸 뒤에 값을 더해주면 되고
//오른쪽 왼쪽 시프트시 시작칸을 움직여보자!

#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
int n,q,s;
ll arr[200020];


int main(){
    cin>>n>>q;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<q;i++){
        int x; cin>>x;
        int a,b;
        if(x==1){
            cin>>a>>b; a--;
            arr[(s+a)%n]+=b;
        } else if(x==2){
            cin>>a; 
            s = (s+n-a)%n;
        } else {
            cin>>a;
            s = (s+a)%n;
        }
    }
    for(int i=0;i<n;i++) printf("%d ",arr[(s+i)%n]); puts("");
}