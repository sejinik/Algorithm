#include <iostream>
#include <algorithm>
using namespace std;

char Ml,Mr,Tl,Tr;

int Acheck(char A, char B){
    if(A=='R'){
        if(B=='R') return 0;
        else if (B=='P') return -1;
        return 1;
    } 
    else if(A=='P'){
        if(B=='R') return 1;
        else if(B=='P') return 0;
        return -1;
    }
    else{
        if(B=='R') return -1;
        else if(B=='P') return 1;
        return 0;
    }
}
int main(){
    cin>>Ml>>Mr>>Tl>>Tr;
    if((Acheck(Ml,Tl)==1 && Acheck(Ml,Tr)==1) || ((Acheck(Mr,Tl)==1 && Acheck(Mr,Tr)==1))) puts("MS");
    else if((Acheck(Tl,Ml)==1 && Acheck(Tl,Mr)==1) || (Acheck(Tr,Ml)==1 && Acheck(Tr,Mr)==1)) puts("TK");
    else puts("?");
}