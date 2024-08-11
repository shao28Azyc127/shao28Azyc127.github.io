#include <iostream>
#include <cmath>
using namespace std;

bool check(double a)
{
	return int(a) == a;
}

int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int t,m;
	cin >> t >> m;
	while (t--)
	{
		int a,b,c;
		cin >> a >> b >> c;
		int tmp = b * b - 4 * a * c;
		if (tmp < 0) cout << "NO" << endl;
		if (tmp >= 0)
		{
			int x,y;
			if (sqrt(tmp) - floor(sqrt(tmp)) == 0)
			{
				cout << (-b + sqrt(tmp)) / 2 / a << endl;
			}
			else if (check(b / -2 / a)) 
			{
				x = b / -2 / a;
				if (check(sqrt(tmp)))
				{
					y = sqrt(tmp);
					if (check(y / -2 / a)) cout << x + y / a / -2 << endl;
					else if (check(y / -2)) cout << x << "+" << y << "/" << a << endl;
					else if (check(y / a)) cout << x << "+" << -y / a << "/" << 2 << endl;
					else cout << x << "+" << -y << "/" << 2 * a << endl;
				}
				else cout << x << "+sqrt(" << tmp << ")/2" << endl;
			}
			else if (check(b / -2)) 
			{
				x = b / -2;
				if (check(sqrt(tmp)))
				{
					y = sqrt(tmp);
					if (check(y / -2 / a)) cout << x << "/" << a << "+" << y / -2 / a << endl;
					else if (check(y / -2)) cout << x << "/" << a << "+" << y / -2 << "/" << a << endl;
					else if (check(y / a)) cout << x << "/" << a << "+" << y / -a << "/" << 2 << endl;
					else cout << x << "/" << a << "+" << -y << "/" << 2 * a << endl;
				}
				else cout << x << "/" << a << "+sqrt(" << tmp << ")/2" << endl;
			}
			else if (check(b / a)) 
			{
				x = b / a;
				if (check(sqrt(tmp)))
				{
					y = sqrt(tmp);
					if (check(y / -2 / a)) cout << -x << "/" << 2 << "+" << y / -2 / a << endl;
					else if (check(y / -2)) cout << -x << "/" << 2 << "+" << y / -2 << "/" << a << endl;
					else if (check(y / a)) cout << -x << "/" << 2 << "+" << y / -a << "/" << 2 << endl;
					else cout << -x << "/" << 2 << "+" << -y << "/" << 2 * a << endl;
				}
				else cout << -x << "/" << 2 << "+sqrt(" << tmp << ")/2" << endl;
			}
			else
			{
				x = b;
				if (check(sqrt(tmp)))
				{
					y = sqrt(tmp);
					if (check(y / -2 / a)) cout << -x << "/" << 2 * a << "+" << y / -2 / a << endl;
					else if (check(y / -2)) cout << -x << "/" << 2 * a << "+" << y / -2 << "/" << a << endl;
					else if (check(y / a)) cout << -x << "/" << 2 * a << "+" << y / -a << "/" << 2 << endl;
					else cout << -x << "/" << 2 * a << "+" << -y << "/" << 2 * a << endl;
				}
				else cout << -x << "/" << 2 * a << "+sqrt(" << tmp << ")/2" << endl;
			}	
		}
	}
	return 0;
}
