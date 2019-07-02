//오름차순 정렬된 수를 먼저 세팅하고 반대를 하려고했는데 실패했다
//이 문제를 편하게 풀려면 먼저 정렬이 안된 부분으로 모두 세팅하고 풀면 쉽다
//먼저 모든 배열에 -1을 넣어두자
// 그리고 만약 정렬된 부분이라면 [l+1,r]을 0으로 바꿔주자
// l+1로 한 이유는 이 배열을가지고 원래 배열을 만들때 
//arr[i+1]+=arr[i]로 만들기 때문에 자신의 인덱스 다음부터 보면 된다
//그렇게 정렬된 부분/아닌부분을 (-1,0)을 통해 나눠두고
//arr[0]= 10000 으로 잡고 원래 배열을 만들어보자
//arr[i+1] +=arr[i]를 통해 정렬된 부분이라면 그대로 수가 들어가고
//정렬되지 않았다면 -1때문에 수가 작아질 것이다
//이제 정렬/정렬안된부분 구간을 다 정했다
//마지막으로 정렬안된부분이 정렬되어있는지 다 확인해보며 된다!
//코드포스문제는 아이큐테스트를 하는기분이다!


#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n,m;
vector<pair<int,int>> DOWN;
int arr[1010];

int main(){
    //freopen("input.txt","r",stdin);
    memset(arr,-1,sizeof(arr));
    scanf(" %d  %d",&n,&m);

    for(int i=0;i<m;i++){
        int a,b,c; scanf(" %d %d %d",&a,&b,&c);
        if(!a) DOWN.push_back({b,c});
        else {
            for(int j=b+1;j<=c;j++) arr[j]=0;
        }
    }

    arr[1]=10000;
    for(int i=1;i<n;i++) arr[i+1]+=arr[i];

    for(int i=0;i<DOWN.size();i++){
        int l=DOWN[i].first;
        int r=DOWN[i].second;
        bool check= false;
        for(int j=l;j<=r;j++){
            if(arr[l]>arr[r]) check=true;
        }
        if(!check){
            puts("NO"); return 0;
        }
    }
    puts("YES");
    for(int i=1;i<=n;i++) printf("%d ",arr[i]);
}