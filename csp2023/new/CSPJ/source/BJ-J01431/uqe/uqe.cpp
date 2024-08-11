#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int T,M;

int gcd(int x,int y)
{
	if (x==0 || y==0) return max(x,y);
	return gcd(max(x,y)%min(x,y),min(x,y));
}

int work(int t)
{
	int x = 1;
	for (int i=1;i<=20005;i++)
	{
		if (t%(i*i) == 0)
		{
			t /= (i*i);
			x *= i;
		}
	}
	return x;
}

int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin >> T >> M;
	for (int i=1;i<=T;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		if (c == 0)
		{
			if (b==0 || -1.0*b/a <= 0)
			{
				cout << 0 << endl;
			}
			else
			{
				if (b%a == 0)
				{
					cout << -b/a << endl;
				}
				else
				{
					int g = gcd(abs(a),abs(b));
					cout << abs(-b/g) << "/" << abs(a/g) << endl;
				}
			}
		}
		else if (b == 0)
		{
			if (-4*a*c < 0) cout << "NO" << endl;
			else if (-4*a*c == 0) cout << 0 << endl;
			else
			{
				int s = work(-4*a*c);
				if (s%(2*a) == 0)
				{
					if (s == 2*a) cout << "sqrt(" << -4*a*c/s/s << ")" << endl;
					else
					{
						cout << s/2/a << "*" << "sqrt(" << -4*a*c/s/s << ")";
					}
				}
				else if ((2*a)%s == 0)
				{
					if (s == 2*a) cout << "sqrt(" << -4*a*c/s/s << ")" << endl;
					else
					{
						cout << "sqrt(" << -4*a*c/s/s << ")" << "/" << 2*a/s << endl;
					}
				}
				else if (s*s == -4*a*c)
				{
					int g = gcd(s,2*a);
					if (g == 2*a) cout << s/g << endl;
					else if (s == g) cout << "sqrt(" << -4*a*c/s/s << ")" << "/" << 2*a/s << endl;
					else cout << s/g << "/" << 2*a/g << endl;
 				}
				else
				{
					int g = gcd(s,2*a);
					if (g%(2*a) == 0) cout << s/g << "*" << "sqrt(" << -4*a*c/s/s << ")" << endl;
					else if ((2*a)%g == 0) cout << "sqrt(" << -4*a*c/s/s << ")" << "/" << 2*a/g << endl;
					else if (s == g) cout << "sqrt(" << -4*a*c/s/s << ")" << "/" << 2*a/s << endl;
					else
					{
						cout << s/g << "*sqrt(" << -4*a*c/s/s << ")" << "/" << 2*a/g << endl;
					}
				}
			}
		}
		else
		{
			if (b*b-4*a*c >= 0) cout << int((-b+sqrt(b*b-4*a*c))/2/a) << endl;
			else cout << "NO" << endl;
		}
	}
	return 0;
}