#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int t,m;
	long long a,b,c,drt,xo,xt;
	cin>>t>>m;
	for(int i=1;i<=t;i++)
	{
		cin>>a>>b>>c;
		drt=b*b-4*a*c;
		if(drt<0)
			cout<<"NO"<<endl;
		else
		{
			xo=(-b+sqrt(drt))/(2*a);
			xt=(-b-sqrt(drt))/(2*a);
			cout<<max(xo,xt)<<endl;
		}
	}
	return 0;
}