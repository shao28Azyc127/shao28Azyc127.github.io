#include<bits/stdc++.h>
using namespace std;
int T,M,a,b,c;
int gcd(int x,int y)
{
	if(y==0) return x;
	return gcd(y,x%y);
}
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin>>T>>M;
	while(T--)
	{
		cin>>a>>b>>c;
		if(b*b-4*a*c<0) cout<<"NO"<<endl;
		else 
		{
			int p=b*b-4*a*c;
			//cout<<p<<endl;
			double x=(-1*b+sqrt(p))/(2*a);
			double xx=(-1*b-sqrt(p))/(2*a);
			int X=x;
			int XX=xx;
			if(x-X==0&&xx-XX==0) cout<<max(X,XX)<<endl;
			else if(x-X==0) cout<<x<<endl;
			else if(xx-XX==0) cout<<xx<<endl;
			else
			{	double t=sqrt(p);
				int m=t;
				if(t-m==0) 
				{
					int g=gcd(b+m,2*a),qwq=1;
					if(2*a/g<0) qwq=-1; 
					if((-1*b+m)/g<0) qwq=1;
					if((-1*b+m)/g<0&&2*a/g<0) qwq=-1;
					cout<<(-1*b+m)/g*qwq<<"/"<<abs(2*a/g)<<endl;
				}
				else 
				{
					
					if(b!=0) 
					{
						int g=gcd(-1*b,2*a),qwq=1;
						if(2*a/g<0) qwq=-1; 
						if(-1*b/g<0) qwq=1;
						if(2*a/g<0&&-1*b/g<0) qwq=-1;
						if(b%(2*a)==0) cout<<(-1*b)/(2*a)<<"+";
						else cout<<(-1*b)/g*qwq<<"/"<<abs((2*a)/g)<<"+";
					}
					//cout<<"sqrt("<<p<<")/"<<2*a<<endl;
					int n=0;
					for(int i=2;i<=M;i++)
					{
						if(p%(i*i)==0)
						{
							n=i;
						}
					}
					if(n!=0)
					{
						int g=gcd(n,2*a),qwq=1;
						if(2*a/g<0) qwq=-1; 
						if(n/g<0) qwq=1;
						if(n/g<0&&2*a/g<0) qwq=-1;
						if(n%(2*a)==0) 
						{
							if(n/(2*a)!=1&&n/(2*a)!=-1) cout<<abs(n/(2*a))<<"*"<<"sqrt("<<p/(n*n)<<")"<<endl;
							else cout<<"sqrt("<<p/(n*n)<<")"<<endl;
						}
						else 
						{
							if(n/g*qwq!=1&&n/g*qwq!=-1) cout<<n/g*qwq<<"*"<<"sqrt("<<p/(n*n)<<")/"<<abs(2*a/g)<<endl;
							else cout<<"sqrt("<<p/(n*n)<<")/"<<abs(2*a/g)<<endl;
							
						}
					}
					else
					{
						cout<<"sqrt("<<p<<")/"<<abs(2*a)<<endl;
					}
				}
			}
			
		}
	}
}
