#include <bits/stdc++.h>
using namespace std;
const int N=1e7;
int m,t;
int vis[N];
int gcd(int a,int b)
{
	return b==0?a:gcd(a,b);
}
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin>>t>>m;
	int a,b,c;
	memset(vis,-1,sizeof(vis));
	vis[0]=0;
	for (int i=1;i<=3000;i++) vis[i*i]=i;
	for (int i=1;i<=t;i++)
	{
		cin>>a>>b>>c;
		int derta=b*b-4*a*c;
		int era=2*a;
		int bfang=b*b;
		if (derta<0)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			int x1m=(-b-vis[derta]);
			int x1z=era;
			int x2m=(-b+vis[derta]);
			int x2z=era;
			//cout<<x1m<<"/"<<x1z<<endl;
			//cout<<x2m<<"/"<<x2z<<endl;
			int x1=x1m/x1z;
			int x2=x2m/x2z;
			cout<<max(x1,x2)<<endl;
		}
	}
	return 0;
}