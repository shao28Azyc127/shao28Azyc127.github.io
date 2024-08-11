#include<bits/stdc++.h>
using namespace std;
#define int long long

int eul(int Del)
{
	if (Del == 0) return 0;
	int ans = 1;
	for (int i = 1; i * i <= Del; i++)
		if (Del % (i * i) == 0) ans = i;
	return ans;
}

signed main()
{
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	int T, up, a, b, c;
	cin >> T >> up;
	while (T--)
	{
		cin >> a >> b >> c;
		int Del = b * b - 4 * a * c;
		if (a < 0) a = -a, b = -b;
		if (Del < 0) cout << "NO" << endl;
		else
		{
			if (eul(Del) * eul(Del) == Del)
			{
				int p = -b + eul(Del);
				int q = 2 * a;
				int g = __gcd(p, q);
				p /= g, q /= g;
				if (q < 0) q = -q, p = -p;
				if (q == 1) cout << p << endl;
				else cout << p << "/" << q << endl;
			}
			else
			{
				int p1 = -b, p2 = eul(Del);
				int q = 2 * a;
				int r = Del / (eul(Del) * eul(Del));
				if (q < 0) q = -q, p1 = -p1, p2 = -p2;
				if (p2 < 0) p2 = -p2;
				if (p1 != 0) 
				{
					int tq = q;
					int g = __gcd(p1, q);
					p1 /= g, q /= g;
					if (q < 0) q = -q, p1 = -p1;
					if (q == 1) cout << p1 << "+";
					else cout << p1 << "/" << q << "+";
					q = tq;
				}
				if (p2 == q) cout << "sqrt(" << r << ")" << endl;
				else if (p2 % q == 0) cout << p2 / q << "*sqrt(" << r << ")" << endl;
				else if (q % p2 == 0) cout << "sqrt(" << r << ")/" << q / p2 << endl;
				else
				{
					int g = __gcd(p2, q);
					if (q < 0) q = -q, p2 = -p2;
					if (p2 < 0) p2 = -p2;
					p2 /= g, q /= g;
					cout << p2 << "*sqrt(" << r << ")/" << q << endl;
				}
			}
		}
	}
	return 0;
}