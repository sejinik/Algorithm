#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,l;
int arr[1111];
int main(){
    //freopen("input.txt","r",stdin);
    scanf(" %d %d",&n,&l);
    for(int i=0;i<n;i++) scanf(" %d",&arr[i]);
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        if(arr[i]<=l) l++;
    }
    printf("%d\n",l);
}