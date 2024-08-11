#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d,v[100010],a[100010];
vector<int>rd;
void ss()
{
	int sm=0;
	for (int i=2;i<=n;i++) sm+=v[i];
	int dd=(sm%d==0?sm/d:sm/d+1);
	cout<<dd*a[1];
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>d;
	for (int i=2;i<=n;i++) cin>>v[i];
	int mn=1000000000;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		mn=min(mn,a[i]);
	}
	if (a[1]==mn)
	{
		ss();
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		int pt=i;
		while (pt<=n&&a[pt]>=a[i]) pt++;
		if (pt<=n) rd.push_back(pt);
		i=pt-1;
	}
	v[1]=0;
	for (int i=1;i<=n;i++) v[i]+=v[i-1];
	int res=0,fg=1,rez=0;
	for (int i=0;i<(int)rd.size();i++)
	{
		int you=((v[rd[i]]-v[fg]-rez)%d==0?(v[rd[i]]-v[fg]-rez)/d:(v[rd[i]]-v[fg]-rez)/d+1);
		res+=you*a[fg];
		rez=you*d-(v[rd[i]]-v[fg]-rez);
		fg=rd[i];
	}
	cout<<res;
	return 0;
}
