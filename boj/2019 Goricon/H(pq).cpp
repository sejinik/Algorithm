// 도수를 기준으로 정렬하고 
// k개를 돌아보며 하나씩 선호도값을 더해보자
// 이 때 pq에도 같이 넣어준다
// 만약 pq가 내가 정한 술이라 할 때
// pq의 사이즈가 n보다 커지면 가장 선호도가 낮은걸 빼주자
// 그리고 pq.size == n && sum>=m으로 문제의 조건을 만족한다면
// 내가 마지막으로 넣어준 도수를 출력해주자
// k번동안 못찾으면 답은 없다 -1

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
ll n,m,k,sum;

int main(){
    scanf(" %lld %lld %lld",&n,&m,&k);
    vector<pair<ll,ll>> vt(k);
    for(int i=0;i<k;i++) scanf(" %lld %lld",&vt[i].second,&vt[i].first);
    sort(vt.begin(),vt.end());
    priority_queue<ll> pq;
    for(int i=0;i<k;i++){
        pq.push(-vt[i].second);
        sum+=vt[i].second;

        if(pq.size()>n){
            sum +=pq.top();
            pq.pop();
        }

        if(pq.size()==n && sum >=m){
            printf("%lld\n",vt[i].first); return 0;
        }
    }
    puts("-1");
}
