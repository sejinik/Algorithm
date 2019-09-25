#include <iostream>
// 흰 사각형 1개, 검은 사각형 2개가 있을 때 흰색의 영역이 검은색으로 덮히지 않는 곳이 있는지 확인한다
// 나는 흰사각형의 내부에서 대각선 2개 위의 점을 0.1 간격으로 확인했다
// 정해는 아니겠지만 검은색이 x,y축에 항상 평행 하므로 이 대각선들의 점만 확인하면 항상 확인할 수 있다 

#include <vector>
using namespace std;
 
bool check(double x,double y,double r1,double r2,double w1,double w2){
    if(x<r1 || x>r2 || y<w1 || y>w2) return true;
    return false;
}
 
double x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6;
int main(){
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4>>x5>>y5>>x6>>y6;
    double mid = (y2-y1)/(x2-x1);
    for(double i=0;i<=x2-x1;i+=0.1){
        double x = x1+i;
        double y = y1+i*mid;
        if(check(x,y,x3,x4,y3,y4) && check(x,y,x5,x6,y5,y6)){
            puts("YES"); return 0;
        }
        double Y = y2-i*mid;
        if(check(x,Y,x3,x4,y3,y4) && check(x,Y,x5,x6,y5,y6)){
            puts("YES"); return 0;
        }
    }
    puts("NO");
}