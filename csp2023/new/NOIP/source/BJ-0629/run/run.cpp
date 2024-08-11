#include <bits/stdc++.h>
#define maxm 100005
using namespace std;

int c,t,m;
long long k,d,n;
int x[maxm],y[maxm],v[maxm];
bool cmp[maxm];

long long dfs(long long kk,int i)
{
	if(i > n)
	{
		return 0;
	}
	for(int j = 1;j <= m;j++)
	{
		if(cmp[j])
			continue;
		if(i == x[j] && kk >= y[j])
		{
			//cout << "a " << i << " " << kk << endl;
			cmp[j] = 1;
			if(kk+1 > k)
			{
				return dfs(0,i + 1) + v[i];
			}
			return max(dfs(kk + 1,i + 1) - d + v[i],dfs(0,i + 1) + v[i]);
		}
	}
	//cout << "b " << i << " " << kk << endl;
	if(kk+1 > k)
	{
		return dfs(0,i + 1);
	}
	return max(dfs(kk + 1,i + 1) - d,dfs(0,i + 1));
}

int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin >> c >> t;
	for(int i = 1;i <= t;i++)
	{
		cin >> n >> m >> k >> d;
		for(int j = 1;j <= m;j++)
		{
			cin >> x[j] >> y[j] >> v[j];
		}
		cout << dfs(0,0) + d;
	}
	return 0;
}
// << " " << dfs(kk + 1,i + 1) - d << " " << dfs(0,i + 1)
