//미리 전처리를 통해 처음 받는 문자열 n까지의 알파뱃 수를 배열에 계산 해준다
// 그리고 쿼리로 입력받는 문자열의 알파뱃 수를 저장한다
// 그 후 이분탐색을 통해 만족시키는 값을 빠르게 찾는다!

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
int n,m;
char s[200020],t[200020];
int check[200020][30];
int temp[30];

bool go(int mid){
    for(int i=0;i<26;i++){
        if(check[mid][i]<temp[i]) {
            return false;
        }
    }
    return true;
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf(" %d",&n);
    scanf(" %s",&s);
    for(int i=0;i<n;i++){
        int c = s[i]-'a';
        check[i][c]++;
        for(int j=0;j<26;j++){
            check[i+1][j]=check[i][j];
        }
    }
    scanf(" %d",&m);
    while(m--){
        memset(temp,0,sizeof(temp));
        scanf(" %s",&t);
        for(int i=0;t[i];i++){
            int c = t[i]-'a';
            temp[c]++;
        }
        int l=0,r=n;
        int ans = 1e9;
        while(l<=r){
            int mid = (l+r)/2;
            if(go(mid)){
                ans = min(ans,mid);
                r = mid-1;
            }
            else l = mid+1;
        }
        printf("%d\n",ans+1);
    }
}