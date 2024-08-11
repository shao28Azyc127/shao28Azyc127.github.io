#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int T, M;
int a, b, c;
int main(){
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	cin>>T>>M;
	while(T--){
		cin>>a>>b>>c;
		int dt=b*b-4*a*c;
		if(dt<0)
			cout<<"NO"<<endl;
		else{
			int p=(-b+sqrt(dt))/2/a;
			int q=(-b-sqrt(dt))/2/a;
			cout<<max(p, q)<<endl;
		}
	}
	return 0;
}