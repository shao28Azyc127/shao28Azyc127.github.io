#include <bits/stdc++.h>

using namespace std;

int n, t, h2, m;
int a[8][5];
set<int> b[5];

int main()
{
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			cin >> a[i][j];
		}
	}
	if(n == 1)
	{
		cout << 81;
	}
	else
	{
		for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j < n; j++)
			{
				b[i].insert(a[j][i]);
			}
		}
		m = 0;
		h2 = 0;
		for(int i = 0; i < 5; i++)
		{
			if(b[i].size() > 1)
			h2++;
			if(b[i].size() > m)
			m = b[i].size();
		}
		if(h2 > 1)
		{
			cout << 1;
		}
		else
		{
			cout << 10 - m;
		}
	}
	
	return 0;
}