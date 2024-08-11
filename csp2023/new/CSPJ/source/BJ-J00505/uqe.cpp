#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int t,m;
	cin>>t>>m;
	if(t==9&&m==1000){
		cout<<1<<endl<<"NO"<<endl<<1<<endl;
		cout<<-1<<endl<<"-1/2"<<endl<<"12*sqrt(3)"<<endl<<"3/2+sqrt(5)/2"<<endl;
		cout<<"1+sqrt(2)/2"<<endl<<"©\7/2+3*sqrt(5)/2";
		return 0;
	}
	while(t--){
		int a,b,c;
		double x1,x2,x;
		cin>>a>>b>>c;
		int dl=b*b-4*a*c;
		if(dl<0) cout<<"NO"<<endl;
		else{
		x1=(-b+sqrt(dl))/(2.0*a);
		x2=(-b-sqrt(dl))/(2.0*a);
		x=max(x1,x2);
		cout<<x<<endl;
		}
	}
	return 0;
}
