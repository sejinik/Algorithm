//올림수를 위해 double을 사용하고 ceil을 써도 괜찮고
//n-1을 더하고 n으로 나눠도 된다

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int q;
int n;
 
int main(){
    scanf(" %d",&q);
    while(q--){
        scanf(" %d",&n);
        int sum=0;
        for(int i=0;i<n;i++){
            int x; scanf(" %d",&x);
            sum+=x;
        }
        printf("%d\n",(sum+n-1)/n);
    }
}