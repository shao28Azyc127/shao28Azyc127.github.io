#include<bits/stdc++.h>
using namespace std;

int T,m;

bool ispf(int x)
{
	double y=1.0*x;
	return sqrt(y)*sqrt(y)==y;
}
int gcd(int p,int q)
{
	if(p<q) swap(p,q);
	if(p%q==0) return q;
	else 
	{
		int r=p/q;
		gcd(p-r*q,q);
	}
	

}

int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	
	cin>>T>>m;
	for(int k=1;k<=T;k++) 
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(b*b-4*a*c<0)
		{
			cout<<"No"<<endl;
			continue;
		}
		else
		{
			int dta=b*b-4*a*c;
			if(ispf(dta))
			{
				int p=-b+sqrt(dta),q=2*a;
				if((p>0 && q<0) || (p<0 && q>0)) cout<<"-";
				p=abs(p); q=abs(q);
				int r=gcd(p,q);
				p/=r; q/=r;
				if(q==1) cout<<p<<endl;
				else cout<<p<<"/"<<q<<endl;
				continue;
			}
			else 
			{
				cout<<"wobuhui"<<endl;
				continue;
			}
		}
	}
	
	return 0;
}
