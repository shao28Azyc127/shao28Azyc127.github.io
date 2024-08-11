#include <iostream>
#include <algorithm>
#include <cmath>
#define gcd(a,b) __gcd(a, b)
#define lcm(a,b) a * b / gcd(a, b)
using namespace std;

bool check(double u)
{
	int q = 1;
	double p = 1;
	bool flag = false;
	while (true)
	{
		p = u * q;
		if ((int)p != p) 
		{
			q++;
			continue;
		}
		int g = gcd(int(p), q);
		if (g == 1 || g == -1) {
			flag = true;
			break;
		}
		if (g > 1) break;
		q++;
	}
	return flag;
}

bool outu(double u)
{
	int q = 1;
	double p = 1;
	bool flag = false;
	while (true)
	{
		p = u * q;
		if ((int)p != p) 
		{
			q++;
			continue;
		}
		int g = gcd(int(p), q);
		if (g == 1 || g == -1) {
			flag = true;
			break;
		}
		if (g > 1) break;
		q++;
	}
	if (flag) {
		if (q == 1) cout << p << endl;
		else cout << p << "/" << q << endl;
	}
	return flag;
}

bool chai(int n) {
	for (int i = 2; i <= n; i++)
	{
		if (n % i == 0) n /= i;
		if (n % i == 0) return false;
	}
	return true;
}

void uqe()
{
	int a, b, c;
	cin >> a >> b >> c;
	int d = b*b - 4*a*c;
	if (d < 0) {
		cout << "NO" << endl;
	} else {
		double x1 = ((-b)*(+sqrt(d)))/(2*a), 
			x2 = ((-b)*(-sqrt(d)))/(2*a);
		double x = max(x1, x2);
		if (!outu(x))
		{
			double q1, q2 = 1, q3, r = 2;
			while (true)
			{
				q1 = x - q2 * sqrt(r);
				if (!check(q1))
				{
					r++;
					continue;
				}
				if (chai((int)r)) break;
				q2++;
				r++;
			}
			if (q1 != 0) {
				outu(q1);
				cout << "+";
			}
			if (q2 == 1) cout << "sqrt(" << r << ")\n";
			else if ((int)q2 == q2) cout << q2<<"*sqrt("<<r<<")"<<"\n";
			else if ((int)(q3 = 1/q2) == q3) cout << "sqrt("<<r<<")/"<<q3<<"\n";
			else {
				int c = 2, d = 2;
				while (true)
				{
					c = q2 * d;
					if (d < 2) 
					{
						c++;
						continue;
					}
					int g = gcd(c, d);
					if (g == 1) {
						break;
					}
					c++;
				}
				cout << c << "*sqrt("<<r<<")/"<<d<<"\n";
			}
		}
		
		cout << flush;
	}
}

int main()
{
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	int T, M;
	cin >> T >> M;
	for (int i = 1; i <= T; i++)
		uqe();
	return 0;
}
