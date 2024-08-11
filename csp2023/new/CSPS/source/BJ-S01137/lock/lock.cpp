#include<bits/stdc++.h>
#define F
using namespace std;

int n,ans=0;
int pw[12][12][12][12][12];

int main()
{
	#ifdef F
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	#endif
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a,b,c,d,e;
		cin>>a>>b>>c>>d>>e;
		for(int i=0;i<=9;i++)
		{
			if(i==a)
				continue;
			pw[i][b][c][d][e]++;
		}
		for(int i=0;i<=9;i++)
		{
			if(i==b)
				continue;
			pw[a][i][c][d][e]++;
		}
		for(int i=0;i<=9;i++)
		{
			if(i==c)
				continue;
			pw[a][b][i][d][e]++;
		}
		for(int i=0;i<=9;i++)
		{
			if(i==d)
				continue;
			pw[a][b][c][i][e]++;
		}
		for(int i=0;i<=9;i++)
		{
			if(i==e)
				continue;
			pw[a][b][c][d][i]++;
		}
		for(int i=0;i<=9;i++)
		{
			if(i==a)
				continue;
			int j=(i+b-a)%10;
			//cout<<"pair:"<<i<<","<<j<<endl;
			pw[i][j][c][d][e]++;
		}
		for(int i=0;i<=9;i++)
		{
			if(i==b)
				continue;
			int j=(i+c-b)%10;
			//cout<<"pair:"<<i<<","<<j<<endl;
			pw[a][i][j][d][e]++;
		}
		for(int i=0;i<=9;i++)
		{
			if(i==c)
				continue;
			int j=(i+d-c)%10;
			pw[a][b][i][j][e]++;
		}
		for(int i=0;i<=9;i++)
		{
			if(i==d)
				continue;
			int j=(i+e-d)%10;
			pw[a][b][c][i][j]++;
		}
	}
	for(int i=0;i<=9;i++)
	{
		for(int j=0;j<=9;j++)
		{
			for(int k=0;k<=9;k++)
			{
				for(int l=0;l<=9;l++)
				{
					for(int i5=0;i5<=9;i5++)
					{
						if(pw[i][j][k][l][i5]>=n)
							ans++;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}