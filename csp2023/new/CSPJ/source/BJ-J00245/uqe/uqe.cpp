#include<bits/stdc++.h>
using namespace std;
int t,m,a,b,c;
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin>>t>>m;
	for(;1<=t;t--)
	{
		cin>>a>>b>>c;
		if(b*b-4*a*c<0)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			for(int i=m;i>=0-m;i--)
			{
				if(a*i*i+b*i+c==0)
				{
					cout<<i<<endl;
					break;
				}
			}
		}
	}
	return 0;
}
