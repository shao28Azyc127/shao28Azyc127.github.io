#include<iostream>
#include<cstdio>
using namespace std;
int p1,q1,p2,p3,q2;
int a,b,c,m,t;
int gcd(int a,int b)
{
	if(a<b) swap(a,b);
	while(b)
	{
		a%=b;
		swap(a,b);
	}
	return a;
}
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin>>t>>m;
	for(int i=1;i<=t;++i)
	{
		cin>>a>>b>>c;
		int g1,g2;
		p1=-b;
		p3=b*b-4*a*c;
		if(p3<0)
		{
			cout<<"NO\n";
			continue;
		}
		p2=1;
		//cout<<i<<":part1\n";
		for(int j=2;j*j<=p3;j++)
			if(p3%(j*j)==0) p2=j;
		//cout<<i<<":part2\n";
		p3/=p2*p2;
		q1=q2=2*a;
		g1=gcd(p1,q1);
		g2=gcd(p2,q2);
		p1/=g1;
		q1/=g1;
		p2/=g2;
		q2/=g2;
		if(q1<0)
		{
			p1=-p1;
			q1=-q1;
		}
		if(q2<0)
		{
			p2=-p2;
			q2=-q2;
		}
		//cout<<i<<":part3\n";
		if(p3==1)
		{
			int p4=p1*q2+q1*p2;
			int q4=q1*q2;
			int g4=gcd(p4,q4);
			if(p4==g4) cout<<1;
			else
			{
				if(!p4) cout<<0;
				cout<<p4/g4;
				if(q4!=1) cout<<"/"<<q4/g4;
			}
		}
		else
		{
			if(p1)
			{
				cout<<p1;
				if(q1!=1) cout<<"/"<<q1;
				if(p2!=0 && p3!=0)
				{
					cout<<"+";
					if(p2!=1 && p3!=1) cout<<p2<<"*sqrt("<<p3<<")";
					else if(p2==1 && p3!=1) cout<<"sqrt("<<p3<<")";
					if(q2!=1) cout<<"/"<<q2;
				}
			}
			else
			{
				if(p2!=0 && p3!=0)
				{
					if(p2!=1 && p3!=1) cout<<p2<<"*sqrt("<<p3<<")";
					else if(p2==1 && p3!=1) cout<<"sqrt("<<p3<<")";
				}
				else cout<<0;
			}
		}
		cout<<endl;
	}
	return 0;
}