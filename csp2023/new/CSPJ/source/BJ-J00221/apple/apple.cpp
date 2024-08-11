#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n,cnt=0,pos=0;
	cin>>n;
	int x=n;
	while(x>0){
		cnt++;
		if(x%3==1&&pos==0)	pos=cnt;
		x-=(x+2)/3;
	}
	cout<<cnt<<' '<<pos<<endl;
	return 0;
}
