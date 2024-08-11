#include<bits/stdc++.h>
using namespace std;
const int maxm=1e3+5;
int t,m,a,b,c,sq[maxm],x;
inline int dt(int a,int b,int c)
{
	return b*b-(4*a*c);
}
int gcd(int i,int j)
{
	if(i%j==0) return j;
	else return gcd(j,i%j);
}
void print(int d)
{
	bool dc=0,dc1=0,q1=0;
	int q=1;
	a*=2;
	b*=-1;
	for(int i=0;i<=m;i++)
	{
		while(i>1 && d%sq[i]==0) 
		{
			q*=i;
			d=d/sq[i];
		}
		if(d==1 || d==0)
		{
			dc=1;
			if(i<2) dc1=1;
			break;
		}
	}
	if(dc==1)
	{
		int u=b;
		if(dc1==1) u+=d;
		else u+=q;
		if(u==0)
		{
			printf("0");
			return;
		}
		if(u*a<0)
		{
				printf("-");
				a=abs(a);
				u=abs(u);
		}
		if(u%a==0) printf("%d",u/a);
		else
		{
			int g=gcd(max(u,a),min(u,a));
			printf("%d/%d",u/g,a/g);
		}
	}
	else
	{
		if(a*b<0) q1=1;
		a=abs(a);
		b=abs(b);
		if(b!=0)
		{
			if(q1==1) printf("-");
			if(max(a,b)%min(a,b)==0) printf("%d",b/a);
			else
			{
				int g=gcd(max(a,b),min(a,b));
				printf("%d/%d",b/g,a/g);
			}
			printf("+");	
		}
		int g=gcd(max(a,q),min(a,q));
		a=a/g;
		q=q/g;
		if(a==1 && q==1) printf("sqrt(%d)",d);
		else if(a==1) printf("%d*sqrt(%d)",q,d);
		else if(q==1) printf("sqrt(%d)/%d",d,a);
		else printf("%d*sqrt(%d)/%d",q,d,a);
	}
	return;
}
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin>>t>>m;
	for(int i=0;i<=m;i++)
	{
		sq[i]=i*i;
	}
	for(int i=0;i<t;i++)
	{
		cin>>a>>b>>c;
		int d=dt(a,b,c);
		if(d<0) cout<<"NO";
		else print(d);
		cout<<endl;
	}
	return 0;
}