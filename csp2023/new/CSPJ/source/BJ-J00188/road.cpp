#include<iostream>
using namespace std;
int main(){
	int n,d,v,miles=0,a;
	double fee,b,c;
	cin>>n>>d;
	for(int i=1;i<=n-1;i++){
cin>>v;
miles+=v;
	}b=miles/d;
	cin>>a;
	cout<<a*b;
	return 0;
}
