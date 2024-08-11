#include <bits/stdc++.h>

using namespace std;

bool b[(int)1e9 + 10];

int main()
{
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	int n, t = 1, c, l = 0;
	bool f = 1;
	cin >> n;
	while(f)
	{
		f = 0;
		c = 2;
		for(int i = 1; i <= n; i++)
		{
			if(b[i] == 0)
			{
				f = 1;
				if(c == 2)
				{
					b[i] = 1;
					c = 0;
				}
				else
				{
					c++;
				}
			}
		}
		if(l == 0 and b[n] == 1)
		{
			l = t;
		}
		t++;
	}
	cout << t - 2 << ' ' << l;
	
	return 0;
}