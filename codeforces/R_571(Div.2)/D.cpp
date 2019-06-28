// 배열이 주어지고 배열의 올림수 or 내림수의 연속적인 합은 0 이다
// 이 때 이 연속적인 배열을 찾는 문제이다
// 합이 0 이 보장되므로 미리 올림수의 합을 싹 다 구해둔다
// 그 후 만약 합이 0이 아니라면 필요한만큼 내림수를 출력하면 된다!
// 이 때 소수점이 없는 수를 입력받았다면 건너뛰어야한다!

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
bool check[100100];
double arr[100010];
int n;
double sum;
int main(){
    //freopen("input.txt","r",stdin);
    scanf(" %d",&n);
    for(int i=0;i<n;i++){
        scanf(" %lf",&arr[i]);
        sum+=ceil(arr[i]);
    }
    for(int i=0;i<n;i++){
        if(sum==0) printf("%d\n",(int)ceil(arr[i]));
        else if(sum>0){
            int d = (int)arr[i];
            if(arr[i]-(double)d == 0.0) printf("%d\n",(int)ceil(arr[i]));
            else{
                printf("%d\n",(int)floor(arr[i]));
                sum--;
            }
        } 
    }
}