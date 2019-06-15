//GCD를 구하면 쉽게 풀 수 있다
//GCD는 gcd(x,y) 함수를 만들고
//x를 y로 나눈 나머지를 계속 구해가며 구하면된다
//만약 나머지를 구한 후에는 gcd(y,나머지);
//이런식으로 계속 들어가준다 나머지가 0이 될 때까지!
//최소공배수는 X*Y/GCD로 쉽게 구할 수 있다

#include <iostream>
using namespace std;
int gcd(int x,int y){
    if(!y) return x;
    return gcd(y,x%y);
}

int main(){
    int n,m; scanf(" %d %d",&n,&m);
    int g = gcd(n,m);
    printf("%d\n%d\n",g,n*m/g);
}