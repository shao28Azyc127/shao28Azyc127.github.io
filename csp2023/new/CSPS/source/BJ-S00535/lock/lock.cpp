#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
int a[10][10];
int b[10];
void dfs(int x,int now)
{
	if(x==6)
	{
		int f=0;
		for(int i=1;i<=n;i++)
		{
			if(now==b[i]) f=1;
			int fl=0;
			for(int j=1;j<=1e4;j*=10)
			{
				int y=now/j%10;
				for(int k=0;k<=9;k++)
				{
					if(k==y) continue;
					if(now-y*j+k*j==b[i])
					{
						fl=1;
						break;
					}
				}
				if(fl) break;
			}
			for(int j=1;j<=1e3;j*=10)
			{
				int y=now/j%10,z=now/j/10%10;
				for(int k=1;k<=9;k++)
				{
					int ny=(y+k)%10,nz=(z+k)%10;
					if(now-y*j-z*j*10+ny*j+nz*j*10==b[i])
					{
						fl=1;
						break;
					}
				}
				if(fl) break;
			}
			if(!fl)
			{
				f=1;
				break;
			}
		}
		if(!f) ans++;
		return;
	}
	for(int i=0;i<10;i++)
	{
		dfs(x+1,now*10+i);
	}
}
signed main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=5;j++) cin>>a[i][j],b[i]=b[i]*10+a[i][j];
	}
	dfs(1,0);
	cout<<ans<<endl;
}