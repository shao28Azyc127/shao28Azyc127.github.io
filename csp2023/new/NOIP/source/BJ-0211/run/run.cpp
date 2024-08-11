//NOIP2023 RP++
#include<iostream>
using namespace std;
#define int long long
const int N=1e5+5;
int c,t,n,m,k,d,ans,x[N],y[N],v[N],l[N],r[N],c[N];
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>m>>k>>d;
		for(int i=1;i<=m;i++)
		{
			cin>>x[i]>>y[i]>>v[i];
			l[i]=x[i]-y[i]+1;
			r[i]=x[i];
			if(l[i]==r[i-1]+1)
			{
				v[i]+=v[i-1];
				v[i-1]=0;
				l[i]=l[i-1];
				l[i]=-1;
				r[i]=0;
				y[i]+=y[i-1];
				y[i-1]=0;
			}
		}
		for(int i=1;i<=m;i++)
		{
			if(y[i]<=k&&y[i]*d>=v)	ans+=y[i]*d-v;
		}
		cout<<ans;
	}
	return 0;
}
