//비트마스크 혹은 bitset으로 풀 수 있는 문제
//메모리 제한에 맞게 배열을 작게 잡아주고
//비트마스크를 통해 숫자가 있는지 없는지 확인한다
//int는 숫자 1개당 32bit를 가진다
//1bit로 숫자를 1개씩 표현하면 숫자 32개 표현가능
//그럼 (1<<20)개로도 모든 수 처리 가능!

#include <iostream>
using namespace std;
int a[1<<20];

int main(){
    //freopen("input.txt","r",stdin);
    int n; 
    while(scanf(" %d",&n) != -1){
        int x = n/32;
        int y = n%32;
        if(!(a[x]&(1<<y))){
            printf("%d ",n);
            a[x]|=(1<<y);
        }
    }
}