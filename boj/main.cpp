#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
pair<int,int> arr[200200];
int n;

int main(){
    //freopen("input.txt","r",stdin);
    scanf(" %d",&n);
    for(int i=0;i<n;i++) scanf(" %d %d",&arr[i].first,&arr[i].second);
    sort(arr,arr+n);
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        int d = arr[i].first;
        pq.push(-arr[i].second);
        while(d<pq.size()) pq.pop();
    }
    int ans=0;
    while(!pq.empty()) ans+=pq.top(),pq.pop();
    printf("%d\n",-ans);
}