//그리디문제인제 복잡하게 생각해서 많이 틀렸다
//나의 틀린 접근법은 각 날마다 최대값을 두고 나머지 날들은 pq에 넣었다
//그리고 각날의 최대값과 나머지날들을 비교해서 큰값을 넣었다
//많은 것들을 고려했었는데 그럴 필요가 없었다
//데드라인 순으로 정렬하고 내가 보고있는 데드라인까지 중 큰 값들만 남기고 버리면 된다
//pq를 이용하면 쉽게 풀 수 있다

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