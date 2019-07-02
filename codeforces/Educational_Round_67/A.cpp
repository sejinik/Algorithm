//5번 틀린 공포의 문제
//나는 왜 계속 뺄 생각을 안하고 난리를 쳤을까
//그냥 더 작은 수 뺀 만큼은 무조건 사고 거기서 1개 더사주면 된다


#include <iostream>
#include <algorithm>
using namespace std;
int t,n,s,k;

int main(){
    scanf(" %d",&t);
    while(t--){
        scanf(" %d %d %d",&n,&s,&k);
        int a = min(s,k);
        printf("%d\n",n-a+1);
    }
}