#include <bits/stdc++.h>

using namespace std;

int n, m, a[3010][26];
string t, mp, mx[3010], mn[3010];
bool f;

void init()
{
	for(int i = 0; i < n; i++)
	{
		cin >> t;
		for(int j = 0; j < m; j++)
		{
			a[i][t[j] - 'a']++;
		}
		mp = "";
		for(int j = 25; j >= 0; j--)
		{
			if(a[i][j] != 0)
			{
				for(int k = 0; k < a[i][j]; k++)
				{
					mp += 'a' + j;
				}
			}
		}
		mx[i] = mp;
		mp = "";
		for(int j = 0; j < 26; j++)
		{
			if(a[i][j] != 0)
			{
				for(int k = 0; k < a[i][j]; k++)
				{
					mp += 'a' + j;
				}
			}
		}
		mn[i] = mp;
	}
	return ;
}

bool c(string a, string b)
{
	for(int i = 0; i < m; i++)
	{
		if(a[i] < b[i])
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin >> n >> m;
	init();
	for(int i = 0; i < n; i++)
	{
		f = 1;
		for(int j = 0; j < n; j++)
		{
			if(j == i)
			{
				continue;
			}
			f = f & c(mn[i], mx[j]);
		}
		cout << f;
	}
}