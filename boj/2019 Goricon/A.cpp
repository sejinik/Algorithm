//1에 항상 둔다고 가정하면
// n-1개를 기준으로 두고 생각하면 된다
#include <iostream>
using namespace std;
int n,t,c,p;

int main(){
    cin>>n>>t>>c>>p;
    printf("%d\n",(n-1)/t*c*p);
}