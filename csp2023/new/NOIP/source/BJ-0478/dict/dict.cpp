#include<bits/stdc++.h>
#include<cstdio>
#include<string>
using namespace std;
const int N=3e4+5;
int n,m;
struct node
{
	int id;
	string s,sn,sx;
}a[N];
bool ans[N];
char c[N];
int cmp(node p,node q)
{
	return p.s<q.s;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].s;
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	int tmp,t;
	for(int i=1;i<=n;i++)
	{
		a[i].sn=a[i].sx=a[i].s;
		for(int j=0;j<m;j++)
			c[j]=a[i].s[j];
		tmp=0;
		sort(c,c+m);
		for(int j=0;j<m;j++)
			if(a[i].s[j]!=c[j])
			{
				tmp=j;
				break;
			}
		for(int j=m-1;j>=0;j--)
			if(a[i].s[j]==c[tmp])
			{
				swap(a[i].sn[j],a[i].sn[tmp]);
				break;
			}
		if(a[i].sn>a[i].s)	a[i].sn=a[i].s;
		tmp=0,t=0;
		for(int j=0;j<m;j++)
			if(a[i].s[j]!=c[m-j-1])
			{
				tmp=m-j-1,t=j;
				break;
			}
		for(int j=m-1;j>=0;j--)
			if(a[i].s[j]==c[tmp])
			{
				swap(a[i].sx[t],a[i].sx[j]);
				break;
			}
		if(a[i].sx<a[i].s)	a[i].sx=a[i].s;
	}
	for(int i=1;i<=n;i++)
	{
		ans[a[i].id]=1;
		for(int j=1;j<=n;j++)
		{
			if(i==j)	continue;
			if(a[j].sx<=a[i].sn)
			{
				ans[a[i].id]=0;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)	cout<<ans[i];
	return 0;
}
