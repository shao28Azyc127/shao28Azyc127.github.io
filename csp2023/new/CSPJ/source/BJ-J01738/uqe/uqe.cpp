#include <iostream>
#include <cmath>
using namespace std;
const int N=1e5+5;
int t,m;
int a,b,c;
int d;
int gcd(int a,int b)
{
	int num=1;
	for(int i=2;i<=min(min(a,b),max(a,b)/2);i++)
	{
		if(a%i==0 && b%i==0) num=i;
	}
	return num;
}
void find(double x)
{
	int cnt=x,num=1;
	while(x-cnt!=0)
	{
		x=x*10;
		cnt=x;
		num=num*10;
	}
	int y=gcd(cnt,num);
	if(num/y==1) cout<<cnt/y;
	else cout<<cnt/y<<"/"<<num/y;
}
int search(int x)
{
	int num=1;
	for(int i=1;i<=sqrt(x)+1;i++)
	{
		if(x%(i*i)==0) num=i;
	}
	return num;
}
void find2(double x,double z)
{
	int cnt=x,num=1;
	while(x-cnt!=0)
	{
		x=x*10;
		cnt=x;
		num=num*10;
	}
	int y=gcd(cnt,num);
	if(num/y==1) cout<<cnt/y<<"*sqrt("<<z<<")"<<endl;
	else if(cnt/y==1) cout<<"sqrt("<<z<<")/"<<num/y<<endl;
	else cout<<cnt/y<<"*sqrt("<<z<<")/"<<num/y<<endl;
}
int main()
{
	cin>>t>>m;
	while(t--)
	{
		cin>>a>>b>>c;
		d=b*b-4*a*c;
		if(d<0)
		{
			cout<<"NO"<<endl;
			continue;
		}
		double x;
		x=max(((sqrt(d)-b)/(2*a)),((0-sqrt(d)-b)/(2*a)));
		if(x==0)
		{
			if(min(((sqrt(d)-b)/(2*a)),((0-sqrt(d)-b)/(2*a)))==0)
			{
				cout<<"0"<<endl;
				continue;
			}
			else x=min(((sqrt(d)-b)/(2*a)),((0-sqrt(d)-b)/(2*a)));
		}
		if(int(sqrt(d))*sqrt(d)==d)		 //ÕûÊýÅÐ¶Ï
		{
			if(x<0) cout<<"-";
			find(abs(x));
			cout<<endl;
			continue;
		}
		double c=(0.0-b)/(2*a);
		if(c!=0)
		{
			if((0-b)/(2*a)<0) cout<<"-";
			find(abs(c));
			cout<<"+";
		}
		double u=search(d/(4*a*a));
		find2(u,d/(u*u*4*a*a));
		//cout<<x;
	}
	return 0;
}