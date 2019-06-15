//BFS + 에라토스테네스의 체를 이용하는 문제이다
//에라토스테네스의 체로 소수를 구한다
//4자리 소수중 숫자가 1만 차이나는것들을 이어서 그래프를 만든다
//그리고 숫자가 들어오면 BFS를 돌려 최소거리를 찾는다!
//나는 배열을 만들어서 인덱스를 저장했지만
//소수는 정렬된 채로 저장되기때문에 lower_bound 사용 가능하다


#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
using namespace std;
bool cPrime[10010];
int num[10010], dist[1111], check[1111];
int cnt;
vector<int> prime;
vector<vector<int>> Graph;
void p(){
    for(int i=2;i<10000;i++){
        if(!cPrime[i]){
            for(int j=i*2;j<10000;j+=i) cPrime[j]=true;
            if(i>=1000) {
                prime.push_back(i);
                num[i]=cnt++;
            }
        }
    }
}
bool numCheck(int _x,int _y){
    int ret = 0;
    int x= _x, y=_y;
    for(int i=0;i<4;i++){
        int a = x%10;
        int b = y%10;
        if(a==b) ret++;
        x/=10; y/=10;
    }
    return (ret==3);
}

void makeGraph(){
    p();
    Graph.resize(cnt);
    for(int i=0;i<cnt;i++){
        for(int j=0;j<cnt;j++){
            if(numCheck(prime[i],prime[j])){
                Graph[i].push_back(j);
                Graph[j].push_back(i);
            }
        }
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    makeGraph();
    int t; scanf(" %d",&t);
    while(t--){
        memset(dist,-1,sizeof(dist));
        memset(check,0,sizeof(check));
        int a,b; scanf(" %d %d",&a,&b);
        queue<int> q;
        q.push(num[a]);
        check[num[a]]=true;
        dist[num[a]]=0;
        while(!q.empty()){
            int pos = q.front();
            q.pop();
            for(int i=0;i<Graph[pos].size();i++){
                int next = Graph[pos][i];
                if(!check[next]){
                    check[next]=true;
                    dist[next]=dist[pos]+1;
                    q.push(next);
                }
            }
        }
        if(dist[num[b]]==-1) puts("Impossible");
        printf("%d\n",dist[num[b]]);
    }
}