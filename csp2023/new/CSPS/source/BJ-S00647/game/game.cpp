#include <iostream>
using namespace std;
typedef long long ll;
ll n;
string s;
bool p[8005][8005], vis[8005][8005];
void dfs(ll l, ll r)
{
	if(r < l)
	{
		return ;
	}
	if(vis[l][r] == true)
	{
		return ;
	}
	ll k = (r - l) + 1;
	if(k == 1)
	{
		vis[l][r] = true;
		p[l][r] = false;
	}
	if(k == 2)
	{
		if(s[l] != s[r])
		{
			vis[l][r] = true;
			p[l][r] = false;
		}
		else
		{
			vis[l][r] = true;
			p[l][r] = true;
		}
	}
	else
	{
		ll qq = 0;
		ll rr = 0;
		ll ss = 0;
		if(s[r - 1] == s[r])
		{
			dfs(l, r - 2);
			qq = p[l][r - 2];
		}
		if(s[l] == s[r])
		{
			dfs(l + 1, r - 1);
			rr = p[l + 1][r - 1];
		}
		if(s[l] == s[l + 1])
		{
			dfs(l + 2, r);
			ss = p[l + 2][r];
		}
		vis[l][r] = true;
		if(qq || rr || ss)
		{
			p[l][r] = true;
			return ;
		}
		for(ll gb = l; gb < r; gb ++)
		{
			ll u, v;
			u = v = false;
			dfs(l, gb);
			if(p[l][gb])
			{
				u = true;
			}
			dfs(gb + 1, r);
			if(p[gb + 1][r])
			{
				v = true;
			}
			if(u && v)
			{
				p[l][r] = true;
				return ;
			}
		}
		p[l][r] = false;
	}
	return ;
}
int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> n;
	cin >> s;
	for(ll i = 0; i < n; i ++)
	{
		for(ll j = 0; j < n; j ++)
		{
			p[i][j] = vis[i][j] = false;
		}
	}
	dfs(0, n - 1);
	ll pans = 0;
	for(ll i = 0; i < n; i ++)
	{
		for(ll j = 0; j < n; j ++)
		{
			if(p[i][j])
			{
				pans ++;
			}
		}
	}
	cout << pans;
	return 0;
}
