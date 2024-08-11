#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
vector<int> v[10005];
int D(int x,int y)
{
	if(y>x) x+=10;
	return x-y;
}
bool check(vector<int> &x,vector<int> &y)
{
	vector<pair<int,int> > v;
	for(int i=0;i<5;i++)
	{
		if(x[i]!=y[i])
			v.push_back({i,D(y[i],x[i])});
	}
	if(v.size()>=3||v.size()==0) return 0;
	if(v.size()==2&&v[1].first-v[0].first!=1) return 0;
	if(v.size()==2&&v[1].second-v[0].second!=0) return 0;
	return 1;
}
signed main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=5;j++)
		{
			int x;
			cin >> x;
			v[i].push_back(x);
		}
	}
	int ans=0;
	for(int a1=0;a1<=9;a1++)
	for(int a2=0;a2<=9;a2++)
	for(int a3=0;a3<=9;a3++)
	for(int a4=0;a4<=9;a4++)
	for(int a5=0;a5<=9;a5++)
	{
		vector<int> s={a1,a2,a3,a4,a5};
		++ans;
		int ok=1;
		for(int j=1;j<=n;j++)
		{
			if(!check(s,v[j]))
			{
				ok=0;
				--ans;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}