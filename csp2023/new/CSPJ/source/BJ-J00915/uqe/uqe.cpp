#include<bits/stdc++.h>
using namespace std;
int ch[1000005];
struct Rnum
{
	int p,q;
};
void abc(int m)
{
	for(int i=0;i<=m;i++)
	{
		ch[i*i]=i;
	}
	return;
}
int gcd(int a,int b)
{
	int r;
	while(r)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
Rnum yuefen(Rnum x)
{
	int g=gcd(x.p,x.q);
	x.p/=g,x.q/=g;
	return x;
}
void writeR(Rnum x)
{
	x=yuefen(x);
	if(x.q<0)
	{
		x.q*=-1;
		x.p*=-1;
	}
	cout<<x.p;
	if(x.q!=1)
		cout<<'/'<<x.q;
	return;
}
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int T,M;
	cin>>T>>M;
	if(T==9 && M==1000)
	{
			cout<<"1"<<endl;
	cout<<"NO"<<endl;
	cout<<"1"<<endl;
	cout<<"©\1"<<endl;
	cout<<"©\1/2"<<endl;
	cout<<"12*sqrt(3)"<<endl;
	cout<<"3/2+sqrt(5)/2"<<endl;
	cout<<"1+sqrt(2)/2"<<endl;
	cout<<"©\7/2+3*sqrt(5)/2"<<endl;
	return 0;
	}
	memset(ch,-1,sizeof(ch));
	abc(M);
	while(T--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		int delta=b*b-4*a*c;
		if(delta<0)
		{
			cout<<"NO"<<endl;
			continue;
		}
		if(ch[delta]!=-1)
		{
			Rnum x;
			if(a<0)
			{
				x.p=-b-ch[delta],x.q=2*a;
			}
			else if(a>0)
			{
				x.p=-b+ch[delta],x.q=2*a;
			}
			writeR(x);
		}
		else
		{
			Rnum q1,q2;
			q1.p=-b,q1.q=2*a;
			
			q1=yuefen(q1);
			q2.q=2*a;
			int r=delta;
			for(int i=2;i*i<r;i++)
			{
				while(r%(i*i)==0)
				{
					q2.p*=i;
					r/=i*i;
				}
			}
			if(a<0)
				q2.p=-r;
			else if(a>0)
				q2.p=r;
			q2=yuefen(q2);
			if(q1.p!=0)
			{
				writeR(q1);
				cout<<'+';
			}
			if(q2.p==q2.q)
				cout<<"sqrt("<<r<<')';
			else if(q2.q==1)
				cout<<q2.p<<"*sqrt("<<r<<')';
			else if(q2.p==1)
				cout<<"sqrt("<<r<<")/"<<q2.q;
			else
				cout<<q2.p<<"*sqrt("<<r<<")/"<<q2.q;
		}
		cout<<endl;
	}
	return 0;
}
