//알파뱃이 A~Z순서대로 들어오고 1직선으로 그림을 그릴 수 있다
//이 때 위에 덧그리면 새로그리는 알파벳이 위로 올라간다
//그려진 그림을 보고 그릴수있는 그림이라면 YES 와 그리는 순서를 출력하고\
//아니라면 NO다
//처음에 생각한건 알파벳들을 S,E에 시작 끝 위치 담아두고
//끝 알파벳부터 돌리면서 위치를 *로 바꿔준다
//알파벳은 S부터 E까지 가면서 나와 같거나 *라면 지나가고 아니면 false다
//그렇게 다 구해서 a부터 출력했는데 계속 시간초과가 떠서 보니 안구해도 되는것도 구해서 계속 시간을 버렸다
//그거 지웠는데도 시간초과가 뜨긴 한다 ㅎ
//결국 알파벳 위치를 받고 그림을 그리고 비교하는 방식으로 풀었다
//왜 시간초과가 나는걸까..! 어렵다!!

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int t,n,m,last;
pair<int,int> S[26],E[26];
char map[2020][2020],temp[2020][2020];
bool check[26];
 
int main(){
    //freopen("input.txt","r",stdin);
    scanf(" %d",&t);
    while(t--){
        memset(S,0,sizeof(S));
        memset(E,0,sizeof(E));
        memset(check,0,sizeof(check));
        last=-1;
        scanf(" %d %d",&n,&m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                temp[i][j]='.';
                scanf(" %1c",&map[i][j]);
                if(map[i][j]=='.') continue;
                int index = map[i][j]-'a';
                
                if(!check[index]) {
                    S[index].first=i,S[index].second=j;
                    E[index] = S[index];
                    check[index]=true;
                    last = max(last,index);
                } else E[index].first=i,E[index].second=j;
            }
        }
 
        bool can = true;
        for(int i=0;i<=last;i++){
            if(!check[i]) continue;
            int x = S[i].first;
            int y = S[i].second;
            if(S[i].first==E[i].first){
                for(int j=S[i].second;j<=E[i].second;j++) temp[x][j]=(char)('a'+i);
            }
            else {
                for(int j=S[i].first;j<=E[i].first;j++) temp[j][y]=(char)('a'+i);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(map[i][j] != temp[i][j]) can = false; 
            }
            if(!can) break;
        }
        if(!can) puts("NO");
        else {
            for(int i=last;i>=0;i--){
            if(!check[i]){
                check[i]=true; 
                S[i]=S[last];
                E[i]=E[last];
            }
            }
            puts("YES");
            printf("%d\n",last+1);
            for(int i=0;i<=last;i++) printf("%d %d %d %d\n",S[i].first+1,S[i].second+1,E[i].first+1,E[i].second+1);
        }
    }
}