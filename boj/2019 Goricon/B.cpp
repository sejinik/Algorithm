// 생각을 결국 못떠올린 문제다
// 한번 2진수로 생각해보자
// N -> 0 까지 갈 예정이다
// 내가 0번째 비트가 1이라면 사라지게 할 방법이 없다
// 그래서 뒤로 다시 밀어버린다 (*)
// 만약 1번째 비트가 1이라면 ==>2가 있다
// 2를 빼면 된다(-)
// 만약 0,1비트가 다 0이라면 계속 땡겨온다(/)
// 그럼 결국 10^13인 2^45승정도의 비트를
// 이런식으로 다 보고 처리해주면 된다
// N부터 거꾸로 보기 때문에 반대로 연산자를 담아주자
// 0번째 비트가 1인경우,0인경우를 생각해보면 절대 99번을 초과할 경우가 없다
// 신기하고 쉬워보이는데 나한텐 어려운 문제다!!

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
ll n;
vector<char> vt;
int main(){
    scanf(" %lld",&n);
    while(n){
        if(n&1) {
            vt.push_back('/'); n*=2;
        }
        else if(n&2){
            vt.push_back('+'); n-=2;
        }
        else {
            vt.push_back('*'); n/=2;
        }
    }
    if(vt.size() >99) puts("-1");
    else {
        printf("%d\n",(int)vt.size());
        for(int i=(int)vt.size()-1; i>=0;i--) printf("[%c] ",vt[i]);
    } 
}