#include<bits/stdc++.h>
using namespace std;
int n,m;
int to[30];
int t1[30],f1;
int t2[30],f2;
string s1[3005];
string a,b;
signed main()
{
	// system("deff dict4.ans 1.out");
	// return 0;
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	memset(t1,0x3f,sizeof(t1));
	memset(t2,0x3f,sizeof(t2));
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		memset(to,0,sizeof(to));
		cin>>s1[i];
		for(int j=0;j<m;j++) to[s1[i][j]-'a']++;
		int f=0;
		for(int j=25;j>=0;j--)
		{
			if(to[j]<t1[j])
			{
				f=1;
				break;
			}
			if(to[j]>t1[j]) break;
		}
		if(f)
		{
			for(int j=0;j<26;j++) t2[j]=t1[j],t1[j]=to[j];
			f2=f1,f1=i;
			continue;
		}
		for(int j=25;j>=0;j--)
		{
			if(to[j]<t2[j])
			{
				f=1;
				break;
			}
			if(to[j]>t2[j]) break;
		}
		if(f)
		{
			for(int j=0;j<26;j++) t2[j]=to[j];
			f2=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int fl=0;
		memset(to,0,sizeof(to));
		for(int j=0;j<m;j++) to[s1[i][j]-'a']++;
		for(int j=0;j<26;j++)
		{
			for(int k=1;k<=to[j];k++) a+=char(j+'a');
		}
		if(i!=f1)
		{
			for(int j=25;j>=0;j--)
			{
				for(int k=1;k<=t1[j];k++) b+=char(j+'a');
			}
		}
		else
		{
			for(int j=25;j>=0;j--)
			{
				for(int k=1;k<=t2[j];k++) b+=char(j+'a');
			}
		}
		if(a<b) cout<<1;
		else cout<<0;
		a="",b="";
	}
}