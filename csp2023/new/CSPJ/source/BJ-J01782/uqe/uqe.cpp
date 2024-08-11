#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b)
{
	if(min(a,b))
	{
		return a;
	}
	return gcd(max(a,b),max(a,b)%min(a,b));
}
void print(double n)
{
	long long rn=n*1000000;
	long long rb=1000000;
	int flag=0;
	if(rn<0)
	{
		flag=1;
	}
	rn=abs(rn);
	while(gcd(rn,rb)!=1)
	{
		int t=gcd(rn,rb);
		rn/=t;
		rb/=t;
	}
	if(rb==1)
	{
		if(flag)
		{
			cout<<-rn;
		}
		else
		{
			cout<<rn;
		}
	}
	else
	{
		if(flag)
		{
			cout<<-rn<<"/"<<rb;
		}
		else
		{
			cout<<rn<<"/"<<rb;
		}
	}
	return ;
}
void printn(double xa,double tr,double a,double b,int type)
{
	double q1=-b*(1/(2*a));
	double q2=(1/(2*a));
	double r;
	if(type==1)
	{
		r=sqrt(tr);
	}
	else
	{
		r=-sqrt(tr);
	}
	cout<<q1<<" "<<q2<<" "<<r<<endl;
	if(q1!=0)
	{
		print(q1);
		cout<<"+";
	}
	if(q2==1)
	{
		cout<<"sqrt("<<r<<")";
	}
	else if((long long)q2==q2)
	{
		cout<<q2<<"*sqrt("<<r<<")";
	}
	else if((long long)1/q2==q2)
	{
		cout<<"sqrt("<<r<<")/"<<1/q2;
	}
	else
	{
		long long rn=q2*1000000;
		long long rb=1000000;
		rn=abs(rn);
		while(gcd(rn,rb)!=1)
		{
			int t=gcd(rn,rb);
			rn/=t;
			rb/=t;
		}
		cout<<rn<<"*sqrt("<<r<<")/"<<rb;
	}
	return ;
}
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int T,M;
	cin>>T>>M;
	while(T--)
	{
		double a,b,c;
		cin>>a>>b>>c;
		double tr=b*b-4*a*c;
		if(tr<0)
		{
			cout<<"NO"<<endl;
			continue;
		}
		else
		{
			int flxa=0,flxb=0;
			double xa=sqrt(tr);
			if(xa*xa!=tr)
			{
				flxa=1;
			}
			xa-=b;
			xa/=2*a;
			double xb=-sqrt(tr);
			if(xb*xb!=tr)
			{
				flxb=1;
			}
			xb=xb+(-b);
			xb/=2*a;
			if(xa>xb)
			{
				if(flxa==0)
				{
					print(xa);
					cout<<endl;
				}
				else if(flxa==1)
				{
					printn(xa,tr,a,b,1);
					cout<<endl;
				}
			}
			else
			{
				if(flxb==0)
				{
					print(xb);
					cout<<endl;
				}
				else if(flxb==1)
				{
					printn(xb,tr,a,b,2);
					cout<<endl;
				}
			}
			
		}
	}
	return 0;
}
