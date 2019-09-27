#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int n,odd,even;
int main(){
    scanf(" %d",&n);
    for(int i=0;i<n;i++){
        int x; scanf(" %d",&x);
        if(x&1) odd++;
        else even++;
    }
    printf("%d\n",min(odd,even));
}