#include <bits/stdc++.h>
using namespace std;
long long m;
void uqe(){
	long long a,b,c;
	cin>>a>>b>>c;
	long long d=b*b-4*a*c;
	if(d<0){
		cout<<"NO"<<endl;
	}else{
		double x=(-b+sqrt(d))/2*a;
		if(x*10%10==0){
			cout<<x<<endl;
		}else if(-b+sqrt(d)*10%10==0){
			cout<<-b+sqrt(d)/gcd(-b+sqrt(d),2*a)<<"/"<<2*a/gcd(-b+sqrt(d),2*a)<<endl;
		}else{
			long long r=b*c/2;
			double q1=-b/2/a,q2=a/2;
			if(q1!=0){
				if(q1*10%10==0){
					cout<<q1<<"+";
				}else{
					cout<<b/gcd(b,2*a)<<"/"<<2*a/gcd(b,2*a)<<"+";
				}
			}
			if(q2==1){
				cout<<"sqrt("<<r<<")"<<endl;
			}else if(q2*10%10==0){
				cout<<q2<<"*sqrt("<<r<<")"<<endl;
			}else if(1/q2*10%10==0){
				cout<<"sqrt("<<r<<")/"<<1/q2<<endl
			}else{
				cout<<c<<"*sqrt("<<r<<")/"<<d;
			}
		}
	}
}
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	long long t;
	cin>>t>>m;
	while(t--){
		uqe();
	}
	return 0;
}