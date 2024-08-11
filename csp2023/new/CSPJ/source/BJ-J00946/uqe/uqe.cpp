#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int t,m;
	cin>>t>>m;
	for(int i=1;i<=t;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		int r=b*b-4*a*c;
		if(r<0)
		{
			cout<<"NO"<<endl;
			continue;
		}
		int x1=(-b+sqrt(r))/(2*a);
		int x2=(-b-sqrt(r))/(2*a);
		if(x1==x2)
			cout<<x1<<endl;
		else
			cout<<max(x1,x2)<<endl;
	}
	return 0;
}