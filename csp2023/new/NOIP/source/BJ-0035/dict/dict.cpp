#include<bits/stdc++.h>
using namespace std;
const int MAXN=3005;
int n,m,cnt[30],frm;
string str[MAXN],mx[MAXN],mn[MAXN];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	frm=1;
	for(int i=1;i<=n;i++)
	{
		cin>>str[i];
		for(int i=0;i<26;i++) cnt[i]=0;
		for(int j=0;j<str[i].size();j++) cnt[str[i][j]-'a']++;
		for(int j=0;j<26;j++)
		{
			int tmp=cnt[j];
			while(tmp--) mn[i].push_back(j+'a');
		}
		for(int j=25;j>=0;j--)
		{
			int tmp=cnt[j];
			while(tmp--) mx[i].push_back(j+'a');
		}
		if(mx[i]<mx[frm]) frm=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(i==frm)
		{
			bool flag=1;
			for(int j=1;j<=n;j++)
				if(j!=i&&mx[j]<=mn[i]) flag=0;
			cout<<flag;
		}
		else if(mn[i]<mx[frm]) cout<<1;
		else cout<<0;
	}
	putchar('\n');
	return 0;
}