#include <iostream>
#include <map>
#include <cstdio>
using namespace std;
int f[10];
int a[10][10];
int tmp[10];
int cnt[10];
int n;
int ans=0;
int sums=0;
map<int,int> mp;
/*void inits()
{
	for(int i=1;i<=5;i++)
	{
		sums++;
		tmp[i]=f[i];
	}
	return;
}
void check2()
{
	bool p;
	for(int i=1;i<=n;i++)
	{
		p=1;
		for(int j=1;j<=5;j++)
		{
			sums++;
			if(tmp[j]!=a[i][j])
			{
				p=0;
			}
		}
		if(p)
		{
			cnt[i]=1;
		}
	}
	return;
}
void checks()
{
	for(int i=1;i<=n;i++)
	{
		sums++;
		cnt[i]=0;
	}
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=9;j++)
		{
			sums++;
			inits();
			tmp[i]=(tmp[i]+j)%10;
			check2();
		}
	}
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=9;j++)
		{
			sums++;
			inits();
			tmp[i]=(tmp[i]+j)%10;
			tmp[i+1]=(tmp[i+1]+j)%10;
			check2();
		}
	}
	bool p1=1;
	for(int i=1;i<=n;i++)
	{
		sums++;
		if(cnt[i]<1)
		{
			p1=0;
		}
	}
	if(p1)
	{
		ans++;
	}
	return;
}
void dfs(int d)
{
	if(d==6)
	{
		checks();
		return;
	}
	for(int i=0;i<=9;i++)
	{
		f[d]=i;
		dfs(d+1);
	}
	return;
}*/
void nex()
{
	int t=0;
	t=tmp[1]*10000+tmp[2]*1000+tmp[3]*100+tmp[4]*10+tmp[5];
	mp[t]++;
	if(mp[t]==n)
	{
		//cout << t << endl;
		ans++;
	}
	return;
}
void init2(int x)
{
	for(int i=1;i<=5;i++)
	{
		tmp[i]=a[x][i];
	}
	return;
}
void dff()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=5;j++)
		{
			for(int k=1;k<=9;k++)
			{
				init2(i);
				tmp[j]=(tmp[j]+k)%10;
				nex();
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=4;j++)
		{
			for(int k=1;k<=9;k++)
			{
				init2(i);
				tmp[j]=(tmp[j]+k)%10;
				tmp[j+1]=(tmp[j+1]+k)%10;
				nex();
			}
		}
	}
	return;
}
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=5;j++)
		{
			cin >> a[i][j];
		}
	}
	dff();
	cout << ans;
return 0;
}
