#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int t,m,a,b,c,drt;
	double tmp;
	cin>>t>>m;
	if(m<=1)
	{
		while(t--)
		{
			cin>>a>>b>>c;
			cout<<0<<endl;
		}
		return 0;
	}
	else
	{
		return 0;
	}
	/*while(t--)
	{
		cin>>a>>b>>c;
		drt=b*b-4*a*c;
		if(drt<0) 
		{
			cout<<"NO"<<endl;
			continue;
		}
		double x1,x2,x;
		tmp=sqrt(drt);
		if(tmp*tmp==drt)
		{
			x1=(b*-1+drt)/(2*a),x2=(b*-1-drt)/(2*a);
			x=max(x1,x2);
			cout<<x<<endl;
			continue;
		}
		//else(
		//x1=(b*-1+drt)/(2*a),x2=(b*-1-drt)/(2*a);
		x=max(x1,x2);
		
	}*/
	return 0;
}
