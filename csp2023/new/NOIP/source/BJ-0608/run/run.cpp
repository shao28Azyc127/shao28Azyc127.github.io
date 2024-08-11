#include <bits/stdc++.h>
using namespace std;

int x[10000], y[10000], z[10000];

int main()
{
	int c, t;
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	cin >> c >> t;
	while (t--)
	{
		int n, m, k, d, s = 0;
		cin >> n >> m >> k >> d;
		for (int i = 0; i < m; i++)
		{
			cin >> x[i] >> y[i] >> z[i];
			if (x[i] < y[i])
				continue;
			s += z[i] - y[i];
		}
		cout << s << endl;;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
