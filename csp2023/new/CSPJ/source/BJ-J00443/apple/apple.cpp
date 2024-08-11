#include <bits/stdc++.h>
using namespace std;
int a[100000005];
int main()
{
	int n;
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	cin >> n;
	a[0] = n;
	for(int i = 1; i <= n; ++i)
		a[i] = 1;
	int x = 0, x0;
	bool flag = true;
	while(a[0] != 0)
	{
		int i;
		for(i = 1; i <= n; ++i)
		{
			if(a[i] == 1)
				break;
		}
		while(i <= n)
		{
			a[i] = 0;
			a[0]--;
			int p = 2;
			while(p >= 0 && i <= n)
			{
				i++;
				if(p == 0 && a[i] == 1)
					break;
				else if(a[i] == 1)
					p--;
			}
		}
		x++;
		if(a[n] == 0 && flag)
		{
			x0 = x;
			flag = false;
		}
	}
	cout << x << " " << x0 << endl;
	return 0;
}