#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
bool np[1005];
vector<int> p;
void getprime(int n)
{
	np[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!np[i])	p.emplace_back(i);
		for(int j:p)
		{
			if(i*j>n)	break;
			np[i*j]=1;
			if(i%j==0)	break;
		}
	}
}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
void output(int above,int below)
{
	if(above==0)
	{
		cout<<0;
		return;
	}
	int g=gcd(abs(above),abs(below));
	if(below==g)
	{
		cout<<above/g;
		return;
	}
	cout<<above/g<<"/"<<below/g;
}
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int t,m;
	cin>>t>>m;
	getprime(m);
	while(t--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(a<0)	a=-a,b=-b,c=-c;
		long long delta=1ll*b*b-4ll*a*c;
		if(delta<0)
		{
			cout<<"NO\n";
			continue;
		}
		int s=sqrt(delta)+1;
		while(1ll*s*s>delta)	s--;
		if(1ll*s*s==delta)
		{
			output(s-b,2*a);
			cout<<endl;
			continue;
		}
		if(b)	output(-b,2*a),cout<<"+";
		long long q2=1,r=delta,q3=2*a;
		for(int i:p)
			if(i>r)	break;
			else
			{
				int i2=i*i;
				while(r%i2==0)
					r/=i2,q2*=i;
			}
		int g=gcd(q2,q3);
		q2/=g,q3/=g;
		if(q2!=1)	cout<<q2<<"*";
		cout<<"sqrt("<<r<<")";
		if(q3!=1)	cout<<"/"<<q3;
		cout<<endl;
	}
}