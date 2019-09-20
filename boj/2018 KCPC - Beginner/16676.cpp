#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string s; cin>>s;
    if(s[0] != '1') printf("%d\n",s.size());
    else {
        string a="";
        for(int i=0;i<s.size();i++) a.push_back('1');
        int num = stoi(a);
        int n = stoi(s);
        if(n>=num) printf("%d\n",s.size());
        else printf("%d\n",s.size()-1);
    }
}