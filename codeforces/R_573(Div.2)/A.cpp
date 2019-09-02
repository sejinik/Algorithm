//나머지가 0이면 D, 1이면 A, 2이면 C, 3이면 D이다
//순서는 A>B>C>D 순으로 A가 가장 높다
//수가 주어질때 0~2까지 더할수있는데 이 때 가장높은 순위를 만들고 더한 수와 순위를 출력해라
//나머지에 맞게 미리 배열에 저장해주고 직접 0~2까지 더해보자


#include <iostream>
#include <algorithm>
using namespace std;
int n;
char arr[4]= {'D','A','C','B'};
int main(){
	//freopen("input.txt","r",stdin);
	scanf(" %d",&n);
	int cnt=0;
	char ans=arr[n%4];
	for(int i=0;i<3;i++){
		char next = arr[(n+i)%4];
		if(next<ans){
			ans = next;
			cnt=i;
		}
	}
	printf("%d %c\n",cnt,ans);
}