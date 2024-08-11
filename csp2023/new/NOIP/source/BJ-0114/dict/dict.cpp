#include<bits/stdc++.h>
#define int long long
using namespace std;
string s[3005];
string p[3005],d[3005];
int cnt[50];
signed main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m;cin>>n>>m;
	if(n==1) 
	{
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++)
	{
		string tmp=s[i];
		for(int j=0;j<m;j++)
		{
			cnt[s[i][j]-'a'+1]++;
		}
		int now=0;
		for(int j=26;j>=1;j--)
		{
			while(cnt[j])
			{
				tmp[now]=j+'a'-1;
				now++;
				cnt[j]--;
			}
		}
		if(i==1) p[i]=tmp;
		else p[i]=min(p[i-1],tmp);
	}
	for(int i=n;i>=1;i--)
	{
		string tmp=s[i];
		for(int j=0;j<m;j++)
		{
			cnt[s[i][j]-'a'+1]++;
		}
		int now=0;
		for(int j=26;j>=1;j--)
		{
			while(cnt[j])
			{
				tmp[now]=j+'a'-1;
				now++;
				cnt[j]--;
			}
		}
		if(i==n) d[i]=tmp;
		else d[i]=min(d[i+1],tmp);
	}
	for(int i=1;i<=n;i++)
	{
		string tmp=s[i];
		for(int j=0;j<m;j++)
		{
			cnt[s[i][j]-'a'+1]++;
		}
		int now=0;
		for(int j=1;j<=26;j++)
		{
			while(cnt[j])
			{
				tmp[now]=j+'a'-1;
				now++;
				cnt[j]--;
			}
		}
		if(i==1) cout<<(tmp<d[i+1]);
		else if(i==n) cout<<(tmp<p[i-1]);
		else cout<<(tmp<d[i+1]&&tmp<p[i-1]);
	}
}