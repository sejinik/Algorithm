#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
string s;
int n,ssize;
double maxScore;
vector<pair<string,double>> vt;

void input(string st,int score){
    int j=0;
    for(int i=0;i<st.size();i++){
        if(st[i]==s[j]) j++;
    }
    if(j<ssize) return;
    int len = st.size() - ssize;
    if(len==0) vt.push_back({st,0});
    else {
        double temp = (score*1.0)/len;
        maxScore = max(temp,maxScore);
        vt.push_back({st,temp});
    }
}
int main(){
    cin>>s>>n;
    ssize= s.size();
    for(int i=0;i<n;i++){
        string temp;
        int num;
        cin>>temp >>num;
        input(temp,num);
    }
    for(int i=0;i<vt.size();i++){
        if(vt[i].second==maxScore){
            cout<<vt[i].first<<endl; return 0;
        }
    }
    puts("No Jam");
}