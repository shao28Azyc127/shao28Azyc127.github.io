#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int n;
int a[10][10];
int f[10];
int tmp[10];
int ans;
int diff[10][10];

bool check(int k)
{
	for (int i=1;i<=5;i++)
		tmp[i]=diff[f[i]][a[k][i]];
	vector<int> dif;
	for (int i=1;i<=5;i++)
		if (tmp[i])
			dif.push_back(i);
	//printf("%d ", (int)dif.size());
	if (dif.size()>2 || dif.size()==0)
		return 0;
	if (dif.size()==1)
		return 1;
	else if (dif.size()==2)
	{
		if (tmp[dif[0]]==tmp[dif[1]] && dif[1]-dif[0]==1)
			return 1;
		return 0;
	}
}

void dfs(int u)
{
	if (u>5)
	{
		bool flag=0;
		for (int i=1;i<=n;i++)
			if (!check(i))
				flag=1;
		if (!flag)
		{
			ans++;
		}
		return;
	}
	for (int i=0;i<=9;i++)
	{
		f[u]=i;
		dfs(u+1);
	}
}

int main()
{
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	for (int i=0;i<=9;i++)
	{
		for (int j=0;j<=9;j++)
		{
			diff[i][j]=(j-i+10)%10;
			//printf("%d ", diff[i][j]);
		}
		//puts("");
	}

	scanf("%d", &n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=5;j++)
			scanf("%d", &a[i][j]);
	dfs(1);
	printf("%d\n", ans);
	return 0;
}