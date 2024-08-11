#include<bits/stdc++.h>

using namespace std;

int read()
{
	int s=0,ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return s;
}

const int N = 2007;

int c, n, m, q;
int x[N], y[N], tx[N], ty[N];
bitset<N> dp[N];

bool solve()
{
	if(tx[1] == ty[1]) return 0;
	int flg = 0;
	if(ty[1] < tx[1])
	{
		flg = 1;
		swap(tx, ty);
		swap(n, m);
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(i == 1 && j == 1) dp[i][j] = 1;
			else dp[i][j] = (tx[i] < ty[j]) && 
			(dp[i][j - 1] || dp[i - 1][j]);
	int res = dp[n][m];
	if(flg) swap(n, m);
	return res;
}

signed main()
{
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	c = read(); n = read(); m = read(); q = read();
	for(int i = 1; i <= n; i++) cin >> x[i];
	for(int i = 1; i <= m; i++) cin >> y[i];
	for(int i = 1; i <= n; i++) tx[i] = x[i];
	for(int i = 1; i <= n; i++) ty[i] = y[i];
	cout << solve();
	while(q--)
	{
		int kx, ky, p, v;
		kx = read(); ky = read();
		for(int i = 1; i <= n; i++) tx[i] = x[i];
		for(int i = 1; i <= m; i++) ty[i] = y[i];
		for(int i = 1; i <= kx; i++){
			p = read(); v = read(); tx[p] = v;
		}
		for(int i = 1; i <= ky; i++){
			p = read(); v = read(); ty[p] = v;
		}	
		cout << solve();
	}	
	cout << endl;
	return 0;
}
