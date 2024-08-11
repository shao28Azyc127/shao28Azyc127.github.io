#include <iostream>
using namespace std;
typedef long long ll;
ll n;
ll lk[15][15];
ll a[15], b[15], c[15];
bool func(ll xa, ll xb, ll xc, ll xd, ll xe, ll ya, ll yb, ll yc, ll yd, ll ye)
{
	ll cnt = 0;
	if(xa != ya)
	{
		cnt ++;
	}
	if(xb != yb)
	{
		cnt ++;
	}
	if(xc != yc)
	{
		cnt ++;
	}
	if(xd != yd)
	{
		cnt ++;
	}
	if(xe != ye)
	{
		cnt ++;
	}
	if((cnt > 2) || (cnt < 1))
	{
		return false;
	}
	if(cnt == 1)
	{
		return true;
	}
	cnt = 0;
	if(xa != ya)
	{
		++ cnt;
		a[cnt] = (10 + xa -ya) % 10;
		b[cnt] = (10 + ya -xa) % 10;
		c[cnt] = 1;
	}
	if(xb != yb)
	{
		++ cnt;
		a[cnt] = (10 + xb -yb) % 10;
		b[cnt] = (10 + yb -xb) % 10;
		c[cnt] = 2;
	}
	if(xc != yc)
	{
		++ cnt;
		a[cnt] = (10 + xc -yc) % 10;
		b[cnt] = (10 + yc -xc) % 10;
		c[cnt] = 3;
	}
	if(xd != yd)
	{
		++ cnt;
		a[cnt] = (10 + xd -yd) % 10;
		b[cnt] = (10 + yd -xd) % 10;
		c[cnt] = 4;
	}
	if(xe != ye)
	{
		++ cnt;
		a[cnt] = (10 + xe -ye) % 10;
		b[cnt] = (10 + ye -xe) % 10;
		c[cnt] = 5;
	}
	if(((a[1] == a[2]) || (b[1] == b[2])) && ((c[2] - 1) == c[1]))
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	cin >> n;
	for(ll i = 1; i <= n; i ++)
	{
		cin >> lk[i][1] >> lk[i][2] >> lk[i][3] >> lk[i][4] >> lk[i][5];
	}
	ll ans = 0;
	for(ll i = 0; i <= 99999; i ++)
	{
		ll a, b, c, d, e;
		a = i / 10000;
		b = (i / 1000) % 10;
		c = (i / 100) % 10;
		d = (i / 10) % 10;
		e = i % 10;
		bool flag = true;
		for(ll j = 1; j <= n; j ++)
		{
			if(!func(a, b, c, d, e, lk[j][1], lk[j][2], lk[j][3], lk[j][4], lk[j][5]))
			{
				flag = false;
			}
		}
		if(flag)
		{
			ans ++;
		}
	}
	cout << ans;
	return 0;
}
