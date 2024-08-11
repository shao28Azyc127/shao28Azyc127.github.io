#include <iostream>

using namespace std;

int num[9][6];
int cur[6];
int n, ans = 0;

bool Check(int a, int b, int c, int d)
{
	for (int i = 1; i <= 9; i++)
	{
		a--;
		a = (a + 10) % 10;
		b--;
		b = (b + 10) % 10;
		if (a == c && b == d) return true;
	}
	return false;
}

bool FullCheck()
{
	for (int i = 1; i <= n; i++)
	{
		bool flag = false;
		bool allcurr = true;
		for (int j = 1; j <= 5; j++)
		{
			if (num[i][j] != cur[j])
			{
				allcurr = false;
				break;
			}
		}
		if (allcurr) return false;
		for (int j = 1; j <= 5; j++)
		{
			bool flag1 = true;
			for (int k = 1; k <= 5; k++)
			{
				if (k == j) continue;
				if (cur[k] != num[i][k]) 
				{
					flag1 = false;
					break;
				} 
			}
			if (flag1) 
			{
				flag = true;
				break;
			}
		}
		for (int j = 1; j <= 4; j++)
		{
			bool flag2 = true;
			for (int k = 1; k <= 5; k++)
			{
				if (k == j || k == j + 1) continue;
				if (cur[k] != num[i][k]) 
				{
					flag2 = false;
					break;
				}
			}
			if (flag2)
			{
				flag |= Check(cur[j], cur[j + 1], num[i][j], num[i][j + 1]);
				break;
			}
		}
		if (!flag) return false;
	}
	return true;
}

void DFS(int d)
{
	if (d == 6)
	{
		ans += FullCheck();
		return;
	}
	for (int i = 0; i <= 9; i++)
	{
		cur[d] = i;
		DFS(d + 1);
	}
}

int main()
{
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 5; j++) 
		{
			cin >> num[i][j];
		}
	}
	DFS(1);
	cout << ans << endl;
}