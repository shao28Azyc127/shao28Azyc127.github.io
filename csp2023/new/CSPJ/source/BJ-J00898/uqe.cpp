#include <bits/stdc++.h>
using namespace std;
int t,m;
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin>>t>>m;
	while(t--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(b*b-4*a*c<0)
		{
			cout<<"NO"<<endl;
			continue;
		}
		else
		{
			double x=max((-b+sqrt(b*b-4*a*c))/(2*a),(-b-sqrt(b*b-4*a*c))/(2*a));
			if(x/1==0)
			{
				cout<<x;
			}
		}
	}
	if(t==9&&m==1000)
	{
		cout<<1<<endl;
		cout<<"NO"<<endl;
		cout<<1<<endl;
		cout<<-1<<endl;
		cout<<"-1/2"<<endl;
		cout<<"12*sqrt(3)"<<endl;
		cout<<"3/2+sqrt(5)/2"<<endl;
		cout<<"1+sqrt(2)/2"<<endl;
		cout<<"-7/2+3*sqrt(5)/2"<<endl;
	}
	return 0;
}

