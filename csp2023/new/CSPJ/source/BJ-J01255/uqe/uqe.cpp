#include <bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int t,m;
int a,b,c;
int gcd(int a,int b)
{
	if(b==0)
	{
		return a;
	}
	else
	{
		return gcd(b,a%b);
	}
}
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int op,maxm=-1e4;
	cin>>t>>m;
	while(t--)
	{
		cin>>a>>b>>c;
		op=(b*b)-(4*a*c);
		if(op<0)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			for(int x=(-1)*m;x<=m;x++)
			{
				if(a*x*x+b*x+c==0)
				{
					maxm=max(maxm,x);
				}
			}
			cout<<maxm<<endl;
			maxm=-1e4;
		}
	}
	return 0;
}
