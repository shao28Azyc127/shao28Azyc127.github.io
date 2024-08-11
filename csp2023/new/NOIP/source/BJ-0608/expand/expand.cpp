#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Pair;

vector<int> l, r;

int lmin = 1e9+10, lmini;
int lmax = -1, lmaxi;
int rmin = 1e9+10, rmini;
int rmax = -1, rmaxi;

int c, n, m, q, t;

int main()
{
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	cin >> c >> n >> m >> q;
	if (c == 1)
	{
		int A, B;
		cin >> A >> B;
		for (int i = 0; i <= q; i++)
		{
			cout << 1;
		}
		return 0;
	}
	if (c == 2)
	{
		int A, B, C, D;
		cin >> A >> B >> C >> D;
		if ((A < B && C < D)||(A > B && C > D))
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
		for (int i = 0; i < q; i++)
		{
			int E, F, KX, KY;
			cin >> KX >> KY;
			for (int i = 0; i < KX; i++)
			{
				cin >> E >> F;
				switch(E)
				{
					case 1:
					A = F;
					break;
					case 2:
					B = F;
					break;
				}
			}
			for (int i = 0; i < KY; i++)
			{
				cin >> E >> F;
				switch(E)
				{
					case 1:
					C = F;
					break;
					case 2:
					D = F;
					break;
				}
			}
			if ((A < B && C < D)||(A > B && C > D))
			{
				cout << 1;
			}
			else
			{
				cout << 0;
			}
		}
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		l.push_back(t);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> t;
		r.push_back(t);
	}
	if ((r[m - 1] - l[n - 1]) * (r[0] - l[0]) > 0)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	for (int idx = 0; idx < q; idx++)
	{
		int E, F, KX, KY;
		cin >> KX >> KY;
		for (int i = 0; i < KX; i++)
		{
			cin >> E >> F;
			l[E - 1] = F;
		}
		for (int i = 0; i < KY; i++)
		{
			cin >> E >> F;
			r[E - 1] = F;
		}
		if ((r[m - 1] - l[n - 1]) * (r[0] - l[0]) > 0)
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
