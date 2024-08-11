#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int t,m;
	cin>>t>>m;
	while(t--)
	{
		double a,b,c;
		cin>>a>>b>>c;
		if(b==0 and c==0)
		{
			cout<<0<<endl;
		}
		double yn=(b*b)-(4*a*c);
		if(yn<0)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			double x1=((b-2*b)+sqrt(yn))/(2*a);
			double x2=((b-2*b)-sqrt(yn))/(2*a);
			cout<<max(x1,x2)<<endl;
		}
	}
	return 0;
}//may will get 50 marks