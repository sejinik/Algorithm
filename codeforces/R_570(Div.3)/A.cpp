// n보다 큰수중 각자리수의 합이 4로 나눠떨어지는 수를 찾는 문제다
// 그냥 정말 찾아보면된다

#include <iostream>
using namespace std;
int n;

bool isOk(int x){
    int ret=0;
    int c =x;
    while(c){
        ret+=c%10;
        c/=10;
    }
    return (ret%4==0);
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf(" %d",&n);
    for(int i=n;i<=100000;i++){
        if(isOk(i)){
            printf("%d\n",i); return 0;
        }
    }
}