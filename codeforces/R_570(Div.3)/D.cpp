//정렬 + 그리디 문제이다
//pq를 이용해서 정렬하고 큰값을보며 마지막으로 더한값을 last에 담아갔다
//만약 개수가 last보다 많다면 last-1을
//아니라면 개수를 더한다
// 근데 시간초과가 났다
// 방법은 같은데 pq를 써서 그런가보다
// 벡터로 똑같이 풀면 시간안에 들어온다!
// 시간 고려해서 벡터로 우선 풀수있으면 하자!

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int q,n;
int main(){   
    //freopen("input.txt","r",stdin);
    scanf(" %d",&q);
    while(q--){
        scanf(" %d",&n);
        vector<int> vt(n+1);
        for(int i=0;i<n;i++){
            int x; scanf(" %d",&x);
            vt[x]++; 
        }
        sort(vt.begin(),vt.end());
        reverse(vt.begin(),vt.end());
        int ans= vt[0];
        int last = vt[0];
        for(int i=1;i<=n;i++){
            if(vt[i]>=last){
                ans+=last-1;
                last--;
            } else {
                ans += vt[i];
                last =vt[i];
            }
            if(last<=1) break;
        }
        printf("%d\n",ans);
    }
}