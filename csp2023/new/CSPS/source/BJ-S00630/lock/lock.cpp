#include<iostream>
using namespace std;
inline bool Same(int *a,int *b)
{
	for(int i=1;i<=5;i++)
	{
		if(a[i]!=b[i])
		{
			return 0;
		}
	}
	return 1;
}
inline bool judge(int *a,int *b)
{
	if(Same(a,b))
	{
		return 0;
	}
	for(int i=1;i<=5;i++)
	{
		for(int j=0;j<10;j++)
		{
			int A=a[i];
			a[i]=j;
			if(Same(a,b))
			{
				a[i]=A;
				return 1;
			}
			a[i]=A;
		}
	}
	for(int i=1;i<5;i++)
	{
		for(int j=1;j<10;j++)
		{
			int A=a[i],B=a[i+1];
			a[i]=(a[i]+j)%10;
			a[i+1]=(a[i+1]+j)%10;
			if(Same(a,b))
			{
				a[i]=A,a[i+1]=B;
				return 1;
			}
			a[i]=A,a[i+1]=B;
		}
	}
	return 0;
}
int n,a[10][6],b[6],ans=0;
void dfs(int now)
{
	if(now>5)
	{
		for(int i=1;i<=n;i++)
		{
			if(!judge(b,a[i]))
			{
				return;
			}
		}
		ans++;
		return;
	}
	for(int i=0;i<10;i++)
	{
		b[now]=i;
		dfs(now+1);
	}
}
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=5;j++)
		{
			cin>>a[i][j];
		}
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}