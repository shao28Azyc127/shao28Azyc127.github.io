#include<bits/stdc++.h>
using namespace std;
int M;
long long gcd(int a,int b)
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
int find(double dt)
{
	long long p=dt;
	if(p==dt)
	{
		cout<<1<<endl;
	}
	for(double i=2;i<=M;i++)
	{
		p=(dt*i);
		if(p==dt*i&&gcd(p,i)==1)
		{
			return i;
		}
	}
	return 0;
}
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	ios::sync_with_stdio(false);
	int T;
	cin>>T>>M;
	while(T--)
	{
		long long a,b,c;
		cin>>a>>b>>c;
		double dt=b*b-4*a*c;
		if(dt<0)
		{
			cout<<"NO"<<endl;
			continue;
		}
		else 
		{
			double maxans=0;
			if(dt==0)
			{
				maxans=(-b+sqrt(dt))/(2*a);
			}
			else
			{
				maxans=max((-b+sqrt(dt))/(2*a),(-b-sqrt(dt)/(2*a)));
			}
			int d=find(maxans);
			if(d!=0)
			{
				if(d==1)
				{
					cout<<maxans<<endl;
				}
				else
				{
					cout<<maxans*d<<"/"<<d<<endl;
				}
			}
			else
			{
				if((-b)/(2*a)!=0)
				{
					cout<<(-b)/(2*a)<<"+"<<endl;
				}
			}
		}
	}
	return 0;
}