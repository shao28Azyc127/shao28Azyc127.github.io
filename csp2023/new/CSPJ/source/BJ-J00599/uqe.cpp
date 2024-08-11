#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=114514;

inline ll gcd(ll x,ll y)
{
	if (y==0) return x;
	return gcd(y,x%y);
}
inline void print(ll p,ll q,char ed='\n')
{
	ll g=gcd(p,q);
	p/=g; q/=g;
	if (q<0) p=-p,q=-q;
	if (q==1) cout<<p<<ed;
	else cout<<p<<'/'<<q<<ed;
}

int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	ll T,M;
	cin>>T>>M;
	while (T--)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		ll delta=b*b-4*a*c;
		if (delta<0)
		{
			cout<<"NO\n";
			continue;
		}
		ll u=sqrt(delta);
		if (u*u==delta)
		{
			if (2*a>0) print(-b+u,2*a);
			else print(-b-u,2*a);
			continue;
		}
		if (-b) print(-b,2*a,'+');
		ll q2=u;
		for (;q2;q2--) if (delta%(q2*q2)==0) break;
		delta=delta/q2/q2;
		u=q2; ll v=2*a,g=gcd(u,v); u=abs(u/g),v=abs(v/g);
		if (u%v==0&&u/v==1) cout<<"sqrt("<<delta<<")\n";
		else if (u%v==0) cout<<u/v<<"*sqrt("<<delta<<")\n";
		else if (v%u==0) cout<<"sqrt("<<delta<<")/"<<v/u<<"\n";
		else cout<<u<<"*sqrt("<<delta<<")/"<<v<<'\n';
	}
	
	return 0;
}
