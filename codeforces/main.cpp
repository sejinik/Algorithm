#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int t,n,m;
pair<int,int> S[26],E[26];
char map[2020][2020];
bool check[26];
 
bool r(int index){
    int x = S[index].first;
    int y = S[index].second;
    char c= map[x][y];
    for(int i=S[index].second;i<=E[index].second;i++){
        if((c==map[x][i]) || (map[x][i]=='*')) map[x][i]='*';
        else return false;
    }
    return true;
}
 
bool l(int index){
    int x = S[index].first;
    int y = S[index].second;
    char c = map[x][y];
    for(int i=S[index].first;i<=E[index].first;i++){
        if((c==map[i][y]) || (map[i][y]=='*')) map[i][y]='*';
        else return false;
    }
    return true;
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf(" %d",&t);
    while(t--){
        memset(S,0,sizeof(S));
        memset(E,-1,sizeof(E));
        memset(map,0,sizeof(map));
        memset(check,0,sizeof(check));
        scanf(" %d %d",&n,&m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf(" %1c",&map[i][j]);
                if(map[i][j]=='.') continue;
                int index = map[i][j]-'a';
                if(!check[index]) {
                    S[index].first=i,S[index].second=j;
                    E[index]=S[index];
                    check[index]=true;
                } else E[index].first=i,E[index].second=j;
            }
        }
        bool can = true;
        for(int i=25;i>=0;i--){
            if(!check[i]) continue;
            if(S[i].first==E[i].first) can = r(i);
            else can = l(i);
            if(!can) break;
        }
        if(!can) puts("NO");
        else {
            int sz=check[25];
            for(int i=24;i>=0;i--){
                if(check[i]) sz++;
                else {
                    int prev = i+1;
                    if(check[prev]){
                        check[i]=true; sz++;
                        S[i] = S[prev];
                        E[i] = E[prev];
                    }
                }
            }
            puts("YES");
            printf("%d\n",sz);
            for(int i=0;i<sz;i++){
                printf("%d %d %d %d\n",S[i].first+1,S[i].second+1,E[i].first+1,E[i].second+1);
            }
        }
    }
}