#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,ans;
int a[10][10];
int f[100005];
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int tmp,t,b,c;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=5;j++)	scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=5;j++)
		{
			tmp=a[i][j];
			for(int k=1;k<=9;k++)
			{
				a[i][j]=(a[i][j]+1)%10;
				t=0;
				for(int x=1;x<=5;x++)
					t=t*10+a[i][x];
				f[t]++;
			}
			a[i][j]=tmp;
		}
		for(int j=1;j<=4;j++)
		{
			b=a[i][j],c=a[i][j+1];
			for(int k=1;k<=9;k++)
			{
				a[i][j]=(a[i][j]+1)%10;
				a[i][j+1]=(a[i][j+1]+1)%10;
				t=0;
				for(int x=1;x<=5;x++)
					t=t*10+a[i][x];
				f[t]++;
			}
			a[i][j]=b,a[i][j+1]=c;
		}
		t=0;
		for(int j=1;j<=5;j++)
		{
			t=t*10+a[i][j];
		}
		f[t]=-1;
	}
	for(int i=0;i<=99999;i++)
	{
		if(f[i]>=n)
		{
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
