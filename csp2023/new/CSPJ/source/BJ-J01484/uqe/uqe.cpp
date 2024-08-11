#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a,b,c,delta,maxn;
	double x1,x2;
	for(long long i=1;i<=n;i++)
	{
		cin>>a>>b>>c;
		delta=pow(b,2)-4*a*c;
		if(delta<0)
		{
			cout<<"NO"<<endl;
			continue;
		}
		else
		{
			x1=(-b+sqrt(delta))/2*a;
			x2=(-b-sqrt(delta))/2*a;
			maxn=max(x1,x2);
			cout<<maxn<<endl;
		}
	}
	return 0;
}

