#include<bits/stdc++.h>
using namespace std;
int T,M;
int dt;
int u;
int gcd(int a,int b)
{
	int k=min(a,b);
	int ans=1;
	for(int i=2;i<=k;i++)
	{
		while(a%i==0 && b%i==0)
		{
			ans*=i;
			a/=i;
			b/=i;
			k=min(a,b);
		}
	}
	return ans;
}
double derta(int a,int b,int c)
{
	return b*b-4*a*c;
}
void output(int a,int b,int dt)
{
	//cout<<a<<" "<<b<<" "<<dt<<endl;
	if(u<0) b=b-dt;
	else b=b+dt;
//	cout<<a<<" "<<b<<endl;
	a=abs(a),b=abs(b);
	int k=gcd(2*a,b);
	if(((2*a)/k)==1) cout<<b/k;
	else cout<<b/k<<"/"<<(2*a)/k;
}
bool sqt(int x)
{
	int k=sqrt(x);
	if(k*k==x) return true;
	else return false;
}
int find_max(int dt)
{
	int ans=1;
	for(int i=2;i<=dt;i++)
	{
		while(sqt(i) && dt%i==0)
		{
			ans=ans*sqrt(i);
			dt/=i;
		}
	}
	return ans;
}
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin>>T>>M;
	while(T--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		u=b;
		dt=derta(a,b,c);
		if(dt<0)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			if(a*b>0) cout<<"-";
			if(dt==0)
			{
				output(a,b,0);
				cout<<endl;
			}
			else if(dt>0)
			{
				if(sqt(dt))
				{
					output(a,b,sqrt(dt));
					cout<<endl;
				}
				else
				{
					int q2=find_max(dt);
					bool flag=0;
					if(b!=0) 
					{
						output(a,b,0);
						cout<<"+";
						flag=1;
					}
					if(q2==1) 
					{
						cout<<"sqrt("<<dt<<")/"<<2*a<<endl;
					}
					else
					{
						dt=dt/(q2*q2);
						q2=abs(q2),a=abs(a);
						int k=gcd(2*a,q2);
					//	cout<<endl<<"a : "<<2*a/k<<endl;
						if(((2*a)/k)==1) 
						{
							if(q2/k!=1)
							cout<<q2/k<<"*"<<"sqrt("<<dt<<")"<<endl;
							else
							cout<<"sqrt("<<dt<<")"<<endl;
						}
						else if(q2/k!=1) cout<<q2/k<<"*sqrt("<<dt<<")/"<<(2*a)/k<<endl;
						else
						cout<<"sqrt("<<dt<<")/"<<(2*a)/k<<endl;
					}
				}
			}
		}
	}
	return 0;
}