#include <bits/stdc++.h>
using namespace std;

int gcd(int p,int q)
{
	return q==0 ? p : gcd(q,p%q);
}

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
		if(c==0 && b==0)
		{
			cout<<0<<endl;
		}
		else if(b==0)
		{
			if(c<0) cout<<"NO"<<endl;
			else cout<<"sqrt("<<c<<")/"<<a<<endl;
		}
	}
	return 0;
}
