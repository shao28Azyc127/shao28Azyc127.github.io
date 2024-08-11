#include <iostream>
using namespace std;
typedef long long ll;
const ll maxn = 1e5 + 5;
ll n, step;
ll a[maxn], b[maxn], c[maxn], d[maxn], e[maxn];
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> step;
	e[0] = 0;
	for(ll i = 1; i < n; i ++)
	{
		cin >> a[i];
		e[i] = e[i - 1] + a[i];
	}
	cin >> b[1];
	c[1] = b[1];
	for(ll i = 2; i <= n; i ++)
	{
		cin >> b[i];
		c[i] = min(c[i - 1], b[i]);
	}
	ll cnt = 1;
	d[cnt] = 1;
	for(ll i = 2; i <= n; i ++)
	{
		if(c[i] != c[i - 1])
		{
			cnt ++;
			d[cnt] = i;
		}
	}
	ll oil = 0, costs = 0;
	for(ll i = 1; i < cnt; i ++)
	{
		ll p = d[i];
		ll q = d[i + 1];
		ll l = e[p - 1];
		ll r = e[q - 1];
		ll wt = r - l;
		if(oil < wt)
		{
			ll s = wt - oil;
			ll h = s / step;
			if(s % step != 0)
			{
				h ++;
			}
			oil += h * step;
			costs += h * b[p];
		}
		oil -= wt;
	}
	ll p = d[cnt];
	ll q = n;
	ll l = e[p - 1];
	ll r = e[q - 1];
	ll wt = r - l;
	if(oil < wt)
	{
		ll s = wt - oil;
		ll h = s / step;
		if(s % step != 0)
		{
			h ++;
		}
		oil += h * step;
		costs += h * b[p];
	}
	oil -= wt;
	cout << costs;
	return 0;
}
