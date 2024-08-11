#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#define MAXN 3050
using namespace std;
int n,m;
int b[MAXN],s[MAXN];

struct node{
	string s;
	int ord;
}a[MAXN];

struct res{
	int ord,flag;
}ans[MAXN];

bool cmp1(node x,node y)
{
	return x.s<y.s;
}

bool cmp2(res x,res y)
{
	return x.ord<y.ord;
}

int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i].s;
		a[i].ord=i;
	}
	sort(a+1,a+n+1,cmp1);
	for (int i=1;i<=n;i++)
	{
		int tmp=0;
		for (int j=m-1;j>=0;j--) //last biggest
		{
			if (tmp<a[i].s[j])
			{
				tmp=a[i].s[j];
				b[i]=j;
			}
		}
		tmp=10000;
		for (int j=m-1;j>=0;j--) //last smallest
		{
			if (tmp>a[i].s[j])
			{
				tmp=a[i].s[j];
				s[i]=j;
			}
		}
	}
	ans[1].ord=a[1].ord;
	ans[1].flag=1;
	for (int i=2;i<=n;i++)
	{
		ans[i].flag=1;
		ans[i].ord=a[i].ord;
		string st1=a[i].s;
		char c1=st1[0];
		st1[0]=st1[s[i]];
		st1[s[i]]=c1;
		for (int j=i-1;j>=1;j--)
		{
			string st2=a[j].s;
			char c2=st2[0];
			st2[0]=st2[b[j]];
			st2[b[j]]=c2;
			if (st2<=st1)
			{
				ans[i].flag=0;
				break;
			}
		}
	}
	sort(ans+1,ans+n+1,cmp2);
	for (int i=1;i<=n;i++)
	{
		cout<<ans[i].flag;
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
