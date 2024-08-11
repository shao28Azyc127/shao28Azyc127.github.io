#include<iostream>
#include<cmath>
#include<string>
#include<cstdio>
using namespace std;
struct fs
{
	int a,b;
};
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
fs f(int m,int n) 
{
	int a=m,b=n;
	fs ans;
	if(a==0) 
	{
		ans.a=a,ans.b=1;
		return ans;
	}
	a=abs(a),b=abs(b);
	int fact=gcd(a,b);
	ans.a=a/fact;
	ans.b=b/fact;
	return ans;
}
int g(int a)
{
	int m=1;
	for(int i=1;i*i<=a;i++)
		if(a%(i*i)==0 && i>=m) m=i;
	return m; 
}
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.ans","w",stdout);
	int T,M; cin>>T>>M;
	while(T--)
	{
		int a,b,c; cin>>a>>b>>c;
		int d=b*b-4*a*c;
		if(d>=0)
		{
			int sd=sqrt(d);
			//cout<<sd<<endl;
			if(sd*sd==d)
			{
				int under=sd-b;
				if(a<0) under=under-2*sd;
				int below=2*a;
				//cout<<under<<endl;
				//cout<<below<<endl;
				fs t=f(under,below);
				if(under*below<0) cout<<"-";
				cout<<t.a;
				if(t.b!=1) cout<<"/"<<t.b;
				cout<<endl;
			}
			else
			{
				int flag=1;
				int out=g(d);
				int in=d/(out*out);
				int under1=0-b,under2=out,below=2*a;
				if(a<0) under2=0-under2;
				fs t=f(under1,below);
				if(under1!=0)
				{
					if(under1*below<0) cout<<"-";
					cout<<t.a;
					if(t.b!=1) cout<<"/"<<t.b;
					flag=0;
				}
				t=f(under2,below);
				if(under2*below<0) cout<<"-";
				else if(!flag) cout<<"+";
				if(t.a!=1) cout<<t.a<<"*";
				cout<<"sqrt("<<in<<")";
				if(t.b!=1) cout<<"/"<<t.b;
				cout<<endl;
			}
		}
		else cout<<"NO"<<endl;
	}
	/*int a,b;cin>>a>>b;
	fs t=f(a,b);
	cout<<gcd(a,b)<<" "<<t.a<<" "<<t.b<<endl;*/
	/*int a;
	cin>>a;
	cout<<g(a)<<endl;*/
}
