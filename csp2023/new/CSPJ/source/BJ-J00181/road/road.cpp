#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

struct sta
{
	ll l , v;
}a[100010] , b[100010];
bool cmp(sta x , sta y)
{
	return x.v < y.v;
}
bool cnp(sta x , sta y)
{
	return x.l < y.l;
}
bool vis[100010];
ll ceil(ll x , ll y)
{
	if (x % y == 0)return x / y;
	else return x / y + 1;
}
int main()
{
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	ll n , d;
	cin >> n >> d;
	a[1].l = 0;
	for (int i = 2; i <= n; i++)
	{
		ll x;
		cin >> x;
		a[i].l = a[i-1].l + x;
	}
	for (int i = 1; i <= n; i++)cin >> a[i].v;
	ll now = 9e18 , s = a[n].l;
	sort (a + 1 , a + n , cmp);
	for (int i = 1; i < n; i++)
	{
		if (a[i].l < now)
		{
			vis[i] = true;
			now = a[i].l;
		}
	}
	int cnt = 0;
	for (int i = 1; i < n; i++)
		if (vis[i])
		{
			b[++cnt].l = a[i].l;
			b[cnt].v = a[i].v;
		}
	sort(b + 1 , b + cnt + 1 , cnp);
	ll sum = 0;
	ll len = 0;
	b[cnt+1].l = s;
	for (int i = 1; i <= cnt; i++)
	{
		if (i == 1)
		{
			ll k = ceil(b[2].l , d);
			sum += k * b[1].v;
			len += k * d;
		}
		else
		{
			len -= b[i].l - b[i-1].l;
			ll k = ceil(b[i+1].l - b[i].l - len , d);
			sum += k * b[i].v;
			len += k * d;
		}
	}
	cout << sum << endl;
	return 0;
}
