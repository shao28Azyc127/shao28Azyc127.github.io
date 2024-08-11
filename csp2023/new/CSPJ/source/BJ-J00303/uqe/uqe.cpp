#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0,f=1;char c=getchar();
	while(!(c>='0'&&c<='9'))
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		ret=ret*10+c-'0';
		c=getchar();
	}
	return ret*f;
}
int t,m;
double a,b,c;
void yl(int p,int q)
{
	if(q<0) q*=-1,p*=-1;
	int g=__gcd(abs(p),abs(q));
	p/=g,q/=g;
	if(q==1) printf("%d",p);
	else if(q==p) printf("1");
	else printf("%d/%d",p,q);
}
int aa[100005],bb[100005],cc[100005];
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	t=read(),m=read();
	for(int i=1;i<=t;i++)
	{
		aa[i]=read(),bb[i]=read(),cc[i]=read();
	}
	for(int g=1;g<=t;g++)
	{
		a=aa[g],b=bb[g],c=cc[g];
		double derta=b*b-4*a*c;
		if(derta<0){cout<<"NO\n";continue;} 
		double x=max((-1*b+abs(sqrt(derta)))/2.0/a,(-1*b-abs(sqrt(derta)))/2.0/a);
		int ch=derta;int v=sqrt(ch);
		if(v*v==ch) 
		{
			if(a<0)
			{
				int p=-1*b-abs(sqrt(ch)),q=2*a;
				yl(p,q);
				cout<<"\n";
			}
			else
			{
				int p=-1*b+abs(sqrt(ch)),q=2*a;
				yl(p,q);
				cout<<"\n";
			}
			
		}
		else 
		{
			if(a>0)
			{	
				double q1=-1*b/2.0/a,q2=1/2.0/a,r=derta;
				int f=r,tmp=1;
				for(int i=2;i*i<=f;i++)
				{
					while(f%(i*i)==0)
					{
						// cout<<i<<endl;
						q2*=i,tmp*=i;
						f/=i;f/=i;r/=i;r/=i;
					}
				}
				// cout<<q2<<' '<<r<<endl;
				if(q1!=0)
				{
					yl(-1*b,2*a);cout<<"+";
				}
				int l=q2,k=1.0/q2;
				if(q2==l&&l==1) cout<<"sqrt("<<r<<')';
				else if(q2==l)
				{
					cout<<q2<<"*sqrt("<<r<<')';
				}
				else if(1/q2==k)
				{
					cout<<"sqrt("<<r<<")/"<<1/q2;
				}
				else
				{
					int p=tmp,q=2*a;
					if(q<0) q*=-1,p*=-1;
					for(int i=2;i*i<=q;i++)
					{
						while(q%i==0&&abs(p)%i==0)
						{
							p/=i;q/=i;
						}
					}
					cout<<p<<"*sqrt("<<r<<")/"<<q;
				}
				cout<<"\n";
			}
			else
			{
				double q1=-1*b/2.0/a,q2=-1/2.0/a,r=derta;
				int f=r,tmp=1;
				for(int i=2;i*i<=f;i++)
				{
					while(f%(i*i)==0)
					{
						q2*=i;tmp*=i;
						f/=i;f/=i;r/=i;r/=i;
					}
				}
				if(q1!=0)
				{
					yl(-1*b,2*a);cout<<"+";
				}
				int l=q2,k=1/q2;
				if(q2==l&&l==1) cout<<"sqrt("<<r<<')';
				else if(q2==l)
				{
					cout<<q2<<"*sqrt("<<r<<')';
				}
				else if(1/q2==k)
				{
					cout<<"sqrt("<<r<<")/"<<1/q2;
				}
				else
				{
					int p=-1*tmp,q=2*a;
					if(q<0) q*=-1,p*=-1;
					for(int i=2;i*i<=q;i++)
					{
						while(q%i==0&&abs(p)%i==0)
						{
							p/=i;q/=i;
						}
					}
					cout<<p<<"*sqrt("<<r<<")/"<<q;
				}
				cout<<"\n";
			}
		}
	}

	return 0;
}