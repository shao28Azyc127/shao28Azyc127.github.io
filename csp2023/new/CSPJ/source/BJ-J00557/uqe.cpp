#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("uqe.in","r",stdout);
	freopen("uqe.out","w",stdout);
	int T,ddd;
	cin>>T>>ddd;
	while(T--){
		int a,b,c;
		cin>>a>>b>>c;
		int derta=b*b-(4*a*c);
		if(derta<0){
			cout<<"NO\n";
			continue;
		}
		cout<<max(((-b+sqrt(derta))/(2*a)),((-b-sqrt(derta))/(2*a)))<<endl;
	}
	return 0;
}