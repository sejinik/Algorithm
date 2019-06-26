#include <iostream>
using namespace std;
int n,m;
int p[1000100];

int find(int x){
    if(x==p[x]) return x;
    return p[x] = find(p[x]);
}

void merge(int x,int y){
    x = find(x);
    y = find(y);
    if(x==y) return;
    p[x]=y;
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf(" %d %d",&n,&m);
    for(int i=1;i<=n;i++) p[i]=i;
    for(int i=0;i<m;i++){
        int a,b,c; scanf(" %d %d %d",&a,&b,&c);
        if(!a) merge(b,c);
        else{
            int x = find(b);
            int y = find(c);
            printf("%s\n",(x==y ? "YES" : "NO"));
        }
    }
}