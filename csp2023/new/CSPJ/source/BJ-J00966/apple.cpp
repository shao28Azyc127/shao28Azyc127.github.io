#include<iostream>
using namespace std;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n,x=1,y,z,f=0;
	cin>>n;
	while(n){
		n--;
		if(n%3==0&&f==0){
			f=1;
			y=x;
		}
		x++;
		z=n%3;
		n/=3;
		n*=2;
		n+=z;
	}
	cout<<x-1<<' '<<y;
	return 0;
}