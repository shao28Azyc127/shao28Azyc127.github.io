# include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y)
{
	if (y == 0)
		return x;
	return gcd(y, x % y);
}

struct N
{
	int p, q;
	void yuefen()
	{
		int tmp = gcd(p, q);
		p /= tmp;
		q /= tmp;
	}
	void print()
	{
		if (q == 1) cout << p;
		else
		{
			if (q < 0 || p < 0)
				cout << '-';
			cout << abs(p) << '/' << abs(q);
		}
	}
};

int t, m, a, b, c, der;

bool check1()
{
	if ((int)sqrt(der) * (int)sqrt(der) != der) return 0;
	else if ((int)(-b + sqrt(der)) % (2 * a) != 0) return 0;
	return 1;
}

bool check2(int x)
{
	if ((int)sqrt(x) * (int)sqrt(x) == x) return 1;
	else return 0;
}

int main()
{
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	cin >> t >> m;
	while (t--)
	{
		cin >> a >> b >> c;
		der = b * b - 4 * a * c;
		if (der < 0)
		{
			cout << "NO" << endl;
			continue;
		}
		if (check1())
		{
			cout << max((-b + sqrt(der)) / (2 * a), (-b - sqrt(der)) / (2 * a)) << endl;
		}
		else if (check2(der))
		{
			N ans;
			ans.p = -b + sqrt(der);
			if (a < 0) ans.p -= 2 * sqrt(der);
			ans.q = 2 * a;
			ans.yuefen();
			ans.print();
			cout << endl;
		}
		else
		{
			if (b != 0)
			{
				if (b % (2 * a) == 0)
				{
					cout << -b / (2 * a);
				}
				else
				{
					N q1;
					q1.p = -b;
					q1.q = 2 * a;
					q1.yuefen();
					q1.print();
				}
				cout << "+";
			}
			int r = der, k = 1;
			for (int i = 2; i * i < der; i++)
			{
				while (r % (i * i) == 0)
				{
					r /= i * i;
					k *= i;
				}
			}
			a = abs(a);
			N q2;
			q2.p = k;
			q2.q = 2 * a;
			q2.yuefen();
			if (q2.q == 1 && q2.p == 1)
				cout << "sqrt(" << r << ")" << endl;
			else if (q2.q == 1)
				cout << q2.p << '*' << "sqrt(" << r << ")" << endl;
			else if (q2.p == 1)
				cout << "sqrt(" << r << ")" << "/" << q2.q << endl;
			else
				cout << q2.p << '*' << "sqrt(" << r << ")" << "/" << q2.q << endl;
		}
	}
	return 0;
}
