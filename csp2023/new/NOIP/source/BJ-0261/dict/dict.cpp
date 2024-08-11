#include<bits/stdc++.h>
using namespace std;
string s[3010];
string mmin[3010],mmax[3010];
int h[3010][26];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		for(int j=0;j<m;j++)
		{
			h[i][s[i][j]-'a']++;
		}
		for(int j=0;j<26;j++)
		{
			int cnt=h[i][j];
			while(cnt!=0)
			{
				char x=j+'a';
				mmin[i]+=x;
				cnt--;
			}
		}
		for(int j=25;j>=0;j--)
		{
			int cnt=h[i][j];
			while(cnt!=0)
			{
				char x=j+'a';
				mmax[i]+=x;
				cnt--;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		int f=1;
		for(int j=1;j<=n;j++)
		{
			if(i!=j&&mmin[i]>=mmax[j])
			{
				f=0;
			}
		}
		cout<<f;
	}
    return 0;
}
