#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
char a[3005][3005];
string s[3005][2];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		sort(a[i],a[i]+m);
		s[i][0]=a[i];
		for(ll j=m-1;j>=0;j--) s[i][1]+=a[i][j];
	}
	for(ll i=1;i<=n;i++)
	{
		bool f=1;
		for(ll j=1;j<=n;j++)
		{
			if(s[i][0]>s[j][1])
			{
				f=0;
				break;
			}
		}
		cout<<f;
	}
	return 0;
}