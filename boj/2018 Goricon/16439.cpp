#include <iostream>
#include <algorithm>
using namespace std;

int n,m,ans;

int arr[33][33];

int main(){
    //freopen("input.txt","r",stdin);
    scanf(" %d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf(" %d",&arr[i][j]);
        }
    }
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            for(int k=j+1;k<m;k++){
                int temp=0;
                for(int q=0;q<n;q++){
                    temp+=max({arr[q][i],arr[q][j],arr[q][k]});
                }
                ans = max(ans,temp);
            }
        }
    }
    printf("%d\n",ans);
}