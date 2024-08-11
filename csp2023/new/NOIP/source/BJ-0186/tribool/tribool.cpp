#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int c, t;

int n, m;

struct operations
{
	string op;
	int i, j;
}ar[1000010];

int var[20], ans1;
int tmp[20];

bool check()
{
	for (int i=1;i<=n;i++)
		tmp[i]=var[i];
	for (int i=1;i<=m;i++)
	{
		if (ar[i].op=="T")
			tmp[ar[i].i]=1;
		if (ar[i].op=="F")
			tmp[ar[i].i]=-1;
		if (ar[i].op=="U")
			tmp[ar[i].i]=0;
		if (ar[i].op=="+")
			tmp[ar[i].i]=tmp[ar[i].j];
		if (ar[i].op=="-")
			tmp[ar[i].i]=-tmp[ar[i].j];
	}
	for (int i=1;i<=n;i++)
		if (var[i]!=tmp[i])
			return 0;
	return 1;
}

void dfs(int u)
{
	if (u>n)
	{
		if (check())
		{
			int cnt=0;
			for (int i=1;i<=n;i++)
				if (var[i]==0)
					cnt++;
			//for (int i=1;i<=n;i++)
			//	printf("%d ", var[i]);
			//printf("cnt:%d\n", cnt);
			ans1=min(ans1, cnt);
		}
		return;
	}
	for (int i=-1;i<=1;i++)
	{
		var[u]=i;
		dfs(u+1);
	}
}

void solve1()
{
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		cin>>ar[i].op>>ar[i].i;
		if (ar[i].op=="+" || ar[i].op=="-")
			cin>>ar[i].j;
	}
	ans1=0x3f3f3f3f;
	dfs(1);
	cout<<ans1<<endl;
}

char a[100010];

void solve2()
{
	memset(a, 0, sizeof(a));
	cin>>n>>m;
	for (int i=1;i<=m;i++)
		cin>>ar[i].op>>ar[i].i;
	for (int i=1;i<=m;i++)
		a[ar[i].i]=ar[i].op[0];
	int ans2=0;
	for (int i=1;i<=n;i++)
		if (a[i]=='U')
			ans2++;
	cout<<ans2<<endl;
}

void solve3()
{
	memset(a, 0x3f, sizeof(a));
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		cin>>ar[i].op>>ar[i].i;
		if (ar[i].op=="+" || ar[i].op=="-")
			cin>>ar[i].j;
	}
	for (int i=1;i<=m;i++)
	{
		if (ar[i].op=="U")
			a[ar[i].i]=0;
		else if (ar[i].op=="+")
			a[ar[i].i]=a[ar[i].j];
	}
	int ans3=0;
	for (int i=1;i<=n;i++)
		if (a[i]==0)
			ans3++;
	cout<<ans3<<endl;
}

int main()
{
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	cin>>c>>t;
	while (t--)
	{
		if (c==1 || c==2)
			solve1();
		if (c==3 || c==4)
			solve2();
		if (c==5 || c==6)
			solve3();
	}
	return 0;
}