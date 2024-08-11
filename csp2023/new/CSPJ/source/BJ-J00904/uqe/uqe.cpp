#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
ll t, m;
ll gcd(ll a, ll b)
{
	if(b == 0)
	{
		return a;
	}
	else
	{
		return gcd(b, a % b);
	}
}
ll chk(ll n)
{
	if(n < 4)
	{
		return 1;
	}
	else
	{
		ll k = 1;
		for(int i = 2; i * i <= n; i ++)
		{
			if(n % (i * i) == 0)
			{
				k = i;
			}
		}
		return k;
	}
}
int main()
{
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	cin >> t >> m;
	while(t --)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		ll k = b * b - 4 * a * c;
		if(k < 0)
		{
			cout << "NO" << endl;
			continue;
		}
		ll f = 2 * a;
		ll g = -b;
		ll p = sqrt(k);
		ll j = p + g;
		ll q = j / f;
		cout << q << endl;
	}
	return 0;
}
