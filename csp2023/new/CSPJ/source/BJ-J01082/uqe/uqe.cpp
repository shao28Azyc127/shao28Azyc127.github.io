#include<bits/stdc++.h>
using namespace std;
double t,a,b,c,abab,m;
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin>>t>>m;
	while(t--){
		cin>>a>>b>>c;
		abab=b*b-4*a*c;
		if(abab<0){
			cout<<"NO"<<endl;
			continue;
		}
		double p1,p2;
		p1=p2=-INT_MAX;
		if((-b-sqrt(abab)))p1=(-b-sqrt(abab))/(2*a);
		if((-b+sqrt(abab)))p2=(-b+sqrt(abab))/(2*a);
		cout<<max(p1,p2)<<endl;
	}
	return 0;
}