#include <iostream>
using namespace std;
int n;
int arr[11];
int solve(int x){
    int c =x;
    while(c){
        arr[c%10]++;
        c/=10;
    }
    for(int i=0;i<=9;i++){
        if(arr[i] && i!=2 && i!=0 && i!=1 && i!=8) return 0;
    }
    if(!(arr[2] && arr[0] && arr[1] && arr[8])) return 1;
    if(!((arr[2]==arr[0]) && (arr[0]==arr[1]) && (arr[1]==arr[8]))) return 2;
    return 8;
}

int main(){
    scanf(" %d",&n);
    printf("%d\n",solve(n));
}