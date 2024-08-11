#include<bits/stdc++.h>
#define F
using namespace std;

struct Node
{
	int q2,r;
};

int T,M;

inline int Delta(int a,int b,int c)
{
	return b*b-4*a*c;
}

inline bool Check2()
{
	return false;
}

int gcd(int a,int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}

void Output1(int a,int b,int c,int sq)
{
	int p=0,q=0;
	q=2*a;
	if(q>0)
		p=max((b*-1)+sq,(b*-1)-sq);
	else
		p=min((b*-1)+sq,(b*-1)-sq);
	int mx=gcd(p,q);
	p/=mx;
	q/=mx;
	if(q<0)
	{
		p*=-1;
		q*=-1;
	}
	//output
	if(q==1)
		cout<<p<<endl;
	else
		cout<<p<<'/'<<q<<endl;
}

void Output2(int a,int b,int c,int sq)
{
	int p=0,q=0;
	q=2*a;
	p=b*-1;
	int mx=gcd(p,q);
	p/=mx;
	q/=mx;
	if(q<0)
	{
		p*=-1;
		q*=-1;
	}
	//output
	if(q==1)
		cout<<p<<endl;
	else
		cout<<p<<'/'<<q<<endl;
}

Node SQint(Node x)
{
	int q2=x.q2,r=x.r;
	for(int i=2;i*i<=r;i++)
	{
		while(r%(i*i)==0)
		{
			r/=(i*i);
			q2*=i;
		}
	}
	x.q2=q2;
	x.r=r;
	return x;
}

int main()
{
	#ifdef F
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	#endif
	cin>>T>>M;
	while(T--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		int D=Delta(a,b,c);
		if(D<0)
		{
			cout<<"NO"<<endl;
			continue;
		}
		int sq=sqrt(D);
		if(sq*sq==D)//有理数 
			Output1(a,b,c,sq);
		else//无理数 
		{
			int q1=(b*-1),q2u=1,q2d,r=D;
			q2d=2*a;
			//
			Node x;
			x.q2=q2u;
			x.r=r;
			x=SQint(x);
			q2u=x.q2;
			r=x.r;
			//
			//output
			if(q1!=0)
			{
				Output2(a,b,c,sq);
				cout<<'+';
			}
			if(q2u==1&&q2d==1)
				cout<<"sqrt("<<r<<")"<<endl;
			if(q2d==1)
				cout<<q2u<<"*sqrt("<<r<<")"<<endl;
		}
	}
	return 0;
}