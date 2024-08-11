#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

ifstream cin("uqe.in");
ofstream cout("uqe.out");

void yls(double x)
{
	int s = 1, gcd;
	if (x == int(x))
	{
		cout << int(x) << endl;
		return ;
	}
	while (x != int(x) && s <= 1000000000)
	{
		x *= 10;
		s *= 10;
	}
	if (x != int(x))
	{
		x /= 10000000000;
		x = x * 10 - x;
		s = 9;
	}
	gcd = __gcd(int(x), s);
	x /= gcd;
	s /= gcd;
	if (s < 0)
	{
		s *= -1;
		x *= -1;
	}
	cout << x << '/' << s << endl;
}

int main()
{
	int t, m;
	int a, b, c;
	double d, x;
	cin >> t >> m;
	while (t--)
	{
		cin >> a >> b >> c;
		d = b * b - 4 * a * c;
		if (d < 0)
			cout << "NO" << endl;
		else
		{
			x = max ((1.0 * -1 * b + sqrt(d)) / (1.0 * 2 * a), (1.0 * -1 * b - sqrt(d)) / (1.0 * 2 * a));
			yls(x);
		}
	}
	return 0;
}