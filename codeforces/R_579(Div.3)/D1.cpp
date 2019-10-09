#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s,t;
int ans;
int main(){
    cin>>s>>t;
    int sz= s.size();
    int tz = t.size();
    for(int i=0;i<sz;i++){
        for(int j=i;j<sz;j++){
            bool check=false;
            int pos=0;
            for(int k=0;k<sz;k++){
                if(i<=k && k<=j) continue;
                if(t[pos]==s[k]) pos++;
                if(pos==tz) {
                    check=true; break;
                }
            }
            if(check) ans = max(ans,j-i+1);
        }
    }
    printf("%d\n",ans);
}