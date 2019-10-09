//set에 현재 들어가있는 수를 넣어가며 확인하면 된다
//자료구조 덱을 사용하면 앞뒤로 편하게 빼고 넣을 수 있다

#include <iostream>
#include <algorithm>
#include <set>
#include <deque>
using namespace std;
deque<int> dq;
set<int> s;
 
int main(){
    int n,k; scanf(" %d %d",&n,&k);
    for(int i=0;i<n;i++){
        int x; scanf(" %d",&x);
        if(s.count(x)) continue;
        else {
            if(dq.size()<k){
                s.insert(x);
                dq.push_front(x);
            } else {
                s.erase(dq.back());
                dq.pop_back();
                dq.push_front(x);
                s.insert(x);
            }
        }
    }
    printf("%d\n",dq.size());
    while(!dq.empty()){
        printf("%d ",dq.front());
        dq.pop_front();
    }
}