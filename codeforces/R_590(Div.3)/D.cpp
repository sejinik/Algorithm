//세그먼트 트리를 알파벳별로 만들어서 확인하다
//그럼 26*lgN만에 확인이 가능하다

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
string s;
int n;
int tree[30][4*100010];
 
int update(int node,int l,int r,int pos,int idx,int val){
    if(idx<l || idx>r) return 0;
    if(l==r) return tree[pos][node]=val;
    update(node*2,l,(l+r)/2,pos,idx,val);
    update(node*2+1,(l+r)/2+1,r,pos,idx,val);
    return tree[pos][node] = tree[pos][node*2] | tree[pos][node*2+1];
}
 
int query(int node,int s,int e,int l,int r,int pos){
    if(r<s || l>e) return 0;
    if(l<=s && e<=r) return tree[pos][node];
    return query(node*2,s,(s+e)/2,l,r,pos) | query(node*2+1,(s+e)/2+1,e,l,r,pos);
}
 
int main(){
    cin>>s>>n;
    int len = s.size();
    for(int i=0;i<(int)s.size();i++) 
        update(1,1,len,s[i]-'a',i+1,1);
 
    for(int i=0;i<n;i++){
        int c; scanf(" %d",&c);
        if(c==1){
            int x; char a;
            scanf(" %d %c",&x,&a);
            update(1,1,len,s[x-1]-'a',x,0);
            update(1,1,len,a-'a',x,1);
            s[x-1]=a;
        } else {
            int l,r; scanf(" %d %d",&l,&r);
            int sum=0;
            for(int j=0;j<26;j++) sum +=query(1,1,len,l,r,j);
            printf("%d\n",sum);
        }
    }
}