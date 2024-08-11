#include <iostream>
#include <cstdio>
using namespace std;

int n , ans;
int k[10];
int a[10][10];
int to(int x , int y)
{
	int res = 0;
	while (x != y)
	{
		res++;
		x = (x+1) % 10;
	}
	return res;
}
bool is(int x)
{
	int cnt = 0;
	for (int i = 1; i <= 5; i++)
		if (k[i] != a[x][i])cnt++;
	if (cnt == 1)return true;
	if (cnt == 2)
	{
		int pos1 = 0 , pos2 = 0;
		for (int i = 1; i <= 5; i++)
			if (k[i] != a[x][i])
			{
				if (pos1)pos2 = i;
				else pos1 = i;
			}
		if (pos2 - pos1 != 1)return false;
		if (to(k[pos1] , a[x][pos1]) == to(k[pos2] , a[x][pos2]))return true;
	}
	return false;
}
void dfs(int step)
{
	if (step > 5)
	{
		bool flag = true;
		for (int i = 1; i <= n; i++)
			if (!is(i))
				flag = false;
		if (flag)ans++;
		return;
	}
	for (int i = 0; i <= 9; i++)
	{
		k[step] = i;
		dfs(step + 1);
	}
}
int main()
{
	freopen("lock.in" , "r" , stdin);
	freopen("lock.out" , "w" , stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 5; j++)
			cin >> a[i][j];
	dfs(1);
	cout << ans << endl;
	return 0;
}
