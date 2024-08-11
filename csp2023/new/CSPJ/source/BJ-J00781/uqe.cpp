#include<bits/stdc++.h>
using namespace std;
int n,a,b,c,t,tmp;
int gcd(int x,int y)
{
	int a=x,b=y;
	x=max(a,b);
	y=min(a,b);
	if(y==0||x==0)
	return 1;
	if(x%y==0)
	{
		return y;
	}
	return gcd(y,x%y);
}
int yinfen(int k)
{
	int ans=1;
	for(int i=2;i<=k;i++)
	{
		if(k%i==0)
		{
			int sum=0;
			while(k%i==0)
			{
				k=k/i;
				sum++;
				if(sum==2)
				{
					sum=0;
					ans*=i;
				}
			}
		}
	}
	return ans;
}
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin >> n >> t;
	for(int i=1;i<=n;i++)
	{
		cin >> a >> b >> c;
		if(b*b-4*a*c<0)
		{
			cout << "NO"<< endl;
			continue;
		}
		else if(b*b==4*a*c)
		{
			tmp=sqrt(b*b-4*a*c);
			tmp=-b+tmp;
			if(tmp==0)
			cout << "0"<< endl;
			else if(tmp%(2*a)==0)
			{
				cout << tmp/(2*a)<< endl;
			}
			else
			{
				int w=gcd(max(abs(tmp),abs(2*a)),min(abs(tmp),abs(2*a)));
				 if(a<0)
					cout << "-"<< tmp/w << "/"<< -2*a/w<< endl;
				else 
					cout << tmp/w << "/"<< 2*a/w<< endl;
			}
		}
		else
		{
			 tmp=b*b-4*a*c;
			 int d=yinfen(tmp);
			 if(tmp==d*d)//pingfangshu
			 {
			 	tmp=-b+d;
			 	int w=gcd(max(abs(tmp),abs(2*a)),min(abs(tmp),abs(2*a)));
			 	if(2*a/w==1)
			 	cout << tmp/w << endl;
				else if(a<0)
					cout << "-"<< tmp/w << "/"<< -2*a/w<< endl;
				else 
					cout << tmp/w << "/"<< 2*a/w<< endl;
			 }
			else
			{
				
				tmp=tmp/(d*d);
				int w=gcd(abs(d),abs(2*a));
				w=gcd(abs(b),abs(w));
				if(abs(2*a/w)==1&&b!=0)
			 		cout << -b/w<<"/"<<-2*a/w<<"+"<<d/w<<"*sqrt("<< tmp<<")" << endl;
				else if(a>0)
				{
					if(b!=0)
					{
						if(d/w!=1)
						cout << b/w<<"+"<< d/w<<"*sqrt("<<tmp<<")/"<< 2*a/w<< endl;
						else
						cout << b/w<<"+"<<"sqrt("<<tmp<<")/"<< 2*a/w<< endl;
					}
					else
					{
						 w=gcd(abs(d),abs(2*a));
						 if(d/w!=1&&2*a/w!=1)
						cout<< d/w<<"*sqrt("<<tmp<<")/"<< 2*a/w<< endl;
						else if(2*a/w==1)
						cout<< d/w<<"*sqrt("<<tmp<<")"<< endl;
						else
						cout<< "sqrt("<<tmp<<")/"<< 2*a/w<< endl;
					}
					
				}
				
				else
				{
					if(b!=0)
					cout << -b/w<<"/"<<-2*a/w<<"+"<< d/w<<"*sqrt("<<tmp<<")/"<< -2*a/w<< endl;
					else
					{
						 w=gcd(abs(d),abs(2*a));
						if(d/w!=1&&2*a/w!=1)
						cout<< d/w<<"*sqrt("<<tmp<<")/"<< 2*a/w<< endl;
						else if(2*a/w==1)
						cout<< d/w<<"*sqrt("<<tmp<<")"<< endl;
						else
						cout<< "sqrt("<<tmp<<")/"<< 2*a/w<< endl;
					}
				}
			}
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
